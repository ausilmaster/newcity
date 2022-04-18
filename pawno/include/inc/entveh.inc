#include <YSI\y_hooks>

stock GetClosestVehicle(playerid, Float:range)
{
    new     Float:p_X;
    new     Float:p_Y;
    new     Float:p_Z;

    new     Float:Distance;
    new     Float:PretendentDistance = range +1;
    new     Pretendent;

    GetPlayerPos(playerid, p_X, p_Y, p_Z);

    for(new vehicleid=1; vehicleid < MAX_VEHICLES; vehicleid++)
    {
        Distance = GetVehicleDistanceFromPoint(vehicleid, p_X, p_Y, p_Z);

        if(Distance <= range && Distance <= PretendentDistance)
        {
            Pretendent = vehicleid;
            PretendentDistance = Distance;
        }
    }

    return Pretendent;
}


CMD:entervehicle(playerid)
{
	new vehicleid;
    vehicleid = GetClosestVehicle(playerid, 5); // This will find the nearest vehicles in radius of 5.
	
	if(vehicleid == 433) || vehicleid == 416) // Ambulance and Army truck.
 	{
 	    GetVehiclePos(vehicleid, x, y, z);
 	    SetPlayerPos(playerid, X, Y, Z);
 	    SetPlayerInterior(playerid, 6); // Change 6 with the interior ID.
 	    SetPlayerVirtualWorld(playerid, 54); // 54 The World ID.
    }
}

CMD:exitvehicle(playerid)
{
    new vehicleid;
    vehicleid = GetClosestVehicle(playerid);
	SetPlayerPos(vehicleid, x, y, z);
    SetPlayerVirtualWorld(playerid, 0);

}
