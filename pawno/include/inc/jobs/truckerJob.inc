#include <YSI\y_hooks>

#define MAX_TRUCKER_TRUCKS 6
#define TRUCKER_TRAILER_ID_NONE -1
#define TRUCKER_JOB_ACTOR 186

enum{
    TRUCKER_ERROR_NONE = 0,
    TRUCKER_ERROR_NTRUCK,
    TRUCKER_ERROR_NTRAILER,    
}

enum e_truckerMission{
    tr_DestinationName[40],
    Float:tr_PosX,
    Float:tr_PosY,
    Float:tr_PosZ,
    tr_reward
}
static TruckerMission[][e_truckerMission]={
    {"Cinema",          2480.4636,-1525.4908,23.7658,   593},
    {"Motel",           2219.2073,-1145.5034,25.5625,   1015},
    {"Complex",         534.0090,-1276.7599,17.0167,    2149},
    {"Beach",           367.1093,-2035.5284,7.4454,     2147},
    {"Warehouse",       2210.1406,-2652.6570,13.3172,   615},
    {"Gas Station",     -1577.0963,-2723.0164,48.3094,  4134},
    {"Working Site",    -2107.0681,209.6532,35.0182,    5172},
    {"Gas Station",     1352.6376,475.3220,19.9511,     2840}
};

static 
    truckerVehicleID[MAX_TRUCKER_TRUCKS] = {INVALID_VEHICLE_ID, ...},
    truckerTrailer[MAX_TRUCKER_TRUCKS] = {INVALID_VEHICLE_ID, ...},
    truckerTimer[MAX_TRUCKER_TRUCKS] = {0, ...},
    truckerDestination[MAX_PLAYERS] = {-1, ...},    
    truckerPlayerError[MAX_PLAYERS],
    truckerPlayerErrorTimer[MAX_PLAYERS],
    truckerErrorSecondCount[MAX_PLAYERS];

getTruckerErrorSeconds(playerid){
    return truckerErrorSecondCount[playerid];
}

setTruckerErrorSeconds(playerid, value){
    truckerErrorSecondCount[playerid] = value;
    return 1;
}

getTruckerError(playerid){
    return truckerPlayerError[playerid];
}

getTruckerTrailerFreeID(){
    for(new i = 0; i < sizeof(truckerTrailer); i++){
        if(truckerTrailer[i] == INVALID_VEHICLE_ID)
            return i;
    }
    return TRUCKER_TRAILER_ID_NONE;
}

isInTruckerVehicle(playerid){
    if(!GetPlayerVehicleID(playerid))
        return INVALID_VEHICLE_ID;
    for(new i = 0; i < MAX_TRUCKER_TRUCKS; i++){
        if(truckerVehicleID[i] != INVALID_VEHICLE_ID && GetPlayerVehicleID(playerid) == truckerVehicleID[i])
            return truckerVehicleID[i];
    }
    return INVALID_VEHICLE_ID;
}

hasTruckerTrailer(playerid){
    new vehID = GetPlayerVehicleID(playerid);
    if(!vehID)
        return 0;
    if(isInTruckerVehicle(playerid) == INVALID_VEHICLE_ID)
        return 0;
    new trailerID = GetVehicleTrailer(vehID);
    for(new i = 0; i < sizeof(truckerTrailer); i++){
        if(truckerTrailer[i] == trailerID)
            return truckerTrailer[i];
    }
    return 0;
}

forward DestroyTrailer(vehicleid, index);
public DestroyTrailer(vehicleid, index){
    DestroyVehicleEx(vehicleid);            
    truckerTrailer[index] = INVALID_VEHICLE_ID;
    truckerTimer[index] = 0;
    return 1;
}

forward GameTextErrorTrucker(playerid);
public GameTextErrorTrucker(playerid){

    if(truckerErrorSecondCount[playerid] < 0){
        truckerPlayerErrorTimer[playerid] = KillTimer(truckerPlayerErrorTimer[playerid]);
        return 1;
    }        

    new str[128];

    switch(truckerPlayerError[playerid]){
        case TRUCKER_ERROR_NTRUCK:{
            format(str, sizeof(str), "Get back in the truck in ~r~%d", truckerErrorSecondCount[playerid]);
        }
        case TRUCKER_ERROR_NTRAILER:{
            format(str, sizeof(str), "Get the trailer back in ~r~%d", truckerErrorSecondCount[playerid]);
        }
    }

    GameTextForPlayer(playerid, str, 1000, 3);

    return 1;
}

forward TruckerSync();
public TruckerSync(){
    
    new trailerID;
    foreach(new playerid: Player){

        if(!PlayerInfo[playerid][pTrucking]){
            if(!truckerErrorSecondCount[playerid])
                truckerErrorSecondCount[playerid] = 0;
            if(!truckerPlayerErrorTimer[playerid]){
                KillTimer(truckerPlayerErrorTimer[playerid]);
                truckerPlayerErrorTimer[playerid] = 0;
            }
            if(truckerPlayerError[playerid] != TRUCKER_ERROR_NONE)
                truckerPlayerError[playerid] = TRUCKER_ERROR_NONE;
            if(truckerDestination[playerid] != -1)
                truckerDestination[playerid] = -1;
            continue;
        }

        trailerID = hasTruckerTrailer(playerid);

        if(PlayerInfo[playerid][pTrucking] == 1){
            if(trailerID && truckerDestination[playerid] != -1){
                PlayerInfo[playerid][pTrucking] = 2;
                PlayerInfo[playerid][pCP] = CHECKPOINT_TRUCKER;
                SendClientMessage(playerid, COLOR_AQUA, "Trailer attached! Now go deliver it to the destination.");
                SetPlayerCheckpoint(playerid, TruckerMission[ truckerDestination[playerid] ][tr_PosX], TruckerMission[ truckerDestination[playerid] ][tr_PosY], TruckerMission[ truckerDestination[playerid] ][tr_PosZ], 5.0);
            }
        }
        else if(PlayerInfo[playerid][pTrucking] == 2){
            if(!trailerID){
                if(truckerPlayerError[playerid] != TRUCKER_ERROR_NTRAILER){
                    truckerPlayerError[playerid] = TRUCKER_ERROR_NTRAILER;
                    truckerErrorSecondCount[playerid] = 300;
                    if(!truckerPlayerErrorTimer[playerid])
                        KillTimer(truckerPlayerErrorTimer[playerid]);
                    truckerPlayerErrorTimer[playerid] = SetTimerEx("GameTextErrorTrucker", 1000, true, "i", playerid);
                }
            }
            else{
                if(truckerPlayerError[playerid] == TRUCKER_ERROR_NTRAILER){
                    truckerPlayerError[playerid] = TRUCKER_ERROR_NONE;
                    if(!truckerPlayerErrorTimer[playerid])
                        KillTimer(truckerPlayerErrorTimer[playerid]);
                    truckerPlayerErrorTimer[playerid] = 0;
                }
            }
        }
    }    
    return 1;
}

hook OnGameModeInit(){

    truckerVehicleID[0] = CreateVehicle(403, 2512.1653, -2117.0974, 13.4788, 0.0000, 27, 78, 3000);
    truckerVehicleID[1] = CreateVehicle(403, 2506.7500, -2116.7947, 13.4788, 0.0000, 41, 42, 3000);
    truckerVehicleID[2] = CreateVehicle(403, 2482.2327, -2116.6165, 13.4788, 0.0000, 48, 72, 3000);
    truckerVehicleID[3] = CreateVehicle(403, 2463.3999, -2116.1843, 13.5200, 0.0000, 46, 89, 3000);
    truckerVehicleID[4] = CreateVehicle(403, 2457.8191, -2115.6475, 13.5200, 0.0000, 78, 27, 3000);
    truckerVehicleID[5] = CreateVehicle(403, 2488.4919, -2116.3032, 13.5200, 0.0000, 24, 78, 3000);

    SetTimer("TruckerSync", 500, true);

    return 1;
}

hook OnVehicleSpawn(vehicleid){
    for(new i = 0; i < MAX_TRUCKER_TRUCKS; i++){
        if(truckerTrailer[i] == vehicleid){
            if(truckerTimer[i])
                KillTimer(truckerTimer[i]);
            SetVehicleVirtualWorld(vehicleid, 255);
            truckerTimer[i] = SetTimerEx("DestroyTrailer", 5000, false, "ii", vehicleid, i);
            return -2;            
        }
    }
    return 1;
}

hook OnPlayerConnect(playerid){
    PlayerInfo[playerid][pTrucking] = 0;
    return 1;
}

hook OnPlayerEnterCheckpoint(playerid){

    if(PlayerInfo[playerid][pCP] == CHECKPOINT_TRUCKER){
        if(PlayerInfo[playerid][pTrucking] == 1){
            TogglePlayerControllable(playerid, false);

            new 
                dialogString[700],
                _zoneName[50],
                Float:_distance;

            for(new i = 0; i < sizeof(TruckerMission); i++){
                Get2DZone(_zoneName, sizeof(_zoneName), TruckerMission[i][tr_PosX], TruckerMission[i][tr_PosY], TruckerMission[i][tr_PosZ]);
                _distance = GetPlayerDistanceFromPoint(playerid, TruckerMission[i][tr_PosX], TruckerMission[i][tr_PosY], TruckerMission[i][tr_PosZ]);
                format(dialogString, sizeof(dialogString), "%s%d. %s %s (%dm)\n", dialogString, i+1, _zoneName, TruckerMission[i][tr_DestinationName], floatround(_distance));
            }
            ShowPlayerDialog(playerid, DIALOG_TRUCKING, DIALOG_STYLE_LIST, "{FFFF00}Trucker{FFFFFF}: Destination Choice", dialogString, "Ok", "Cancel");
        }
        else if(PlayerInfo[playerid][pTrucking] == 2){
            new trailerID = hasTruckerTrailer(playerid);
            if(!trailerID){
                SendClientMessage(playerid, COLOR_GREY, "You were supposed to bring the trailer with you. Not just yourself. You failed!");                
            }
            else{
                new reward;
                reward = TruckerMission[ truckerDestination[playerid] ][tr_reward] + random(TruckerMission[ truckerDestination[playerid] ][tr_reward]);
                SendClientMessageEx(playerid, COLOR_AQUA, "You completed the delievery and have earned %s", FormatNumber(reward));
                GivePlayerCash(playerid, reward);
                SetVehicleToRespawn(trailerID);
            }
            CancelActiveCheckpoint(playerid);
        }
    }
    return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]){
    if(dialogid == DIALOG_TRUCKING){
        if(response){
            new tempTruckID = getTruckerTrailerFreeID();
            if(tempTruckID == TRUCKER_TRAILER_ID_NONE){
                CancelActiveCheckpoint(playerid);
                TogglePlayerControllable(playerid, true);
                return SendClientMessage(playerid, COLOR_GREY, "The goods just ran out of stock. Please come back later.");
            }
            else{
                truckerTrailer[tempTruckID] = AddStaticVehicleEx(591, 2496.1299, -2088.7832, 13.5469, 93.4907, -1, -1, 3000);
                if(truckerTrailer[tempTruckID] == INVALID_VEHICLE_ID){
                    CancelActiveCheckpoint(playerid);
                    TogglePlayerControllable(playerid, true);
                    return SendClientMessage(playerid, COLOR_GREY, "Vehicle pool full. Contact an admin/developer.");
                }
            }
            truckerDestination[playerid] = listitem;
            SendClientMessage(playerid, COLOR_SYNTAX, "Hint: Attach the trailer to the truck.");
        }
        else{
            CancelActiveCheckpoint(playerid);
            SendClientMessage(playerid, COLOR_GREY, "You quit the trucking mission.");
        }
        TogglePlayerControllable(playerid, true);
        return 1;
    }
    return 1;
}

hook OnPlayerStateChange(playerid, newstate, oldstate){
    new vehicleID = GetPlayerVehicleID(playerid);
    for(new i = 0; i < MAX_TRUCKER_TRUCKS; i++){
        if(truckerVehicleID[i] == vehicleID && !PlayerHasJob(playerid, JOB_TRUCKER)){
            RemovePlayerFromVehicle(playerid);
            return SendClientMessage(playerid, COLOR_GREY, "You cannot drive this vehicle as you are not a trucker.");
        }
    }    
    if(PlayerInfo[playerid][pTrucking]){
        if(oldstate == PLAYER_STATE_DRIVER){
            if(truckerPlayerError[playerid] == TRUCKER_ERROR_NONE){
                truckerPlayerError[playerid] = TRUCKER_ERROR_NTRUCK;
                truckerErrorSecondCount[playerid] = 120;
                truckerPlayerErrorTimer[playerid] = SetTimerEx("GameTextErrorTrucker", 1000, true, "i", playerid);
            }
        }
        if(newstate == PLAYER_STATE_DRIVER && isInTruckerVehicle(playerid) != INVALID_VEHICLE_ID){
            if(truckerPlayerError[playerid] == TRUCKER_ERROR_NTRUCK){
                truckerPlayerError[playerid] = TRUCKER_ERROR_NONE;
                KillTimer(truckerPlayerErrorTimer[playerid]);
                truckerPlayerErrorTimer[playerid] = 0;
            }
        }
    }
    return 1;
}

CMD:loadtruck(playerid){

    if(!PlayerHasJob(playerid, JOB_TRUCKER))
        return SendClientMessage(playerid, COLOR_GREY, "You cannot use this command as you are not a trucker.");

    if(PlayerInfo[playerid][pCP] != CHECKPOINT_NONE || PlayerInfo[playerid][pTrucking])
        return SendClientMessage(playerid, COLOR_GREY, "You must cancel your active checkpoint first. /cancelcp to cancel it.");    

    if(isInTruckerVehicle(playerid) == INVALID_VEHICLE_ID)
        return SendClientMessage(playerid, COLOR_GREY, "You must be in one of the trucks at the depot.");

    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
        return SendClientMessage(playerid, COLOR_GREY, "You must be the driver of the vehicle.");

    if(getTruckerTrailerFreeID() == TRUCKER_TRAILER_ID_NONE)
        return SendClientMessage(playerid, COLOR_GREY, "There are no goods to export. Please come back later");    

    SetPlayerCheckpoint(playerid, 2483.6104, -2089.3955, 13.5469, 5.0);
    PlayerInfo[playerid][pCP] = CHECKPOINT_TRUCKER;
    PlayerInfo[playerid][pTrucking] = 1;

    SendClientMessage(playerid, COLOR_AQUA, "You have started the trucking mission. Proceed to the checkpoint to get the trailer!");
    return 1;
}

