public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    if(PlayerInfo[playerid][pKicked]) return 0;

	// This is a fix to a known exploit where inserting '%' in the dialog box would crash the server.
	for(new i = 0, l = strlen(inputtext); i < l; i ++)
	{
	    if(inputtext[i] == '%') inputtext[i] = '#';
	}

	switch(dialogid)
	{
		case DIALOG_RACKWEAPONS:
		{
			if (response)
			{
			    new id = Rack_Nearest(playerid);

			    if (id == -1)
			        return 0;

			    if (!RackData[id][rackWeapons][listitem])
			    {
					if (!GetScriptWeapon(playerid))
					    return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban nen luu tru vu khi de giu no.");

					RackData[id][rackWeapons][listitem] = GetScriptWeapon(playerid);
					//RackData[id][rackAmmo][listitem] = GetPlayerAmmo(playerid);

					RemovePlayerWeapon(playerid, GetScriptWeapon(playerid));

					Rack_RefreshGuns(id);
					Rack_Save(id);

					ApplyAnimationEx(playerid, "WEAPONS", "SHP_Ar_Lift", 4.1, 1, 0, 0, 0, 0);
					SendProximityMessage(playerid, 30.0, COLOR_PURPLE, "** %s da luu tru vu khi.", GetPlayerRPName(playerid), GetWeaponNameEx(RackData[id][rackWeapons][listitem]));
			    }
			    else
			    {
			        GivePlayerWeaponEx(playerid, RackData[id][rackWeapons][listitem]);
			        SendProximityMessage(playerid, 30.0, COLOR_PURPLE, "** %s da lay %s vu khi .", GetPlayerRPName(playerid), GetWeaponNameEx(RackData[id][rackWeapons][listitem]));

		            RackData[id][rackWeapons][listitem] = 0;
					//RackData[id][rackAmmo][listitem] = 0;

					Rack_RefreshGuns(id);
					Rack_Save(id);

					ApplyAnimationEx(playerid, "WEAPONS", "SHP_Tray_Out", 4.1, 1, 0, 0, 0, 0);
			    }
			}
		}
		case DIALOG_GRAFFITICOLOR:
		{
			if (response)
			{
			    new id = Graffiti_Nearest(playerid);

				if (id == -1)
				    return 0;

			    if (IsSprayingInProgress(id))
			    {
			        return SendClientMessage(playerid, COLOR_LIGHTRED, "Da co mot nguoi choi khac phun vao thoi diem nay roi.");
				}

			    switch (listitem)
			    {
			        case 0:
			        {
		    	        PlayerInfo[playerid][pGraffitiColor] = 0xFFFFFFFF;
					}

			        case 1:
			        {
			            PlayerInfo[playerid][pGraffitiColor] = 0xFFFF0000;
					}

			        case 2:
			        {
			            PlayerInfo[playerid][pGraffitiColor] = 0xFFFFFF00;
					}

			        case 3:
			        {
			            PlayerInfo[playerid][pGraffitiColor] = 0xFF33CC33;
					}

			        case 4:
			        {
			            PlayerInfo[playerid][pGraffitiColor] = 0xFF33CCFF;
					}

		    	    case 5:
		    	    {
			            PlayerInfo[playerid][pGraffitiColor] = 0xFFFFA500;
					}

		    	    case 6:
		    	    {
			            PlayerInfo[playerid][pGraffitiColor] = 0xFF1394BF;
					}
					case 7:
					{
						PlayerInfo[playerid][pGraffitiColor] = 0x000000AA;
					}
			    }
			    ShowPlayerDialog(playerid, DIALOG_GRAFFITITEXT, DIALOG_STYLE_INPUT, "Graffiti", "Ban hay dien thong tin len van ban de phun.\n\nNote: Toi da 64 ki tu.", "Dong y", "Huy bo");
			}
		}
		case DIALOG_GRAFFITITEXT:
		{
			if (response)
			{
			    new id = Graffiti_Nearest(playerid);

				if (id == -1)
				    return 0;

			    if (isnull(inputtext))
			    {
			        return ShowPlayerDialog(playerid, DIALOG_GRAFFITITEXT, DIALOG_STYLE_INPUT, "Graffiti", "Ban hay dien thong tin len van ban de phun.\n\nNote: Toi da 64 ki tu.", "Dong y", "Huy bo");
				}
				if (strlen(inputtext) > 64)
				{
				    return ShowPlayerDialog(playerid, DIALOG_GRAFFITITEXT, DIALOG_STYLE_INPUT, "Graffiti", "Loi: Thong tin van ban cua ban qua 64 ki tu.\n\nBan hay dien thong tin len van ban de phun.\n\nNote: Toi da 64 ki tu.", "Dong y", "Huy bo");
				}
		        if (IsSprayingInProgress(id))
		        {
			        return SendClientMessage(playerid, COLOR_LIGHTRED, "Da co mot nguoi choi khac phun vao thoi diem nay roi.");
				}
		        PlayerInfo[playerid][pGraffiti] = id;
		        PlayerInfo[playerid][pGraffitiTime] = 15;

				strpack(PlayerInfo[playerid][pGraffitiText], inputtext, 64 char);
				ApplyAnimationEx(playerid, "GRAFFITI", "spraycan_fire", 4.1, 1, 0, 0, 0, 0);

				//ShowPlayerFooter(playerid, "You are now spraying your ~g~graffiti.");
				GameTextForPlayer(playerid, "~n~~n~~n~~n~~n~~n~~n~~n~~n~~b~Dang trong qua trinh phun...~w~ Doi mot lat!", 15000, 3);

				SendProximityMessage(playerid, 30.0, COLOR_PURPLE, "** %s Lay ra mot binh son phun len tuong.", GetPlayerRPName(playerid));
			}
		}
		case DIALOG_EDITMAINBACKPACK: {
		    new bpstring[350], titlestring[64];
		    if(response) {
		        new index = GetPVarInt(playerid, "BackpackID");
		        switch(listitem) {
					case 0: { // Cash
					    format(titlestring, sizeof(titlestring), "Editting Balo Cash");
					    format(bpstring, sizeof(bpstring),"\
							Input a Digit below to set the Cash of %s ($%s / $%s Cash)",
							GetBackpackSize(index),
							FormatNumber(BackpackInfo[index][bCash]),
						 	FormatNumber(BackpackLimit(BackpackInfo[index][bBackpackSize], LIMIT_CASH))
						);
		                ShowPlayerDialog(playerid, DIALOG_EDITITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Chinh sua", "Quay lai");
		                SetPVarInt(playerid, "Edit_Type", TYPE_CASH);
					}
					case 1: { // Pots
					    format(titlestring, sizeof(titlestring), "Editing the Backpack Pot");
					    format(bpstring, sizeof(bpstring),"\
       						Input a Digit below to set the Pots of %s (%sg / %sg Pots)",
							GetBackpackSize(index),
							FormatNumber(BackpackInfo[index][bPot]),
							FormatNumber(BackpackLimit(BackpackInfo[index][bBackpackSize], LIMIT_POT))
						);
		                ShowPlayerDialog(playerid, DIALOG_EDITITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Chinh sua", "Quay lai");
		                SetPVarInt(playerid, "Edit_Type", TYPE_POT);
					}
					case 2: { // Cracks
					    format(titlestring, sizeof(titlestring), "Editing the Backpack Cracks", index);
					    format(bpstring, sizeof(bpstring), "\
							Input a Digit below to set the Cracks of %s (%sg / %sg Cracks)",
							GetBackpackSize(index),
							FormatNumber(BackpackInfo[index][bCrack]),
							FormatNumber(BackpackLimit(BackpackInfo[index][bBackpackSize], LIMIT_CRACK))
						);
		                ShowPlayerDialog(playerid, DIALOG_EDITITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Chinh sua", "Quay lai");
		                SetPVarInt(playerid, "Edit_Type", TYPE_CRACK);

					}
					case 3: { // Mats
					    format(titlestring, sizeof(titlestring), "Editing the Backpack Mats");
					    format(bpstring, sizeof(bpstring), "\
							Input a Digit below to set the Mats of %s (%s / %spound Mats)",
							GetBackpackSize(index),
							FormatNumber(BackpackInfo[index][bMats]),
							FormatNumber(BackpackLimit(BackpackInfo[index][bBackpackSize], LIMIT_MATS))
						);
		                ShowPlayerDialog(playerid, DIALOG_EDITITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Chinh sua", "Quay lai");
		                SetPVarInt(playerid, "Edit_Type", TYPE_MATS);
					}
					case 4: { // Gun 1 - Small to Large Backpack
	                    format(titlestring, sizeof(titlestring), "Editing the Backpack Gun1");
					    format(bpstring, sizeof(bpstring),"\
							Input a Weapon ID below to set the Weapon of %s (%s)",
							GetBackpackSize(index),
							GetWeaponNameEx(BackpackInfo[index][bGun][0])
						);
		                ShowPlayerDialog(playerid, DIALOG_EDITITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Chinh sua", "Quay lai");
		                SetPVarInt(playerid, "Edit_Type", TYPE_GUN1);
					}
					case 5: { // Gun 2 - Small to Large Backpack
					    format(titlestring, sizeof(titlestring), "Editing the Backpack Gun2");
					    format(bpstring, sizeof(bpstring),"\
							Input a Weapon ID below to set the Weapon of %s (%s)",
							GetBackpackSize(index),
							GetWeaponNameEx(BackpackInfo[index][bGun][1])
						);
		                ShowPlayerDialog(playerid, DIALOG_EDITITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Chinh sua", "Quay lai");
		                SetPVarInt(playerid, "Edit_Type", TYPE_GUN2);
					}
					case 6: { // (Gun 3 Medium to Large)
					    format(titlestring, sizeof(titlestring), "Editing the Backpack Gun3");
					    format(bpstring, sizeof(bpstring),"\
							Input a Weapon ID below to set the Weapon of %s (%s)",
							GetBackpackSize(index),
							GetWeaponNameEx(BackpackInfo[index][bGun][2])
						);
		                ShowPlayerDialog(playerid, DIALOG_EDITITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Chinh sua", "Quay lai");
		                SetPVarInt(playerid, "Edit_Type", TYPE_GUN3);
					}
					case 7: { // (Gun 4 Large Backpack)
						format(titlestring, sizeof(titlestring), "Editing the Backpack Gun4");
					    format(bpstring, sizeof(bpstring),"\
							Input a Weapon ID below to set the Weapon of %s (%s)",
							GetBackpackSize(index),
							GetWeaponNameEx(BackpackInfo[index][bGun][3])
						);
		                ShowPlayerDialog(playerid, DIALOG_EDITITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Chinh sua", "Quay lai");
		                SetPVarInt(playerid, "Edit_Type", TYPE_GUN4);
					}
					case 8: { // (Gun 5 Medium Large Backpack)
				        format(titlestring, sizeof(titlestring), "Editing the Backpack Gun5");
				    	format(bpstring, sizeof(bpstring),"\
							Input a Weapon ID below to set the Weapon of %s (%s)",
							GetBackpackSize(index),
							GetWeaponNameEx(BackpackInfo[index][bGun][4])
						);
		                ShowPlayerDialog(playerid, DIALOG_EDITITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Chinh sua", "Quay lai");
		                SetPVarInt(playerid, "Edit_Type", TYPE_GUN5);
					}
		        }
		    }
		}
		case DIALOG_GETJOB:
		{
			if(response)
			{
				for(new i = 0; i < sizeof(jobLocations); i++)
				{
					if(IsPlayerInRangeOfPoint(playerid, 3.0, jobLocations[i][jobX], jobLocations[i][jobY], jobLocations[i][jobZ]))
	                {
	                	if(PlayerInfo[playerid][pPhone] && PlayerInfo[playerid][pGPS])
	                	{
							mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET job = %i WHERE uid = %i", i, PlayerInfo[playerid][pID]);
							mysql_tquery(connectionID, queryBuffer);

							PlayerInfo[playerid][pJob] = i;
							SendClientMessageEx(playerid, COLOR_WHITE, "Ban da nhan cong viec {FF6347}%s{FFFFFF}. Su dung /jobhelp de xem danh sach lenh cho cong viec moi cua ban.", jobLocations[i][jobName]);
	                	}
					}
				}
			}
		}
		case DIALOG_EDITITEMS:
		{
		    new index = GetPVarInt(playerid, "BackpackID"), string[128];
		    if(response)
			{
			    if(isnull(inputtext)) return ShowEditBackpackDialog(playerid, index),DeletePVar(playerid, "Edit_Type");
				if(!GetPVarType(playerid, "Edit_Type")) return SendClientMessageEx(playerid, COLOR_LIGHTRED, "Da xay ra loi khi trong qua trinh chinh sua");
				new bpstring[230], titlestring[64];
				switch(GetPVarInt(playerid, "Edit_Type"))
				{
		   			case TYPE_CASH: // Editing Backpack Cash
					{
					    if(!IsNumeric(inputtext))
						{
					        format(titlestring, sizeof(titlestring), "Editing the Backpack Cash", index);
						    format(bpstring, sizeof(bpstring)," \
						        WARNING: That's not a number!\n\n\
								Input a Digit below to set the Cash of %s ($%s / $%s Cash)",
								GetBackpackSize(index),
								FormatNumber(BackpackInfo[index][bCash]),
								FormatNumber(BackpackLimit(BackpackInfo[index][bBackpackSize], LIMIT_CASH))
							);
			                ShowPlayerDialog(playerid, DIALOG_EDITITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Chinh sua", "Quay lai");
			                return 1;
					    }
					    new cash = strval(inputtext);
					    if(cash > BackpackLimit(BackpackInfo[index][bBackpackSize], LIMIT_CASH))
						{
		       				format(titlestring, sizeof(titlestring), "Editing the Backpack Cash", index);
						    format(bpstring, sizeof(bpstring)," \
              					WARNING: $%s / $%s Backpack is on Maximum Limit!\n\n\
								Input a Digit below to set the Cash of %s ($%s / $%s Cash)",
								FormatNumber(cash),
								FormatNumber(BackpackLimit(BackpackInfo[index][bBackpackSize], LIMIT_CASH)),
								GetBackpackSize(index),
								FormatNumber(BackpackInfo[index][bCash]),
								FormatNumber(BackpackLimit(BackpackInfo[index][bBackpackSize], LIMIT_CASH))
							);
			                ShowPlayerDialog(playerid, DIALOG_EDITITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Chinh sua", "Quay lai");
			                return 1;
					    }
					    new userid = -1;
						if(BackpackInfo[index][bBackpackOwner] != -1) {
							foreach(new i: Player) {
							    if(backpackid[i] == MAX_BACKPACKS+1) continue;
								if(BackpackInfo[index][bBackpackOwner] == GetPlayerSQLId(i)) {
									userid = i;
									break;
								}
							}
						}
						if(userid != -1) {
							format(string, sizeof(string), "* Admin %s da chinh sua so tien mat cua ban $%s tu %s den $%s tien mat", GetPlayerNameEx(playerid), GetPlayerStorageType(userid), FormatNumber(BackpackInfo[index][bCash]), FormatNumber(cash));
							SendClientMessageEx(userid, COLOR_ROYALBLUE, string);
       						format(bpstring, sizeof(bpstring), "* Ban chinh sua tien mat tu $%s den $%s cua chu so huu: %s %s", FormatNumber(BackpackInfo[index][bCash]), FormatNumber(cash), GetPlayerNameEx(userid) ,GetBackpackSize(index));
			       	 		SendClientMessageEx(playerid, COLOR_WHITE, bpstring);
						}
				        BackpackInfo[index][bCash] = cash;
				        SaveBackpack(index);
				        DeletePVar(playerid, "Edit_Type");
				        return ShowEditBackpackDialog(playerid, index);
					}
					case TYPE_POT: // Editing Backpack Pots
					{
					    if(!IsNumeric(inputtext))
						{
					        format(titlestring, sizeof(titlestring), "Editing the Backpack Pots", index);
						    format(bpstring, sizeof(bpstring)," \
						        WARNING: That's not a number!\n\n\
								Input a Digit below to set the Pots of %s (%sg / %sg Pots)",
								GetBackpackSize(index),
								FormatNumber(BackpackInfo[index][bPot]),
								FormatNumber(BackpackLimit(BackpackInfo[index][bBackpackSize], LIMIT_POT))
							);
			                ShowPlayerDialog(playerid, DIALOG_EDITITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Chinh sua", "Quay lai");
			                return 1;
					    }
					    new pots = strval(inputtext);
					    if(pots > BackpackLimit(BackpackInfo[index][bBackpackSize], LIMIT_POT))
						{
		       				format(titlestring, sizeof(titlestring), "Editing the Backpack Pots", index);
						    format(bpstring, sizeof(bpstring)," \
						        WARNING: %sg / %sg  Backpack is on Maximum Limit!\n\n\
								Input a Digit below to set the Pots of %s (%sg / %sg Pots)",
								FormatNumber(pots),
								FormatNumber(BackpackLimit(BackpackInfo[index][bBackpackSize], LIMIT_POT)),
								GetBackpackSize(index),
								FormatNumber(BackpackInfo[index][bPot]),
								FormatNumber(BackpackLimit(BackpackInfo[index][bBackpackSize], LIMIT_POT))
							);
			                ShowPlayerDialog(playerid, DIALOG_EDITITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Chinh sua", "Quay lai");
			                return 1;
					    }
					    new userid = -1;
						if(BackpackInfo[index][bBackpackOwner] != -1) {
							foreach(new i: Player) {
							    if(backpackid[i] == MAX_BACKPACKS+1) continue;
								if(BackpackInfo[index][bBackpackOwner] == GetPlayerSQLId(i)) {
									userid = i;
									break;
								}
							}
						}
						if(userid != -1) {
							format(string, sizeof(string), "* Admin %s da chinh sua Pots trong nguoi ban %s tu %sg den %sg Pots", GetPlayerNameEx(playerid), GetPlayerStorageType(userid), FormatNumber(BackpackInfo[index][bPot]), FormatNumber(pots));
							SendClientMessageEx(userid, COLOR_ROYALBLUE, string);
							format(bpstring, sizeof(bpstring), "* Ban da chinh sua Pots tu %sg den %sg of Owner: %s %s", FormatNumber(BackpackInfo[index][bPot]), FormatNumber(pots) , GetPlayerNameEx(userid), GetBackpackSize(index));
				        	SendClientMessageEx(playerid, COLOR_WHITE, bpstring);
						}
				        BackpackInfo[index][bPot] = pots;
				        SaveBackpack(index);
				        DeletePVar(playerid, "Edit_Type");
				        return ShowEditBackpackDialog(playerid, index);
					}
					case TYPE_CRACK: // Editing Backpack Cracks
					{
					    if(!IsNumeric(inputtext))
						{
					        format(titlestring, sizeof(titlestring), "Editing the Backpack Cracks", index);
						    format(bpstring, sizeof(bpstring)," \
						        WARNING: That's not a number!\n\n\
								Input a Digit below to set the Cracks of %s (%sg / %sg Cracks)",
								GetBackpackSize(index),
								FormatNumber(BackpackInfo[index][bCrack]),
								FormatNumber(BackpackLimit(BackpackInfo[index][bBackpackSize], LIMIT_CRACK))
							);
			                ShowPlayerDialog(playerid, DIALOG_EDITITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Chinh sua", "Quay lai");
			                return 1;
					    }
					    new cracks = strval(inputtext);
					    if(cracks > BackpackLimit(BackpackInfo[index][bBackpackSize], LIMIT_POT))
						{
		       				format(titlestring, sizeof(titlestring), "Editing the Backpack Cracks", index);
						    format(bpstring, sizeof(bpstring)," \
						         WARNING: %sg / %sg  Backpack is on Maximum Limit!\n\n\
								Input a Digit below to set the Cracks of %s (%sg / %sg Cracks)",
								FormatNumber(cracks),
								FormatNumber(BackpackLimit(BackpackInfo[index][bBackpackSize], LIMIT_CRACK)),
								GetBackpackSize(index),
								FormatNumber(BackpackInfo[index][bCrack]),
								FormatNumber(BackpackLimit(BackpackInfo[index][bBackpackSize], LIMIT_CRACK))
							);
			                ShowPlayerDialog(playerid, DIALOG_EDITITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Chinh sua", "Quay lai");
			                return 1;
					    }
					    new userid = -1;
						if(BackpackInfo[index][bBackpackOwner] != -1) {
							foreach(new i: Player) {
							    if(backpackid[i] == MAX_BACKPACKS+1) continue;
								if(BackpackInfo[index][bBackpackOwner] == GetPlayerSQLId(i)) {
									userid = i;
									break;
								}
							}
						}
						if(userid != -1) {
							format(string, sizeof(string), "* Admin %s da edit Cracks trong nguoi ban %s tu %sgg den %sg Cracks", GetPlayerNameEx(playerid), GetPlayerStorageType(userid), FormatNumber(BackpackInfo[index][bCrack]), FormatNumber(cracks));
							SendClientMessageEx(userid, COLOR_ROYALBLUE, string);
       						format(bpstring, sizeof(bpstring), "* Ban da chinh sua Cracks tu %sg den %sg cua chu so huu: %s %s", FormatNumber(BackpackInfo[index][bCrack]), FormatNumber(cracks) , GetPlayerNameEx(userid), GetBackpackSize(index));
				        	SendClientMessageEx(playerid, COLOR_WHITE, bpstring);
						}
				        BackpackInfo[index][bCrack] = cracks;
				        SaveBackpack(index);
				        DeletePVar(playerid, "Edit_Type");
				        return ShowEditBackpackDialog(playerid, index);
					}
					case TYPE_MATS: // Editing Backpack Mats
					{
					    if(!IsNumeric(inputtext))
						{
					        format(titlestring, sizeof(titlestring), "Editing the Backpack Mats", index);
						    format(bpstring, sizeof(bpstring)," \
						        WARNING: That's not a number!\n\n\
								Input a Digit below to set the Mats of %s (%s / %s Mats)",
								GetBackpackSize(index),
								FormatNumber(BackpackInfo[index][bMats]),
								FormatNumber(BackpackLimit(BackpackInfo[index][bBackpackSize], LIMIT_MATS))
							);
			                ShowPlayerDialog(playerid, DIALOG_EDITITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Chinh sua", "Quay lai");
			                return 1;
					    }
					    new mats = strval(inputtext);
					    if(mats > BackpackLimit(BackpackInfo[index][bBackpackSize], LIMIT_MATS))
						{
		       				format(titlestring, sizeof(titlestring), "Editing the Backpack Mats", index);
						    format(bpstring, sizeof(bpstring)," \
						        WARNING: %sg / %sg  Backpack is on Maximum Limit!\n\n\
								Input a Digit below to set the Mats of %s (%s / %s Mats)",
								FormatNumber(mats),
								FormatNumber(BackpackLimit(BackpackInfo[index][bBackpackSize], LIMIT_MATS)),
								GetBackpackSize(index),
								FormatNumber(BackpackInfo[index][bMats]),
								FormatNumber(BackpackLimit(BackpackInfo[index][bBackpackSize], LIMIT_MATS))
							);
			                ShowPlayerDialog(playerid, DIALOG_EDITITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Chinh sua", "Quay lai");
			                return 1;
					    }
					    new userid = -1;
						if(BackpackInfo[index][bBackpackOwner] != -1) {
							foreach(new i: Player) {
							    if(backpackid[i] == MAX_BACKPACKS+1) continue;
								if(BackpackInfo[index][bBackpackOwner] == GetPlayerSQLId(i)) {
									userid = i;
									break;
								}
							}
						}
						if(userid != -1) {
							format(string, sizeof(string), "* Admin %s da chinh sua Vat lieu trong nguoi ban %s tu %s den %s Mats", GetPlayerNameEx(playerid), GetPlayerStorageType(userid), FormatNumber(BackpackInfo[index][bMats]), FormatNumber(mats));
							SendClientMessageEx(userid, COLOR_ROYALBLUE, string);
							format(bpstring, sizeof(bpstring), "* Ban da chinh sua Mats tu %s den %s cua chu so huu: %s %s", FormatNumber(BackpackInfo[index][bMats]), FormatNumber(mats) , GetPlayerNameEx(userid), GetBackpackSize(index));
				        	SendClientMessageEx(playerid, COLOR_WHITE, bpstring);
						}
				        BackpackInfo[index][bMats] = mats;
				        SaveBackpack(index);
				        DeletePVar(playerid, "Edit_Type");
				        return ShowEditBackpackDialog(playerid, index);
					}
					case TYPE_GUN1: // Editing Backpack Gun1
					{
					    if(!IsNumeric(inputtext))
						{
					        format(titlestring, sizeof(titlestring), "Editing the Backpack Gun1", index);
						    format(bpstring, sizeof(bpstring)," \
						        WARNING: That's not a number!\n\n\
								Input a Weapon ID below to set the Weapon of %s (%s)",
								GetBackpackSize(index),
								GetWeaponNameEx(BackpackInfo[index][bGun][0])
							);
			                ShowPlayerDialog(playerid, DIALOG_EDITITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Chinh sua", "Quay lai");
			                return 1;
					    }
					    new gunid = strval(inputtext);
					    if(!IsRoleplayWeapon(gunid))
						{
			   				format(titlestring, sizeof(titlestring), "Editing the Backpack Gun1", index);
						    format(bpstring, sizeof(bpstring)," \
						        WARNING: %s cannot be insert into the Backpack\n\n\
								Input a Weapon ID below to set the Weapon of %s (%s)",
								GetWeaponNameEx(gunid),
								GetBackpackSize(index),
								GetWeaponNameEx(BackpackInfo[index][bGun][0])
							);
			                ShowPlayerDialog(playerid, DIALOG_EDITITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Chinh sua", "Quay lai");
			                return 1;
					    }
					    new userid = -1;
						if(BackpackInfo[index][bBackpackOwner] != -1) {
							foreach(new i: Player) {
							    if(backpackid[i] == MAX_BACKPACKS+1) continue;
								if(BackpackInfo[index][bBackpackOwner] == GetPlayerSQLId(i)) {
									userid = i;
									break;
								}
							}
						}
						if(userid != -1) {
							format(string, sizeof(string), "* Admin %s da chinh sua Gun1 trong nguoi ban %s tu %s den %s", GetPlayerNameEx(playerid), GetPlayerStorageType(userid), GetWeaponNameEx(BackpackInfo[index][bGun][0]), GetWeaponNameEx(gunid));
							SendClientMessageEx(userid, COLOR_ROYALBLUE, string);
							format(bpstring, sizeof(bpstring), "* Ban da chinh sua Gun1 tu %s den %s cua chu so huu balo: %s  %s", GetWeaponNameEx(BackpackInfo[index][bGun][0]), GetWeaponNameEx(gunid) ,  GetPlayerNameEx(userid), GetBackpackSize(index));
							SendClientMessageEx(playerid, COLOR_WHITE, bpstring);
						}

				        BackpackInfo[index][bGun][0] = gunid;
				        SaveBackpack(index);
				        DeletePVar(playerid, "Edit_Type");
				        return ShowEditBackpackDialog(playerid, index);
					}
					case TYPE_GUN2: // Editing Backpack Gun2
					{
					    if(!IsNumeric(inputtext))
						{
					        format(titlestring, sizeof(titlestring), "Editing the Backpack Gun2", index);
						    format(bpstring, sizeof(bpstring)," \
						        WARNING: That's not a number!\n\n\
								Input a Weapon ID below to set the Weapon of %s (%s)",
								GetBackpackSize(index),
								GetWeaponNameEx(BackpackInfo[index][bGun][1])
							);
			                ShowPlayerDialog(playerid, DIALOG_EDITITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Chinh sua", "Quay lai");
			                return 1;
					    }
					    new gunid = strval(inputtext);
					    if(!IsRoleplayWeapon(gunid))
						{
			   				format(titlestring, sizeof(titlestring), "Editing the Backpack Gun2", index);
						    format(bpstring, sizeof(bpstring)," \
						        WARNING: %s cannot be insert into the Backpack\n\n\
								Input a Weapon ID below to set the Weapon of %s (%s)",
								GetWeaponNameEx(gunid),
								GetBackpackSize(index),
								GetWeaponNameEx(BackpackInfo[index][bGun][1])
							);
			                ShowPlayerDialog(playerid, DIALOG_EDITITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Chinh sua", "Quay lai");
			                return 1;
					    }
					    new userid = -1;
						if(BackpackInfo[index][bBackpackOwner] != -1) {
							foreach(new i: Player) {
							    if(backpackid[i] == MAX_BACKPACKS+1) continue;
								if(BackpackInfo[index][bBackpackOwner] == GetPlayerSQLId(i)) {
									userid = i;
									break;
								}
							}
						}
						if(userid != -1) {
							format(string, sizeof(string), "* Admin %s da chinh sua Gun2 trong nguoi ban %s tu %s den %s", GetPlayerNameEx(playerid), GetPlayerStorageType(userid), GetWeaponNameEx(BackpackInfo[index][bGun][1]), GetWeaponNameEx(gunid));
							SendClientMessageEx(userid, COLOR_ROYALBLUE, string);
							format(bpstring, sizeof(bpstring), "*  Ban da chinh sua Gun2 tu %s den %s cua chu so huu balo: %s  %s", GetWeaponNameEx(BackpackInfo[index][bGun][1]), GetWeaponNameEx(gunid) ,  GetPlayerNameEx(userid), GetBackpackSize(index));
							SendClientMessageEx(playerid, COLOR_WHITE, bpstring);

						}
				        BackpackInfo[index][bGun][1] = gunid;
				        SaveBackpack(index);
				        DeletePVar(playerid, "Edit_Type");
				        return ShowEditBackpackDialog(playerid, index);
					}
					case TYPE_GUN3: // Editing Backpack Gun3
					{
					    if(!IsNumeric(inputtext))
						{
					        format(titlestring, sizeof(titlestring), "Editing the Backpack Gun3", index);
						    format(bpstring, sizeof(bpstring)," \
						        WARNING: That's not a number!\n\n\
								Input a Weapon ID below to set the Weapon of %s (%s)",
								GetBackpackSize(index),
								GetWeaponNameEx(BackpackInfo[index][bGun][2])
							);
			                ShowPlayerDialog(playerid, DIALOG_EDITITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Chinh sua", "Quay lai");
			                return 1;
					    }
					    new gunid = strval(inputtext);
					    if(!IsRoleplayWeapon(gunid))
						{
			   				format(titlestring, sizeof(titlestring), "Editing the Backpack Gun3", index);
						    format(bpstring, sizeof(bpstring)," \
						        WARNING: %s cannot be insert into the Backpack\n\n\
								Input a Weapon ID below to set the Weapon of %s (%s)",
								GetWeaponNameEx(gunid),
								GetBackpackSize(index),
								GetWeaponNameEx(BackpackInfo[index][bGun][2])
							);
			                ShowPlayerDialog(playerid, DIALOG_EDITITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Chinh sua", "Quay lai");
			                return 1;
					    }
					    new userid = -1;
						if(BackpackInfo[index][bBackpackOwner] != -1) {
							foreach(new i: Player) {
							    if(backpackid[i] == MAX_BACKPACKS+1) continue;
								if(BackpackInfo[index][bBackpackOwner] == GetPlayerSQLId(i)) {
									userid = i;
									break;
								}
							}
						}
						if(userid != -1) {
							format(string, sizeof(string), "* Admin %s da chinh sua Gun3 trong nguoi ban %s tu %s den %s", GetPlayerNameEx(playerid), GetPlayerStorageType(userid), GetWeaponNameEx(BackpackInfo[index][bGun][2]), GetWeaponNameEx(gunid));
							SendClientMessageEx(userid, COLOR_ROYALBLUE, string);
							format(bpstring, sizeof(bpstring), "* Ban da chinh sua Gun3 tu %s den %s cua chu so huu balo: %s  %s", GetWeaponNameEx(BackpackInfo[index][bGun][2]), GetWeaponNameEx(gunid) ,  GetPlayerNameEx(userid), GetBackpackSize(index));
							SendClientMessageEx(playerid, COLOR_WHITE, bpstring);
						}
				        BackpackInfo[index][bGun][2] = gunid;
				        SaveBackpack(index);
				        DeletePVar(playerid, "Edit_Type");
				        return ShowEditBackpackDialog(playerid, index);
					}
					case TYPE_GUN4: // Editing Backpack Gun4
					{
					    if(!IsNumeric(inputtext))
						{
					        format(titlestring, sizeof(titlestring), "Editing the Backpack Gun4", index);
						    format(bpstring, sizeof(bpstring)," \
						        WARNING: That's not a number!\n\n\
								Input a Weapon ID below to set the Weapon of %s (%s)",
								GetBackpackSize(index),
								GetWeaponNameEx(BackpackInfo[index][bGun][3])
							);
			                ShowPlayerDialog(playerid, DIALOG_EDITITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Chinh sua", "Quay lai");
			                return 1;
					    }
					    new gunid = strval(inputtext);
					    if(!IsRoleplayWeapon(gunid))
						{
			   				format(titlestring, sizeof(titlestring), "Editing the Backpack Gun4", index);
						    format(bpstring, sizeof(bpstring)," \
						        WARNING: %s cannot be insert into the Backpack\n\n\
								Input a Weapon ID below to set the Weapon of %s (%s)",
								GetWeaponNameEx(gunid),
								GetBackpackSize(index),
								GetWeaponNameEx(BackpackInfo[index][bGun][3])
							);
			                ShowPlayerDialog(playerid, DIALOG_EDITITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Chinh sua", "Quay lai");
			                return 1;
					    }
					    new userid = -1;
						if(BackpackInfo[index][bBackpackOwner] != -1) {
							foreach(new i: Player) {
							    if(backpackid[i] == MAX_BACKPACKS+1) continue;
								if(BackpackInfo[index][bBackpackOwner] == GetPlayerSQLId(i)) {
									userid = i;
									break;
								}
							}
						}
						if(userid != -1) {
							format(string, sizeof(string), "* Admin %s da chinh sua Gun4 trong nguoi ban %s tu %s den %s", GetPlayerNameEx(playerid), GetPlayerStorageType(userid), GetWeaponNameEx(BackpackInfo[index][bGun][3]), GetWeaponNameEx(gunid));
							SendClientMessageEx(userid, COLOR_ROYALBLUE, string);
							format(bpstring, sizeof(bpstring), "* Ban da chinh sua Gun4 tu %s den %s cua chu so huu balo: %s  %s", GetWeaponNameEx(BackpackInfo[index][bGun][3]), GetWeaponNameEx(gunid) ,  GetPlayerNameEx(userid), GetBackpackSize(index));
							SendClientMessageEx(playerid, COLOR_WHITE, bpstring);
						}
				        BackpackInfo[index][bGun][3] = gunid;
				        SaveBackpack(index);
				        DeletePVar(playerid, "Edit_Type");
				        return ShowEditBackpackDialog(playerid, index);
					}
					case TYPE_GUN5: // Editing Backpack Gun5
					{
					    if(!IsNumeric(inputtext))
						{
					        format(titlestring, sizeof(titlestring), "Editing the Backpack Gun5", index);
						    format(bpstring, sizeof(bpstring)," \
						        WARNING: That's not a number!\n\n\
								Input a Weapon ID below to set the Weapon of %s (%s)",
								GetBackpackSize(index),
								GetWeaponNameEx(BackpackInfo[index][bGun][4])
							);
			                ShowPlayerDialog(playerid, DIALOG_EDITITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Chinh sua", "Quay lai");
			                return 1;
					    }
					    new gunid = strval(inputtext);
					    if(!IsRoleplayWeapon(gunid))
						{
			   				format(titlestring, sizeof(titlestring), "Editing the Backpack Gun5", index);
						    format(bpstring, sizeof(bpstring)," \
						        WARNING: %s cannot be insert into the Backpack\n\n\
								Input a Weapon ID below to set the Weapon of %s (%s)",
								GetWeaponNameEx(gunid),
								GetBackpackSize(index),
								GetWeaponNameEx(BackpackInfo[index][bGun][4])
							);
			                ShowPlayerDialog(playerid, DIALOG_EDITITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Chinh sua", "Quay lai");
			                return 1;
					    }
					    new userid = -1;
						if(BackpackInfo[index][bBackpackOwner] != -1) {
							foreach(new i: Player) {
							    if(backpackid[i] == MAX_BACKPACKS+1) continue;
								if(BackpackInfo[index][bBackpackOwner] == GetPlayerSQLId(i)) {
									userid = i;
									break;
								}
							}
						}
						if(userid != -1) {
							format(string, sizeof(string), "* Admin %s da chinh sua Gun5 trong nguoi ban %s tu %s den %s", GetPlayerNameEx(playerid), GetPlayerStorageType(userid), GetWeaponNameEx(BackpackInfo[index][bGun][4]), GetWeaponNameEx(gunid));
							SendClientMessageEx(userid, COLOR_ROYALBLUE, string);
							format(bpstring, sizeof(bpstring), "* Ban da chinh sua Gun5 tu %s den %s cua chu so huu balo: %s  %s", GetWeaponNameEx(BackpackInfo[index][bGun][4]), GetWeaponNameEx(gunid) ,  GetPlayerNameEx(userid), GetBackpackSize(index));
							SendClientMessageEx(playerid, COLOR_WHITE, bpstring);
						}
				        BackpackInfo[index][bGun][4] = gunid;
				        SaveBackpack(index);
				        DeletePVar(playerid, "Edit_Type");
				        return ShowEditBackpackDialog(playerid, index);
					}
				}
		    }
		    else ShowEditBackpackDialog(playerid, index), DeletePVar(playerid, "Edit_Type");
		}
		case DIALOG_BACKPACKMENU:
		{
		    if(response)
			{
			    if(!PlayerHasBackpack(playerid)) return SendClientMessageEx(playerid, COLOR_LIGHTRED, "Ban khong co bat ky balo nao");
				SetPVarInt(playerid, "Listitem_Backpack", listitem);
				ShowBackpackActionChoice(playerid);
			}
			else DeletePVar(playerid, "Listitem_Backpack");
		}
		case DIALOG_PUTAKEITEMS:
		{
		    if(response)
		    {
		        new bpstring[300], titlestring[64], index = GetPlayerBackpackID(playerid), rpstring[128];
		        if(!GetPVarType(playerid, "Type_Action")) return SendClientMessageEx(playerid, COLOR_LIGHTRED, "Da xay ra loi trong qua trinh Hanh Dong Noi chuyen/Dat vat pham");
		        if(isnull(inputtext)) return ShowPlayerBackpack(playerid), DeletePVar(playerid, "Listitem_Backpack"), DeletePVar(playerid, "Type_Action");
		        switch(GetPVarInt(playerid, "Type_Action"))
		        {
		            case 1: // Put Items
		            {
						switch(GetPVarInt(playerid, "Listitem_Backpack"))
						{
						    case 0: // Cash
						    {
						        if(!IsNumeric(inputtext))
								{
							        format(titlestring, sizeof(titlestring), "{FFFFFF}Dat mot it tien trong nguoi ban %s", GetBackpackSize(index));
								    format(bpstring, sizeof(bpstring)," \
										WARNING: That's not a number!\n\n\
										Input the amount of Cash that you will put in your %s ($%s / $%s)",
										GetBackpackSize(index),
										FormatNumber(BackpackInfo[index][bCash]),
										FormatNumber(BackpackLimit(BackpackInfo[index][bBackpackSize], LIMIT_CASH))
									);
				                	ShowPlayerDialog(playerid, DIALOG_PUTAKEITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Dat", "Quay lai");
				                	return 1;
								}
								new cash = strval(inputtext);
								if(cash < 1)
								{
							        format(titlestring, sizeof(titlestring), "{FFFFFF}Dat mot it tien trong nguoi ban %s", GetBackpackSize(index));
								    format(bpstring, sizeof(bpstring)," \
										WARNING: Must not be 0 or a Negative value!\n\n\
										Input the amount of Cash that you will put in your %s ($%s / $%s)",
										FormatNumber(cash),
										GetBackpackSize(index),
										FormatNumber(BackpackInfo[index][bCash]),
										FormatNumber(BackpackLimit(BackpackInfo[index][bBackpackSize], LIMIT_CASH))
									);
				                	ShowPlayerDialog(playerid, DIALOG_PUTAKEITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Dat", "Quay lai");
				                	return 1;
								}
								if(GetPlayerCash(playerid) < cash)
								{
							        format(titlestring, sizeof(titlestring), "{FFFFFF}Dat mot it tien mat trong nguoi ban %s", GetBackpackSize(index));
								    format(bpstring, sizeof(bpstring)," \
										WARNING: You don't have enough $%s Cash to put\n\n\
										Input the amount of Cash that you will put in your %s ($%s / $%s)",
										FormatNumber(cash),
										GetBackpackSize(index),
										FormatNumber(BackpackInfo[index][bCash]),
										FormatNumber(BackpackLimit(BackpackInfo[index][bBackpackSize], LIMIT_CASH))
									);
				                	ShowPlayerDialog(playerid, DIALOG_PUTAKEITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Dat", "Quay lai");
				                	return 1;
								}
								if((BackpackInfo[index][bCash]+cash) > BackpackLimit(BackpackInfo[index][bBackpackSize] , LIMIT_CASH))
								{
							        format(titlestring, sizeof(titlestring), "{FFFFFF}Dat mot it tien trong nguoi ban %s", GetBackpackSize(index));
								    format(bpstring, sizeof(bpstring)," \
										WARNING: $%s cannot be put,Cash in your Backpack is on Maximum Limit ($%s/$%s)\n\n\
										Input the amount of Cash that you will put in your %s ($%s / $%s)",
										FormatNumber(cash),
										FormatNumber(BackpackInfo[index][bCash]),
										FormatNumber(BackpackLimit(BackpackInfo[index][bBackpackSize], LIMIT_CASH)),
										GetBackpackSize(index),
										FormatNumber(BackpackInfo[index][bCash]),
										FormatNumber(BackpackLimit(BackpackInfo[index][bBackpackSize], LIMIT_CASH))
									);
				                	ShowPlayerDialog(playerid, DIALOG_PUTAKEITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Dat", "Quay lai");
				                	return 1;
								}
								format(rpstring, sizeof(rpstring), "Lay ra mot it tien va cho anh ay %s", GetPlayerStorageType(playerid));
								callcmd::me(playerid, rpstring);
								GivePlayerCash(playerid, -cash);
								BackpackInfo[index][bCash] +=cash;
								SavePlayerVariables(playerid);
								return ShowPlayerBackpack(playerid), DeletePVar(playerid, "Listitem_Backpack"), DeletePVar(playerid, "Type_Action");
						    }
						    case 1: // Pots
						    {
						        if(!IsNumeric(inputtext))
								{
							        format(titlestring, sizeof(titlestring), "{FFFFFF}Dat mot it Pots trong nguoi ban %s", GetBackpackSize(index));
								    format(bpstring, sizeof(bpstring)," \
										WARNING: That's not a number!\n\n\
										Input the amount of Pots that you will put in your %s (%sg / %sg)",
										GetBackpackSize(index),
										FormatNumber(BackpackInfo[index][bPot]),
										FormatNumber(BackpackLimit(BackpackInfo[index][bBackpackSize], LIMIT_POT))
									);
				                	ShowPlayerDialog(playerid, DIALOG_PUTAKEITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Dat", "Quay lai");
				                	return 1;
								}
								new pots = strval(inputtext);
								if(pots < 1)
								{
							        format(titlestring, sizeof(titlestring), "{FFFFFF}Dat Pots trong nguoi ban %s", GetBackpackSize(index));
								    format(bpstring, sizeof(bpstring)," \
										WARNING: Must not be 0 or a Negative value!\n\n\
										Input the amount of Pots that you will put in your %s (%sg / %sg)",
										GetBackpackSize(index),
										FormatNumber(BackpackInfo[index][bPot]),
										FormatNumber(BackpackLimit(BackpackInfo[index][bBackpackSize], LIMIT_POT))
									);
				                	ShowPlayerDialog(playerid, DIALOG_PUTAKEITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Dat", "Quay lai");
				                	return 1;
								}
								if(PlayerInfo[playerid][pWeed] < pots)
								{
							        format(titlestring, sizeof(titlestring), "{FFFFFF}Dat mot it Pots trong nguoi ban %s", GetBackpackSize(index));
								    format(bpstring, sizeof(bpstring)," \
										WARNING: You don't have enough %sg Pots to put\n\n\
										Input the amount of Pots that you will put in your %s (%sg / %sg)",
										FormatNumber(pots),
										GetBackpackSize(index),
										FormatNumber(BackpackInfo[index][bPot]),
										FormatNumber(BackpackLimit(BackpackInfo[index][bBackpackSize], LIMIT_POT))
									);
				                	ShowPlayerDialog(playerid, DIALOG_PUTAKEITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Dat", "Quay lai");
				                	return 1;
								}
								if((BackpackInfo[index][bPot]+pots) > BackpackLimit(BackpackInfo[index][bBackpackSize] , LIMIT_POT))
								{
							        format(titlestring, sizeof(titlestring), "{FFFFFF}Dat mot it Pots trong nguoi ban %s", GetBackpackSize(index));
								    format(bpstring, sizeof(bpstring)," \
										WARNING: %sg cannot be put,Pots in your Backpack is on Maximum Limit (%sg/%sg)\n\n\
										Input the amount of Pots that you will put in your %s (%sg / %sg)",
										FormatNumber(pots),
										FormatNumber(BackpackInfo[index][bPot]),
										FormatNumber(BackpackLimit(BackpackInfo[index][bBackpackSize], LIMIT_POT)),
										GetBackpackSize(index),
										FormatNumber(BackpackInfo[index][bPot]),
										FormatNumber(BackpackLimit(BackpackInfo[index][bBackpackSize], LIMIT_POT))
									);
				                	ShowPlayerDialog(playerid, DIALOG_PUTAKEITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Dat", "Quay lai");
				                	return 1;
								}
								format(rpstring, sizeof(rpstring), "Lay ra mot it Pots va cho anh ay %s", GetPlayerStorageType(playerid));
								callcmd::me(playerid, rpstring);
								PlayerInfo[playerid][pWeed] -= pots;
								BackpackInfo[index][bPot] += pots;
								SavePlayerVariables(playerid);
								return ShowPlayerBackpack(playerid), DeletePVar(playerid, "Listitem_Backpack"), DeletePVar(playerid, "Type_Action");

						    }
						    case 2: // Cracks
						    {
						        if(!IsNumeric(inputtext))
								{
							        format(titlestring, sizeof(titlestring), "{FFFFFF}Dat mot it Cracks trong nguoi ban %s", GetBackpackSize(index));
								    format(bpstring, sizeof(bpstring)," \
										WARNING: That's not a number!\n\n\
										Input the amount of Cracks that you will put in your %s (%sg / %sg)",
										GetBackpackSize(index),
										FormatNumber(BackpackInfo[index][bCrack]),
										FormatNumber(BackpackLimit(BackpackInfo[index][bBackpackSize], LIMIT_CRACK))
									);
				                	ShowPlayerDialog(playerid, DIALOG_PUTAKEITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Dat", "Quay lai");
				                	return 1;
								}
								new Cracks = strval(inputtext);
								if(Cracks < 1)
								{
							        format(titlestring, sizeof(titlestring), "{FFFFFF}Dat mot it Cracks trong nguoi ban %s", GetBackpackSize(index));
								    format(bpstring, sizeof(bpstring)," \
										WARNING: Must not be 0 or a Negative value!\n\n\
										Input the amount of Cracks that you will put in your %s (%sg / %sg)",
										GetBackpackSize(index),
										FormatNumber(BackpackInfo[index][bCrack]),
										FormatNumber(BackpackLimit(BackpackInfo[index][bBackpackSize], LIMIT_CRACK))
									);
				                	ShowPlayerDialog(playerid, DIALOG_PUTAKEITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Dat", "Quay lai");
				                	return 1;
								}
								if(PlayerInfo[playerid][pCocaine] < Cracks)
								{
							        format(titlestring, sizeof(titlestring), "{FFFFFF}Dat mot it Cracks trong nguoi ban %s", GetBackpackSize(index));
								    format(bpstring, sizeof(bpstring)," \
										WARNING: You don't have enough %sg Pots to put\n\n\
										Input the amount of Cracks that you will put in your %s (%sg / %sg)",
										FormatNumber(Cracks),
										GetBackpackSize(index),
										FormatNumber(BackpackInfo[index][bCrack]),
										FormatNumber(BackpackLimit(BackpackInfo[index][bBackpackSize], LIMIT_CRACK))
									);
				                	ShowPlayerDialog(playerid, DIALOG_PUTAKEITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Dat", "Quay lai");
				                	return 1;
								}
								if((BackpackInfo[index][bCrack]+Cracks) > BackpackLimit(BackpackInfo[index][bBackpackSize] , LIMIT_CRACK))
								{
							        format(titlestring, sizeof(titlestring), "{FFFFFF}Dat mot it Cracks trong nguoi ban %s", GetBackpackSize(index));
								    format(bpstring, sizeof(bpstring)," \
										WARNING: %sg cannot be put,Cracks in your Backpack is on Maximum Limit (%sg/%sg)\n\n\
										Input the amount of Cracks that you will put in your %s (%sg / %sg)",
										FormatNumber(Cracks),
										FormatNumber(BackpackInfo[index][bCrack]),
										FormatNumber(BackpackLimit(BackpackInfo[index][bBackpackSize], LIMIT_CRACK)),
										GetBackpackSize(index),
										FormatNumber(BackpackInfo[index][bCrack]),
										FormatNumber(BackpackLimit(BackpackInfo[index][bBackpackSize], LIMIT_CRACK))
									);
				                	ShowPlayerDialog(playerid, DIALOG_PUTAKEITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Dat", "Quay lai");
				                	return 1;
								}
								format(rpstring, sizeof(rpstring), "Lay ra mot it Cracks va cho anh ay %s", GetPlayerStorageType(playerid));
								callcmd::me(playerid, rpstring);
								PlayerInfo[playerid][pCocaine] -= Cracks;
								BackpackInfo[index][bCrack] += Cracks;
								SavePlayerVariables(playerid);
								return ShowPlayerBackpack(playerid), DeletePVar(playerid, "Listitem_Backpack"), DeletePVar(playerid, "Type_Action");

						    }
						    case 3: // Mats
						    {
						        if(!IsNumeric(inputtext))
								{
							        format(titlestring, sizeof(titlestring), "{FFFFFF}Dat mot it Mats trong nguoi ban %s", GetBackpackSize(index));
								    format(bpstring, sizeof(bpstring)," \
										WARNING: That's not a number!\n\n\
										Input the amount of Mats that you will put in your %s (%s / %s)",
										GetBackpackSize(index),
										FormatNumber(BackpackInfo[index][bMats]),
										FormatNumber(BackpackLimit(BackpackInfo[index][bBackpackSize], LIMIT_MATS))
									);
				                	ShowPlayerDialog(playerid, DIALOG_PUTAKEITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Dat", "Quay lai");
				                	return 1;
								}
								new Mats = strval(inputtext);
								if(Mats < 1)
								{
							        format(titlestring, sizeof(titlestring), "{FFFFFF}Dat mot it Mats trong nguoi ban %s", GetBackpackSize(index));
								    format(bpstring, sizeof(bpstring)," \
										WARNING: Must not be 0 or a Negative value!\n\n\
										Input the amount of Mats that you will put in your %s (%s / %s)",
										GetBackpackSize(index),
										FormatNumber(BackpackInfo[index][bMats]),
										FormatNumber(BackpackLimit(BackpackInfo[index][bBackpackSize], LIMIT_MATS))
									);
				                	ShowPlayerDialog(playerid, DIALOG_PUTAKEITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Dat", "Quay lai");
				                	return 1;
								}
								if(PlayerInfo[playerid][ pMaterials] < Mats)
								{
							        format(titlestring, sizeof(titlestring), "{FFFFFF}Dat mot it Mats trong nguoi ban %s", GetBackpackSize(index));
								    format(bpstring, sizeof(bpstring)," \
										WARNING: You don't have enough %sg Mats to put\n\n\
										Input the amount of Mats that you will put in your %s (%s / %s)",
										FormatNumber(Mats),
										GetBackpackSize(index),
										FormatNumber(BackpackInfo[index][bMats]),
										FormatNumber(BackpackLimit(BackpackInfo[index][bBackpackSize], LIMIT_MATS))
									);
				                	ShowPlayerDialog(playerid, DIALOG_PUTAKEITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Dat", "Quay lai");
				                	return 1;
								}
								if((BackpackInfo[index][bMats]+Mats) > BackpackLimit(BackpackInfo[index][bBackpackSize] , LIMIT_MATS))
								{
							        format(titlestring, sizeof(titlestring), "{FFFFFF}Dat mot it Mats trong nguoi ban %s", GetBackpackSize(index));
								    format(bpstring, sizeof(bpstring)," \
										WARNING: %sg cannot be put,Mats in your Backpack is on Maximum Limit (%sg/%sg)\n\n\
										Input the amount of Mats that you will put in your %s (%sg / %sg)",
										FormatNumber(Mats),
										FormatNumber(BackpackInfo[index][bMats]),
										FormatNumber(BackpackLimit(BackpackInfo[index][bBackpackSize], LIMIT_MATS)),
										GetBackpackSize(index),
										FormatNumber(BackpackInfo[index][bMats]),
										FormatNumber(BackpackLimit(BackpackInfo[index][bBackpackSize], LIMIT_MATS))
									);
				                	ShowPlayerDialog(playerid, DIALOG_PUTAKEITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Dat", "Quay lai");
				                	return 1;
								}
								format(rpstring, sizeof(rpstring), "Lay ra mot it Mats va cho anh ay %s", GetPlayerStorageType(playerid));
								callcmd::me(playerid, rpstring);
								PlayerInfo[playerid][ pMaterials] -= Mats;
								BackpackInfo[index][bMats] += Mats;
								SavePlayerVariables(playerid);
								return ShowPlayerBackpack(playerid), DeletePVar(playerid, "Listitem_Backpack"), DeletePVar(playerid, "Type_Action");

							}
						}

		            }
		            case 2: // Take Items
		            {
		               	switch(GetPVarInt(playerid, "Listitem_Backpack"))
						{
						    case 0: // Cash
						    {
						        if(!IsNumeric(inputtext))
								{
									format(titlestring, sizeof(titlestring), "{FFFFFF}Dang lay tien trong nguoi ban %s", GetBackpackSize(index));
								    format(bpstring, sizeof(bpstring)," \
								        WARNING: That's not a number!\n\n\
										Input the amount of Cash that you will take from your %s ($%s / $%s)",
										GetBackpackSize(index),
										FormatNumber(BackpackInfo[index][bCash]),
										FormatNumber(BackpackLimit(BackpackInfo[index][bBackpackSize], LIMIT_CASH))
									);
					                ShowPlayerDialog(playerid, DIALOG_PUTAKEITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Lay", "Quay lai");
					                return 1;
								}
								new amount = strval(inputtext);
								if(amount < 1)
								{
								    format(titlestring, sizeof(titlestring), "{FFFFFF}Dang lay tien trong nguoi ban %s", GetBackpackSize(index));
								    format(bpstring, sizeof(bpstring)," \
								        WARNING: Must not be 0 or a Negative value!\n\n\
										Input the amount of Cash that you will take from your %s ($%s / $%s)",
										GetBackpackSize(index),
										FormatNumber(BackpackInfo[index][bCash]),
										FormatNumber(BackpackLimit(BackpackInfo[index][bBackpackSize], LIMIT_CASH))
									);
					                ShowPlayerDialog(playerid, DIALOG_PUTAKEITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Lay", "Quay lai");
					                return 1;

								}
								if(BackpackInfo[index][bCash] < amount)
								{
								    format(titlestring, sizeof(titlestring), "{FFFFFF}Dang lay tien trong nguoi ban %s", GetBackpackSize(index));
								    format(bpstring, sizeof(bpstring)," \
								        WARNING: You don't have enough $%s Cash in your Backpack!\n\n\
										Input the amount of Cash that you will take from your %s ($%s / $%s)",
										FormatNumber(amount),
										GetBackpackSize(index),
										FormatNumber(BackpackInfo[index][bCash]),
										FormatNumber(BackpackLimit(BackpackInfo[index][bBackpackSize], LIMIT_CASH))
									);
					                ShowPlayerDialog(playerid, DIALOG_PUTAKEITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Lay", "Quay lai");
					                return 1;
								}
								format(rpstring, sizeof(rpstring), "Lay ra mot it tien va cho anh ay %s", GetPlayerStorageType(playerid));
								callcmd::me(playerid, rpstring);
								GivePlayerCash(playerid, amount);
								BackpackInfo[index][bCash] -= amount;
								SavePlayerVariables(playerid);
								return ShowPlayerBackpack(playerid), DeletePVar(playerid, "Listitem_Backpack"), DeletePVar(playerid, "Type_Action");

							}
							case 1: // Pots
							{
							    if(!IsNumeric(inputtext))
								{
									format(titlestring, sizeof(titlestring), "{FFFFFF}Dang lay Pots trong nguoi ban %s", GetBackpackSize(index));
								    format(bpstring, sizeof(bpstring)," \
								        WARNING: That's not a number!\n\n\
										Input the amount of Pots that you will take from your %s (%sg / %sg)",
										GetBackpackSize(index),
										FormatNumber(BackpackInfo[index][bPot]),
										FormatNumber(BackpackLimit(BackpackInfo[index][bBackpackSize], LIMIT_POT))
									);
					                ShowPlayerDialog(playerid, DIALOG_PUTAKEITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Lay", "Quay lai");
					                return 1;
								}
								new amount = strval(inputtext);
								if(amount < 1)
								{
								    format(titlestring, sizeof(titlestring), "{FFFFFF}Dang lay Pots trong nguoi ban %s", GetBackpackSize(index));
								    format(bpstring, sizeof(bpstring)," \
								        WARNING: Must not be 0 or a Negative value!\n\n\
										Input the amount of Pots that you will take from your %s (%sg / %sg)",
										GetBackpackSize(index),
										FormatNumber(BackpackInfo[index][bPot]),
										FormatNumber(BackpackLimit(BackpackInfo[index][bBackpackSize], LIMIT_POT))
									);
					                ShowPlayerDialog(playerid, DIALOG_PUTAKEITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Lay", "Quay lai");
					                return 1;

								}
								if(BackpackInfo[index][bPot] < amount)
								{
								    format(titlestring, sizeof(titlestring), "{FFFFFF}Dang lay Pots trong nguoi ban %s", GetBackpackSize(index));
								    format(bpstring, sizeof(bpstring)," \
								        WARNING: You don't have enough %sg Pots in your Backpack!\n\n\
										Input the amount of Pots that you will take from your %s (%sg / %sg)",
										FormatNumber(amount),
										GetBackpackSize(index),
										FormatNumber(BackpackInfo[index][bPot]),
										FormatNumber(BackpackLimit(BackpackInfo[index][bBackpackSize], LIMIT_POT))
									);
					                ShowPlayerDialog(playerid, DIALOG_PUTAKEITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Lay", "Quay lai");
					                return 1;
								}
							    format(rpstring, sizeof(rpstring), "Lay ra mot it Pots va cho anh ay %s", GetPlayerStorageType(playerid));
								callcmd::me(playerid, rpstring);
								PlayerInfo[playerid][pWeed] += amount;
								BackpackInfo[index][bPot] -= amount;
								SavePlayerVariables(playerid);
								return ShowPlayerBackpack(playerid), DeletePVar(playerid, "Listitem_Backpack"), DeletePVar(playerid, "Type_Action");
							}
							case 2: // Cracks
							{
							    if(!IsNumeric(inputtext))
								{
									format(titlestring, sizeof(titlestring), "{FFFFFF}Dang lay Cracks trong nguoi ban %s", GetBackpackSize(index));
								    format(bpstring, sizeof(bpstring)," \
								        WARNING: That's not a number!\n\n\
										Input the amount of Cracks that you will take from your %s (%sg / %sg)",
										GetBackpackSize(index),
										FormatNumber(BackpackInfo[index][bCrack]),
										FormatNumber(BackpackLimit(BackpackInfo[index][bBackpackSize], LIMIT_CRACK))
									);
					                ShowPlayerDialog(playerid, DIALOG_PUTAKEITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Lay", "Quay lai");
					                return 1;
								}
								new amount = strval(inputtext);
								if(amount < 1)
								{
								    format(titlestring, sizeof(titlestring), "{FFFFFF}Dang lay Cracks trong nguoi ban %s", GetBackpackSize(index));
								    format(bpstring, sizeof(bpstring)," \
								        WARNING: Must not be 0 or a Negative value!\n\n\
										Input the amount of Cracks that you will take from your %s (%sg / %sg)",
										GetBackpackSize(index),
										FormatNumber(BackpackInfo[index][bCrack]),
										FormatNumber(BackpackLimit(BackpackInfo[index][bBackpackSize], LIMIT_CRACK))
									);
					                ShowPlayerDialog(playerid, DIALOG_PUTAKEITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Lay", "Quay lai");
					                return 1;

								}
								if(BackpackInfo[index][bCrack] < amount)
								{
								    format(titlestring, sizeof(titlestring), "{FFFFFF}Dang lay Cracks trong nguoi ban %s", GetBackpackSize(index));
								    format(bpstring, sizeof(bpstring)," \
								        WARNING: You don't have enough %sg Pots in your Backpack!\n\n\
										Input the amount of Cracks that you will take from your %s (%sg / %sg)",
										FormatNumber(amount),
										GetBackpackSize(index),
										FormatNumber(BackpackInfo[index][bCrack]),
										FormatNumber(BackpackLimit(BackpackInfo[index][bBackpackSize], LIMIT_CRACK))
									);
					                ShowPlayerDialog(playerid, DIALOG_PUTAKEITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Lay", "Quay lai");
					                return 1;
								}
							    format(rpstring, sizeof(rpstring), "Lay ra mot it Cracks va cho anh ay %s", GetPlayerStorageType(playerid));
								callcmd::me(playerid, rpstring);
								PlayerInfo[playerid][pCocaine] += amount;
								BackpackInfo[index][bCrack] -= amount;
								SavePlayerVariables(playerid);
								return ShowPlayerBackpack(playerid), DeletePVar(playerid, "Listitem_Backpack"), DeletePVar(playerid, "Type_Action");
							}
							case 3: // Mats
							{
							    if(!IsNumeric(inputtext))
								{
									format(titlestring, sizeof(titlestring), "{FFFFFF}Dang lay Mats trong nguoi ban %s", GetBackpackSize(index));
								    format(bpstring, sizeof(bpstring)," \
								        WARNING: That's not a number!\n\n\
										Input the amount of Mats that you will take from your %s (%s / %s)",
										GetBackpackSize(index),
										FormatNumber(BackpackInfo[index][bMats]),
										FormatNumber(BackpackLimit(BackpackInfo[index][bBackpackSize], LIMIT_MATS))
									);
					                ShowPlayerDialog(playerid, DIALOG_PUTAKEITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Lay", "Quay lai");
					                return 1;
								}
								new amount = strval(inputtext);
								if(amount < 1)
								{
								    format(titlestring, sizeof(titlestring), "{FFFFFF}Dang lay Mats trong nguoi ban %s", GetBackpackSize(index));
								    format(bpstring, sizeof(bpstring)," \
								        WARNING: Must not be 0 or a Negative value!\n\n\
										Input the amount of Mats that you will take from your %s (%s / %s)",
										GetBackpackSize(index),
										FormatNumber(BackpackInfo[index][bMats]),
										FormatNumber(BackpackLimit(BackpackInfo[index][bBackpackSize], LIMIT_MATS))
									);
					                ShowPlayerDialog(playerid, DIALOG_PUTAKEITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Lay", "Quay lai");
					                return 1;

								}
								if(BackpackInfo[index][bMats] < amount)
								{
								    format(titlestring, sizeof(titlestring), "{FFFFFF}Dang lay Mats trong nguoi ban %s", GetBackpackSize(index));
								    format(bpstring, sizeof(bpstring)," \
								        WARNING: You don't have enough %sg Pots in your Backpack!\n\n\
										Input the amount of Mats that you will take from your %s (%s / %s)",
										FormatNumber(amount),
										GetBackpackSize(index),
										FormatNumber(BackpackInfo[index][bMats]),
										FormatNumber(BackpackLimit(BackpackInfo[index][bBackpackSize], LIMIT_MATS))
									);
					                ShowPlayerDialog(playerid, DIALOG_PUTAKEITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Lay", "Quay lai");
					                return 1;
								}
							    format(rpstring, sizeof(rpstring), "Lay ra mot it Mats va cho anh ay %s", GetPlayerStorageType(playerid));
								callcmd::me(playerid, rpstring);
								PlayerInfo[playerid][ pMaterials] += amount;
								BackpackInfo[index][bMats] -= amount;
								SavePlayerVariables(playerid);
								return ShowPlayerBackpack(playerid), DeletePVar(playerid, "Listitem_Backpack"), DeletePVar(playerid, "Type_Action");
							}
						}
		            }
		        }
		    }
		    else ShowPlayerBackpack(playerid), DeletePVar(playerid, "Listitem_Backpack"), DeletePVar(playerid, "Type_Action");
		}
		case DIALOG_ACTIONBACKPACKMENU:
		{
			if(response)
			{
			    new bpstring[230], titlestring[64], index = GetPlayerBackpackID(playerid), rpstring[128];
			    switch(listitem)
				{
			    	case 0: { // Put Items into Backpack
						switch(GetPVarInt(playerid, "Listitem_Backpack")) {
						    case 0: {
						        format(titlestring, sizeof(titlestring), "{FFFFFF}Dat tien trong nguoi ban %s", GetBackpackSize(index));
							    format(bpstring, sizeof(bpstring)," \
									Input the amount of Cash that you will put in your %s ($%s / $%s)",
									GetBackpackSize(index),
									FormatNumber(BackpackInfo[index][bCash]),
									FormatNumber(BackpackLimit(BackpackInfo[index][bBackpackSize], LIMIT_CASH))
								);
				                ShowPlayerDialog(playerid, DIALOG_PUTAKEITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Dat", "Quay lai");
				                SetPVarInt(playerid, "Type_Action", 1);
						    }
						    case 1: {
						        format(titlestring, sizeof(titlestring), "{FFFFFF}Dat Pots trong nguoi ban %s", GetBackpackSize(index));
							    format(bpstring, sizeof(bpstring)," \
									Input the amount of Pots that you will put in your %s (%sg / %sg)",
									GetBackpackSize(index),
									FormatNumber(BackpackInfo[index][bPot]),
									FormatNumber(BackpackLimit(BackpackInfo[index][bBackpackSize], LIMIT_POT))
								);
				                ShowPlayerDialog(playerid, DIALOG_PUTAKEITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Dat", "Quay lai");
				                SetPVarInt(playerid, "Type_Action", 1);
						    }
						    case 2: {
						        format(titlestring, sizeof(titlestring), "{FFFFFF}Dat Cracks trong nguoi ban %s", GetBackpackSize(index));
							    format(bpstring, sizeof(bpstring)," \
									Input the amount of Cracks that you will put in your %s (%sg / %sg)",
									GetBackpackSize(index),
									FormatNumber(BackpackInfo[index][bCrack]),
									FormatNumber(BackpackLimit(BackpackInfo[index][bBackpackSize], LIMIT_CRACK))
								);
				                ShowPlayerDialog(playerid, DIALOG_PUTAKEITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Dat", "Quay lai");
				                SetPVarInt(playerid, "Type_Action", 1);
						    }
						    case 3: {
						        format(titlestring, sizeof(titlestring), "{FFFFFF}Dat Mats trong nguoi ban %s", GetBackpackSize(index));
							    format(bpstring, sizeof(bpstring)," \
									Input the amount of Materials that you will put in your %s (%s / %s)",
									GetBackpackSize(index),
									FormatNumber(BackpackInfo[index][bMats]),
									FormatNumber(BackpackLimit(BackpackInfo[index][bBackpackSize], LIMIT_MATS))
								);
				                ShowPlayerDialog(playerid, DIALOG_PUTAKEITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Dat", "Quay lai");
				                SetPVarInt(playerid, "Type_Action", 1);
						    }
						    case 4: {
								new gunid = GetPlayerWeapon(playerid);
								if(!gunid) return SendClientMessageEx(playerid, COLOR_LIGHTRED, "Ban khong co vu khi nao de su dung"), ShowPlayerBackpack(playerid), DeletePVar(playerid, "Listitem_Backpack");
								if(!IsRoleplayWeapon(gunid)) return SendClientMessageEx(playerid, COLOR_LIGHTRED, "Ban khong the xoa vu khi nay khoi balo"), ShowPlayerBackpack(playerid), DeletePVar(playerid, "Listitem_Backpack");
								if(BackpackInfo[index][bGun][0] != 0) return SendClientMessageEx(playerid, COLOR_LIGHTRED, "Da co vu khi trong slot nay!"), ShowPlayerBackpack(playerid), DeletePVar(playerid, "Listitem_Backpack");
								format(rpstring, sizeof(rpstring), "Dat anh ay %s vao cua ho %s", GetWeaponNameEx(gunid),GetPlayerStorageType(playerid));
								callcmd::me(playerid, rpstring);
								BackpackInfo[index][bGun][0] = gunid;
								RemovePlayerWeapon(playerid, gunid);
								SavePlayerVariables(playerid);
								return ShowPlayerBackpack(playerid), DeletePVar(playerid, "Listitem_Backpack");
						    }
							case 5: {
								new gunid = GetPlayerWeapon(playerid);
								if(!gunid) return SendClientMessageEx(playerid, COLOR_LIGHTRED, "Ban khong co vu khi nao de su dung"), ShowPlayerBackpack(playerid), DeletePVar(playerid, "Listitem_Backpack");
								if(!IsRoleplayWeapon(gunid)) return SendClientMessageEx(playerid, COLOR_LIGHTRED, "Ban khong the xoa vu khi nay khoi balo"), ShowPlayerBackpack(playerid), DeletePVar(playerid, "Listitem_Backpack");
								if(BackpackInfo[index][bGun][1] != 0) return SendClientMessageEx(playerid, COLOR_LIGHTRED, "Da co vu khi trong slot nay!"), ShowPlayerBackpack(playerid), DeletePVar(playerid, "Listitem_Backpack");
								format(rpstring, sizeof(rpstring), "Put his %s into their %s", GetWeaponNameEx(gunid),GetPlayerStorageType(playerid));
								callcmd::me(playerid, rpstring);
								BackpackInfo[index][bGun][1] = gunid;
								RemovePlayerWeapon(playerid, gunid);
								SavePlayerVariables(playerid);
								return ShowPlayerBackpack(playerid), DeletePVar(playerid, "Listitem_Backpack");
						    }
						    case 6: {
								new gunid = GetPlayerWeapon(playerid);
								if(!gunid) return SendClientMessageEx(playerid, COLOR_LIGHTRED, "Ban khong co vu khi nao de su dung"), ShowPlayerBackpack(playerid), DeletePVar(playerid, "Listitem_Backpack");
								if(!IsRoleplayWeapon(gunid)) return SendClientMessageEx(playerid, COLOR_LIGHTRED, "ban khong the xoa vu khi nay khoi balo"), ShowPlayerBackpack(playerid), DeletePVar(playerid, "Listitem_Backpack");

								if(BackpackInfo[index][bGun][2] != 0) return SendClientMessageEx(playerid, COLOR_LIGHTRED, "Da co vu khi trong slot nay!"), ShowPlayerBackpack(playerid), DeletePVar(playerid, "Listitem_Backpack");
								format(rpstring, sizeof(rpstring), "Put his %s into their %s", GetWeaponNameEx(gunid),GetPlayerStorageType(playerid));
								callcmd::me(playerid, rpstring);
								BackpackInfo[index][bGun][2] = gunid;
								RemovePlayerWeapon(playerid, gunid);
								SavePlayerVariables(playerid);
								return ShowPlayerBackpack(playerid), DeletePVar(playerid, "Listitem_Backpack");
						    }
						    case 7: {
								new gunid = GetPlayerWeapon(playerid);
								if(!gunid) return SendClientMessageEx(playerid, COLOR_LIGHTRED, "Ban khong co vu khi nao de su dung"), ShowPlayerBackpack(playerid), DeletePVar(playerid, "Listitem_Backpack");
								if(!IsRoleplayWeapon(gunid)) return SendClientMessageEx(playerid, COLOR_LIGHTRED, "Ban khong the xoa vu khi nay khoi balo"), ShowPlayerBackpack(playerid), DeletePVar(playerid, "Listitem_Backpack");

								if(BackpackInfo[index][bGun][3] != 0) return SendClientMessageEx(playerid, COLOR_LIGHTRED, "Da co vu khi trong slot nay!"), ShowPlayerBackpack(playerid), DeletePVar(playerid, "Listitem_Backpack");
								format(rpstring, sizeof(rpstring), "Put his %s into their %s", GetWeaponNameEx(gunid),GetPlayerStorageType(playerid));
								callcmd::me(playerid, rpstring);
								BackpackInfo[index][bGun][3] = gunid;
								RemovePlayerWeapon(playerid, gunid);
								SavePlayerVariables(playerid);
								return ShowPlayerBackpack(playerid), DeletePVar(playerid, "Listitem_Backpack");
						    }
						    case 8: {
								new gunid = GetPlayerWeapon(playerid);
								if(!gunid) return SendClientMessageEx(playerid, COLOR_LIGHTRED, "Ban khong co vu khi nao de su dung"), ShowPlayerBackpack(playerid), DeletePVar(playerid, "Listitem_Backpack");
								if(!IsRoleplayWeapon(gunid)) return SendClientMessageEx(playerid, COLOR_LIGHTRED, "ban khong the xoa vu khi nay khoi balo"), ShowPlayerBackpack(playerid), DeletePVar(playerid, "Listitem_Backpack");

								if(BackpackInfo[index][bGun][4] != 0) return SendClientMessageEx(playerid, COLOR_LIGHTRED, "Da co vu khi trong slot nay!"), ShowPlayerBackpack(playerid), DeletePVar(playerid, "Listitem_Backpack");
								format(rpstring, sizeof(rpstring), "Put his %s into their %s", GetWeaponNameEx(gunid),GetPlayerStorageType(playerid));
								callcmd::me(playerid, rpstring);
								BackpackInfo[index][bGun][4] = gunid;
								RemovePlayerWeapon(playerid, gunid);
								SavePlayerVariables(playerid);
								return ShowPlayerBackpack(playerid), DeletePVar(playerid, "Listitem_Backpack");
						    }
						}
					}
					case 1: { // Take Items from the Backpack
					    switch(GetPVarInt(playerid, "Listitem_Backpack")) {
						    case 0: {
						        format(titlestring, sizeof(titlestring), "{FFFFFF}Dang lay mot it tien trong tui ban %s", GetBackpackSize(index));
							    format(bpstring, sizeof(bpstring)," \
									Input the amount of Cash that you will take from your %s ($%s / $%s)",
									GetBackpackSize(index),
									FormatNumber(BackpackInfo[index][bCash]),
									FormatNumber(BackpackLimit(BackpackInfo[index][bBackpackSize], LIMIT_CASH))
								);
				                ShowPlayerDialog(playerid, DIALOG_PUTAKEITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Lay", "Quay lai");
				                SetPVarInt(playerid, "Type_Action", 2);
						    }
						    case 1: {
						        format(titlestring, sizeof(titlestring), "{FFFFFF}Dang lay mot it Pots trong tui ban %s", GetBackpackSize(index));
							    format(bpstring, sizeof(bpstring)," \
									Input the amount of Pots that you will put from your %s (%sg / %sg)",
									GetBackpackSize(index),
									FormatNumber(BackpackInfo[index][bPot]),
									FormatNumber(BackpackLimit(BackpackInfo[index][bBackpackSize], LIMIT_POT))
								);
				                ShowPlayerDialog(playerid, DIALOG_PUTAKEITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Lay", "Quay lai");
				                SetPVarInt(playerid, "Type_Action", 2);
						    }
						    case 2: {
						        format(titlestring, sizeof(titlestring), "{FFFFFF}Dang lay mot it Cracks trong tui ban %s", GetBackpackSize(index));
							    format(bpstring, sizeof(bpstring)," \
									Input the amount of Cracks that you will put from your %s (%sg / %sg)",
									GetBackpackSize(index),
									FormatNumber(BackpackInfo[index][bCrack]),
									FormatNumber(BackpackLimit(BackpackInfo[index][bBackpackSize], LIMIT_CRACK))
								);
				                ShowPlayerDialog(playerid, DIALOG_PUTAKEITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Lay", "Quay lai");
				                SetPVarInt(playerid, "Type_Action", 2);
						    }
						    case 3: {
						        format(titlestring, sizeof(titlestring), "{FFFFFF}Dang lay mot it mats trong nguoi %s", GetBackpackSize(index));
							    format(bpstring, sizeof(bpstring)," \
									Input the amount of Materials that you will put from your %s (%s / %s)",
									GetBackpackSize(index),
									FormatNumber(BackpackInfo[index][bMats]),
									FormatNumber(BackpackLimit(BackpackInfo[index][bBackpackSize], LIMIT_MATS))
								);
				                ShowPlayerDialog(playerid, DIALOG_PUTAKEITEMS, DIALOG_STYLE_INPUT, titlestring, bpstring, "Lay", "Quay lai");
				                SetPVarInt(playerid, "Type_Action", 2);
						    }
						    case 4: {
						        new gunid = BackpackInfo[index][bGun][0];
						        if(!gunid) return SendClientMessageEx(playerid, COLOR_LIGHTRED, "Ban khong co vu khi nao trong slot id nay!"), ShowPlayerBackpack(playerid), DeletePVar(playerid, "Listitem_Backpack");
						        if(PlayerInfo[playerid][pWeapons][weaponSlotIDs[gunid]] == gunid) return  SendClientMessageEx(playerid, COLOR_LIGHTRED, "You already have this weapon in your hand!"), ShowPlayerBackpack(playerid), DeletePVar(playerid, "Listitem_Backpack");
								format(rpstring, sizeof(rpstring), "Take his %s from their %s", GetWeaponNameEx(gunid),GetPlayerStorageType(playerid));
								callcmd::me(playerid, rpstring);
								GivePlayerWeaponEx(playerid, gunid);
								BackpackInfo[index][bGun][0] = 0;
								SavePlayerVariables(playerid);
							 	ShowPlayerBackpack(playerid);
							  	DeletePVar(playerid, "Listitem_Backpack");
							  	return 1;
						    }
							case 5: {
						        new gunid = BackpackInfo[index][bGun][1];
						        if(!gunid) return SendClientMessageEx(playerid, COLOR_LIGHTRED, "Ban khong co vu khi nao trong slot id nay!"), ShowPlayerBackpack(playerid), DeletePVar(playerid, "Listitem_Backpack");
						        if(PlayerInfo[playerid][pWeapons][weaponSlotIDs[gunid]] == gunid) return  SendClientMessageEx(playerid, COLOR_LIGHTRED, "You already have this weapon in your hand!"), ShowPlayerBackpack(playerid), DeletePVar(playerid, "Listitem_Backpack");
								format(rpstring, sizeof(rpstring), "Take his %s from their %s", GetWeaponNameEx(gunid),GetPlayerStorageType(playerid));
								callcmd::me(playerid, rpstring);
								GivePlayerWeaponEx(playerid, gunid);
								BackpackInfo[index][bGun][1] = 0;
								SavePlayerVariables(playerid);
								return ShowPlayerBackpack(playerid), DeletePVar(playerid, "Listitem_Backpack");
						    }
						    case 6: {
						        new gunid = BackpackInfo[index][bGun][2];
						        if(!gunid) return SendClientMessageEx(playerid, COLOR_LIGHTRED, "Ban khong co vu khi nao trong slot id nay!"), ShowPlayerBackpack(playerid), DeletePVar(playerid, "Listitem_Backpack");
						        if(PlayerInfo[playerid][pWeapons][weaponSlotIDs[gunid]] == gunid) return  SendClientMessageEx(playerid, COLOR_LIGHTRED, "You already have this weapon in your hand!"), ShowPlayerBackpack(playerid), DeletePVar(playerid, "Listitem_Backpack");
								format(rpstring, sizeof(rpstring), "Take his %s from their %s", GetWeaponNameEx(gunid),GetPlayerStorageType(playerid));
								callcmd::me(playerid, rpstring);
								GivePlayerWeaponEx(playerid, gunid);
								BackpackInfo[index][bGun][2] = 0;
								SavePlayerVariables(playerid);
								return ShowPlayerBackpack(playerid), DeletePVar(playerid, "Listitem_Backpack");
						    }
						    case 7: {
						        new gunid = BackpackInfo[index][bGun][3];
						        if(!gunid) return SendClientMessageEx(playerid, COLOR_LIGHTRED, "Ban khong co vu khi nao trong slot id nay!"), ShowPlayerBackpack(playerid), DeletePVar(playerid, "Listitem_Backpack");
						        if(PlayerInfo[playerid][pWeapons][weaponSlotIDs[gunid]] == gunid) return  SendClientMessageEx(playerid, COLOR_LIGHTRED, "You already have this weapon in your hand!"), ShowPlayerBackpack(playerid), DeletePVar(playerid, "Listitem_Backpack");
								format(rpstring, sizeof(rpstring), "Take his %s from their %s", GetWeaponNameEx(gunid),GetPlayerStorageType(playerid));
								callcmd::me(playerid, rpstring);
								GivePlayerWeaponEx(playerid, gunid);
								BackpackInfo[index][bGun][3] = 0;
								SavePlayerVariables(playerid);
								return ShowPlayerBackpack(playerid), DeletePVar(playerid, "Listitem_Backpack");
						    }
						    case 8: {
						        new gunid = BackpackInfo[index][bGun][4];
						        if(!gunid) return SendClientMessageEx(playerid, COLOR_LIGHTRED, "Ban khong co vu khi nao trong slot id nay!"), ShowPlayerBackpack(playerid), DeletePVar(playerid, "Listitem_Backpack");
						        if(PlayerInfo[playerid][pWeapons][weaponSlotIDs[gunid]] == gunid) return  SendClientMessageEx(playerid, COLOR_LIGHTRED, "You already have this weapon in your hand!"), ShowPlayerBackpack(playerid), DeletePVar(playerid, "Listitem_Backpack");
								format(rpstring, sizeof(rpstring), "Take his %s from their %s", GetWeaponNameEx(gunid),GetPlayerStorageType(playerid));
								callcmd::me(playerid, rpstring);
								GivePlayerWeaponEx(playerid, gunid);
								BackpackInfo[index][bGun][4] = 0;
								SavePlayerVariables(playerid);
								return ShowPlayerBackpack(playerid), DeletePVar(playerid, "Listitem_Backpack");
						    }
						}
					}
				}
			}
			else  ShowPlayerBackpack(playerid), DeletePVar(playerid, "Listitem_Backpack");
		}

	    case DIALOG_REGISTER:
    	{
	        if(response)
	        {
	            if(isnull(inputtext))
	            {
	                ShowDialogToPlayer(playerid, DIALOG_REGISTER);
	                return 1;
				}
	            if(strlen(inputtext) < 4)
	            {
	                SendClientMessage(playerid, COLOR_LIGHTRED, "** Mat khau phai toi da 4 ki tu.");
	                ShowDialogToPlayer(playerid, DIALOG_REGISTER);
	                return 1;
	            }

	            WP_Hash(PlayerInfo[playerid][pPassword], 129, inputtext);
	            ShowPlayerDialog(playerid, DIALOG_CONFIRMPASS, DIALOG_STYLE_PASSWORD, "{F53F3F}NewCity Roleplay - Xac nhan mat khau", "{ffffff}Vui long nhap lai mat khau cua ban de xac nhan:", "Dong y", "Huy");
			}
			else
			{
			    KickPlayer(playerid);
			}
		}
		case DIALOG_CONFIRMPASS:
		{
		    if(response)
		    {
		        new
					password[129];

		        if(isnull(inputtext))
		        {
		            return ShowPlayerDialog(playerid, DIALOG_CONFIRMPASS, DIALOG_STYLE_PASSWORD, "{F53F3F}NewCity Roleplay - Xac nhan mat khau", "{FFFFFF}Vui long nhap lai mat khau de xac nhan:", "Dong y", "Huy");
				}

				WP_Hash(password, sizeof(password), inputtext);

				if(!strcmp(PlayerInfo[playerid][pPassword], password))
				{
				    gTotalRegistered++;
				    SaveServerInfo();

		            mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "INSERT INTO users (username, password, lastlogin, ip, passwordchanged) VALUES('%s', '%s', NOW(), '%s', 1)", GetPlayerNameEx(playerid), password, GetPlayerIP(playerid));
		            mysql_tquery(connectionID, queryBuffer, "OnQueryFinished", "ii", THREAD_ACCOUNT_REGISTER, playerid);
				}
				else
				{
				    ShowDialogToPlayer(playerid, DIALOG_REGISTER);
				    SendClientMessage(playerid, COLOR_LIGHTRED, "** Mat khau xac nhan cua ban sai. Vui long thu lai.");
				}
		    }
	        else
	        {
	            ShowDialogToPlayer(playerid, DIALOG_REGISTER);
	        }
	    }
	    case DIALOG_LOGIN:
	    {
	        if(response)
	        {
	            new
	                specifiers[] = "%D of %M, %Y @ %k:%i",
	                password[129];

				if(isnull(inputtext))
				{
				    ShowDialogToPlayer(playerid, DIALOG_LOGIN);
				    return 1;
				}

				WP_Hash(password, sizeof(password), inputtext);

				mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "SELECT *, DATE_FORMAT(lastlogin, '%s') AS login_date FROM users WHERE username = '%s' AND password = '%s'", specifiers, GetPlayerNameEx(playerid), password);
	        	mysql_tquery(connectionID, queryBuffer, "OnQueryFinished", "ii", THREAD_PROCESS_LOGIN, playerid);
	        }
	        else
	        {
				KickPlayer(playerid);
			}
	    }
	    case DIALOG_GENDER:
	    {
	        if(response)
	        {
	            if(listitem == 0)
	            {
	                PlayerInfo[playerid][pGender] = 1;
	                PlayerInfo[playerid][pSkin] = 2;
	                SendClientMessage(playerid, COLOR_YELLOW, "Gioi tinh cua nhan vat ban la Nam. Bay gio ban hay chon do tuoi thich hop.");
				}
				else if(listitem == 1)
				{
	                PlayerInfo[playerid][pGender] = 2;
	                PlayerInfo[playerid][pSkin] = 41;
	                SendClientMessage(playerid, COLOR_YELLOW, "Gioi tinh cua nhan vat ban la Nu. Bay gio ban hay chon do tuoi thich hop.");
				}

		        ShowDialogToPlayer(playerid, DIALOG_AGE);
	        }
	        else
	        {
	            ShowDialogToPlayer(playerid, DIALOG_GENDER);
			}
	    }
	    case DIALOG_AGE:
	    {
	        if(response)
	        {
	            new age = strval(inputtext);

				if(!(10 <= age <= 99))
				{
				    ShowDialogToPlayer(playerid, DIALOG_AGE);
				    SendClientMessage(playerid, COLOR_LIGHTRED, "Do tuoi chi xac dinh tu 10 den 99. Vui long thu lai.");
				    return 1;
	            }

	            PlayerInfo[playerid][pAge] = age;
	            PlayerInfo[playerid][pReferralUID] = 0;
	            //PlayerInfo[playerid][pTutorial] = 1;
	            //PlayerInfo[playerid][pTutorialTimer] = SetTimerEx("TutorialTimer", 3000, false, "ii", playerid, 1);

	            //SendClientMessage(playerid, COLOR_GREEN, "** Good stuff! That's all we need right now. The tutorial will start in a moment.");
	            //SetPlayerToSpawn(playerid);

	            SendClientMessageEx(playerid, COLOR_YELLOW, "Wow! Nhan vat cua ban la %i tuoi. Ban duoc ai gioi thieu den may chu (Khong bat buoc, co the bo qua)?", age);
	            ShowDialogToPlayer(playerid, DIALOG_REFERRAL);
	        }
	        else
	        {
	            ShowDialogToPlayer(playerid, DIALOG_AGE);
			}
	    }
	    case DIALOG_REFERRAL:
	    {
	        if(response)
	        {
	            if(isnull(inputtext) || strlen(inputtext) > 24)
	            {
	                return ShowDialogToPlayer(playerid, DIALOG_REFERRAL);
				}
				if(!strcmp(inputtext, GetPlayerNameEx(playerid)))
				{
				    SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong the dat ten cua minh lam ten gioi thieu.");
				    return ShowDialogToPlayer(playerid, DIALOG_REFERRAL);
				}

				mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "SELECT username, ip, uid FROM users WHERE username = '%e'", inputtext);
				mysql_tquery(connectionID, queryBuffer, "OnQueryFinished", "ii", THREAD_CHECK_REFERRAL, playerid);
	        }
	        else
	        {
				PlayerInfo[playerid][pTutorial] = 1;
				PlayerInfo[playerid][pLogged] = 1;
                PlayerInfo[playerid][pTutorialTimer] = SetTimerEx("TutorialTimer", 1000, false, "ii", playerid, 10);
	            //SendClientMessage(playerid, COLOR_YELLOW, "That's all the information we need right now. The tutorial will start in just a moment.");
			}
	    }
	    case DIALOG_INTERIORS:
	    {
	        if(response)
	        {
	            TeleportToCoords(playerid, interiorArray[listitem][intX], interiorArray[listitem][intY], interiorArray[listitem][intZ], interiorArray[listitem][intA], interiorArray[listitem][intID], GetPlayerVirtualWorld(playerid));
	            GameTextForPlayer(playerid, "~w~Dich chuyen", 5000, 1);
	        }
	    }
	    case DIALOG_BUYFURNITURETYPE:
	    {
	        new houseid = GetInsideHouse(playerid);

		    if(houseid == -1 || !HasFurniturePerms(playerid, houseid))
			{
				return 0;
			}

	   	    if(response)
	        {
				PlayerInfo[playerid][pMenuType] = listitem;
				ShowDialogToPlayer(playerid, DIALOG_BUYFURNITURE1);
			}
	    }
	    case DIALOG_BUYFURNITURE1:
	    {
	        new houseid = GetInsideHouse(playerid);

		    if(houseid == -1 || !HasFurniturePerms(playerid, houseid))
			{
				return 0;
			}

	   	    if(response)
			{
			    switch(PlayerInfo[playerid][pMenuType])
			    {
			        case 0: // Model selection
			        {
						PlayerInfo[playerid][pCategory] = listitem;
						ShowObjectSelectionMenu(playerid, MODEL_SELECTION_FURNITURE);
			        }
			        case 1:
		            {
						PlayerInfo[playerid][pCategory] = listitem;
						ShowDialogToPlayer(playerid, DIALOG_BUYFURNITURE2);
					}
				}
		    }
		    else
		    {
		        ShowDialogToPlayer(playerid, DIALOG_BUYFURNITURETYPE);
			}
	    }
	    case DIALOG_BUYFURNITURE2:
	    {
	        new houseid = GetInsideHouse(playerid);

	        if(houseid == -1 || !HasFurniturePerms(playerid, houseid))
			{
				return 0;
			}

	        if(response)
	        {
	            PurchaseFurniture(playerid, listitem + PlayerInfo[playerid][pFurnitureIndex]);
			}
			else
			{
			    ShowDialogToPlayer(playerid, DIALOG_BUYFURNITURE1);
			}
	    }
     	case DIALOG_BUY:
	    {
	        if(response)
	        {
	            new businessid = GetInsideBusiness(playerid);

	            if(BusinessInfo[businessid][bProducts] <= 0)
	            {
	                return SendClientMessage(playerid, COLOR_LIGHTRED, "Doanh nghiep nay da het hang.");
	            }

	            if(BusinessInfo[businessid][bType] == BUSINESS_STORE)
	            {
	                switch(listitem)
	                {
	                    case 0:
	                    {
                         	new price = 100;

	                        if(PlayerInfo[playerid][pCash] < price)
	                        {
	                            return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong du tien. Ban khong the mua.");
	                        }

	                        if(PlayerInfo[playerid][pTraderUpgrade] > 0)
	                        {
								price -= percent(price, (PlayerInfo[playerid][pTraderUpgrade] * 10));
								SendClientMessageEx(playerid, COLOR_YELLOW3, "Trader Perk: Your level %i/3 dac quyen thuong nhan da giam gia mat hang nay xuong $%i.", PlayerInfo[playerid][pTraderUpgrade], price);
	                        }

	                        PlayerInfo[playerid][pPhone] = random(799999) + 199999;
	                        GivePlayerCash(playerid, -price);

							BusinessInfo[businessid][bCash] += price;
	                        BusinessInfo[businessid][bProducts]--;

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE businesses SET cash = %i, products = %i WHERE id = %i", BusinessInfo[businessid][bCash], BusinessInfo[businessid][bProducts], BusinessInfo[businessid][bID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET phone = %i WHERE uid = %i", PlayerInfo[playerid][pPhone], PlayerInfo[playerid][pID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da thanh toan $%i de quay thu ngan va nhan Dien thoai.", GetPlayerRPName(playerid), price);
	                        SendClientMessageEx(playerid, COLOR_WHITE, "Da mua dien thoai. So dien thoai cua ban la %i.", PlayerInfo[playerid][pPhone]);
						}
						case 1:
						{
						    new price = 500;

						    if(PlayerInfo[playerid][pCash] < price)
	                        {
	                            return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong du tien. Ban khong the mua.");
	                        }
						    if(PlayerInfo[playerid][pWalkieTalkie])
						    {
						        return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban da co mot bo dam.");
						    }

						    if(PlayerInfo[playerid][pTraderUpgrade] > 0)
	                        {
								price -= percent(price, (PlayerInfo[playerid][pTraderUpgrade] * 10));
								SendClientMessageEx(playerid, COLOR_YELLOW3, "Trader Perk: Cap do cua ban %i/3 dac quyen thuong nhan da giam gia mat hang nay xuong $%i.", PlayerInfo[playerid][pTraderUpgrade], price);
	                        }

						    PlayerInfo[playerid][pWalkieTalkie] = 1;
	                        GivePlayerCash(playerid, -price);

							BusinessInfo[businessid][bCash] += price;
	                        BusinessInfo[businessid][bProducts]--;

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE businesses SET cash = %i, products = %i WHERE id = %i", BusinessInfo[businessid][bCash], BusinessInfo[businessid][bProducts], BusinessInfo[businessid][bID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET walkietalkie = 1 WHERE uid = %i", PlayerInfo[playerid][pID]);
	                        mysql_tquery(connectionID, queryBuffer);

                            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da thanh toan $%i cho nguoi ban hang va nhan duoc mot bo dam.", GetPlayerRPName(playerid), price);
	                        SendClientMessage(playerid, COLOR_WHITE, "Da mua bo dam. Su dung /wt de noi va /channel de thay doi.");
						}
						case 2:
						{
						    new price = 10;

						    if(PlayerInfo[playerid][pCash] < price)
	                        {
	                            return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong co du tien. Ban khong the mua vat pham nay.");
	                        }
						    if(PlayerInfo[playerid][pCigars] >= 20)
						    {
						        return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong the mua 20 dieu Xi Ga.");
						    }

						    if(PlayerInfo[playerid][pTraderUpgrade] > 0)
	                        {
								price -= percent(price, (PlayerInfo[playerid][pTraderUpgrade] * 10));
								SendClientMessageEx(playerid, COLOR_YELLOW3, "Trader Perk: Cap do cua ban %i/3 dac quyen thuong nhan da giam gia mat hang nay xuong $%i.", PlayerInfo[playerid][pTraderUpgrade], price);
	                        }

						    PlayerInfo[playerid][pCigars] += 10;
	                        GivePlayerCash(playerid, -price);

							BusinessInfo[businessid][bCash] += price;
	                        BusinessInfo[businessid][bProducts]--;

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE businesses SET cash = %i, products = %i WHERE id = %i", BusinessInfo[businessid][bCash], BusinessInfo[businessid][bProducts], BusinessInfo[businessid][bID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET cigars = %i WHERE uid = %i", PlayerInfo[playerid][pCigars], PlayerInfo[playerid][pID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da thanh toan $%i cho nguoi ban hang va nhan duoc mot tui cigar.", GetPlayerRPName(playerid), price);
	                        SendClientMessage(playerid, COLOR_WHITE, "Da mua Xi Ga. Su dung /usecigar de hut Xi Ga.");
						}
						case 3:
						{
						    new price = 50;

						    if(PlayerInfo[playerid][pCash] < price)
	                        {
	                            return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong co du tien. Ban khong the mua vat pham nay.");
	                        }
						    if(PlayerInfo[playerid][pSpraycans] + 10 > 20)
						    {
						        return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong the mua qua 20 binh xit.");
						    }

						    if(PlayerInfo[playerid][pTraderUpgrade] > 0)
	                        {
								price -= percent(price, (PlayerInfo[playerid][pTraderUpgrade] * 10));
								SendClientMessageEx(playerid, COLOR_YELLOW3, "Trader Perk: Cap do cua ban %i/3 dac quyen thuong nhan da giam gia mat hang nay xuong $%i.", PlayerInfo[playerid][pTraderUpgrade], price);
	                        }

						    PlayerInfo[playerid][pSpraycans] += 10;
	                        GivePlayerCash(playerid, -price);

							BusinessInfo[businessid][bCash] += price;
	                        BusinessInfo[businessid][bProducts]--;

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE businesses SET cash = %i, products = %i WHERE id = %i", BusinessInfo[businessid][bCash], BusinessInfo[businessid][bProducts], BusinessInfo[businessid][bID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET spraycans = %i WHERE uid = %i", PlayerInfo[playerid][pSpraycans], PlayerInfo[playerid][pID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da thanh toan $%i cho nguoi ban hang va nhan duoc 10 spraycans.", GetPlayerRPName(playerid), price);
	                        SendClientMessage(playerid, COLOR_WHITE, "Da mua binh xit. Su dung /colorcar va /paintcar trong xe de su dung.");
						}
						case 4:
						{
						    new price = 100;

						    if(PlayerInfo[playerid][pCash] < price)
	                        {
	                            return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong co du tien. Ban khong the mua vat pham nay.");
	                        }
						    if(PlayerInfo[playerid][pPhonebook])
						    {
						        return SendClientMessage(playerid, COLOR_LIGHTRED, "Danh ba cua ban da hoat dong.");
						    }

						    if(PlayerInfo[playerid][pTraderUpgrade] > 0)
	                        {
								price -= percent(price, (PlayerInfo[playerid][pTraderUpgrade] * 10));
								SendClientMessageEx(playerid, COLOR_YELLOW3, "Trader Perk: Cap do cua ban %i/3 dac quyen thuong nhan da giam gia mat hang nay xuong $%i.", PlayerInfo[playerid][pTraderUpgrade], price);
	                        }

						    PlayerInfo[playerid][pPhonebook] = 1;
	                        GivePlayerCash(playerid, -price);

							BusinessInfo[businessid][bCash] += price;
	                        BusinessInfo[businessid][bProducts]--;

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE businesses SET cash = %i, products = %i WHERE id = %i", BusinessInfo[businessid][bCash], BusinessInfo[businessid][bProducts], BusinessInfo[businessid][bID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET phonebook = 1 WHERE uid = %i", PlayerInfo[playerid][pID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da thanh toan $%i cho nguoi ban hang va nhan duoc danh ba.", GetPlayerRPName(playerid), price);
	                        SendClientMessage(playerid, COLOR_WHITE, "Da mua Danh ba. Su dung /number de biet so dien thoai nguoi do.");
						}
						case 5:
						{
						    new price = 200;

						    if(PlayerInfo[playerid][pCash] < price)
	                        {
	                            return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong co du tien . Ban khong the mua vat pham nay");
	                        }

                            if(PlayerInfo[playerid][pTraderUpgrade] > 0)
	                        {
								price -= percent(price, (PlayerInfo[playerid][pTraderUpgrade] * 10));
								SendClientMessageEx(playerid, COLOR_YELLOW3, "Trader Perk: Cap do cua ban %i/3 dac quyen thuong nhan da giam gia mat hang nay xuong $%i.", PlayerInfo[playerid][pTraderUpgrade], price);
	                        }

							GivePlayerWeaponEx(playerid, 43);
	                        GivePlayerCash(playerid, -price);

							BusinessInfo[businessid][bCash] += price;
	                        BusinessInfo[businessid][bProducts]--;

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE businesses SET cash = %i, products = %i WHERE id = %i", BusinessInfo[businessid][bCash], BusinessInfo[businessid][bProducts], BusinessInfo[businessid][bID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da thanh toan $%i cho nguoi ban hang va nhan duoc Camera.", GetPlayerRPName(playerid), price);
	                        SendClientMessage(playerid, COLOR_WHITE, "Da mua Camera.");
						}
						case 6:
						{
						    new price = 500;

						    if(PlayerInfo[playerid][pCash] < price)
	                        {
	                            return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong co du tien. Ban khong the mua vat pham nay.");
	                        }
						    if(PlayerInfo[playerid][pMP3Player])
						    {
						        return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban da co mot chiec may MP3 .");
						    }

						    if(PlayerInfo[playerid][pTraderUpgrade] > 0)
	                        {
								price -= percent(price, (PlayerInfo[playerid][pTraderUpgrade] * 10));
								SendClientMessageEx(playerid, COLOR_YELLOW3, "Trader Perk: Cap do cua ban %i/3 dac quyen thuong nhan da giam gia mat hang nay xuong $%i.", PlayerInfo[playerid][pTraderUpgrade], price);
	                        }

						    PlayerInfo[playerid][pMP3Player] = 1;
	                        GivePlayerCash(playerid, -price);

							BusinessInfo[businessid][bCash] += price;
	                        BusinessInfo[businessid][bProducts]--;

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE businesses SET cash = %i, products = %i WHERE id = %i", BusinessInfo[businessid][bCash], BusinessInfo[businessid][bProducts], BusinessInfo[businessid][bID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET mp3player = 1 WHERE uid = %i", PlayerInfo[playerid][pID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da thanh toan $%i to the shopkeeper and received an MP3 player.", GetPlayerRPName(playerid), price);
	                        SendClientMessage(playerid, COLOR_WHITE, "Da mua MP3. su dung /mp3 de chon nhac va nghe.");
						}
						case 7:
						{
						    new price = 500;

						    if(PlayerInfo[playerid][pCash] < price)
	                        {
	                            return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong co du tien. Ban khong the mua vat pham nay.");
	                        }
						    if(PlayerInfo[playerid][pFishingRod])
						    {
						        return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban da mot chiec can cau ca roi.");
						    }

						    if(PlayerInfo[playerid][pTraderUpgrade] > 0)
	                        {
								price -= percent(price, (PlayerInfo[playerid][pTraderUpgrade] * 10));
								SendClientMessageEx(playerid, COLOR_YELLOW3, "Trader Perk: Cap dua cua ban %i/3 dac quyen thuong nhan da giam gia mat hang nay xuong  $%i.", PlayerInfo[playerid][pTraderUpgrade], price);
	                        }

						    PlayerInfo[playerid][pFishingRod] = 1;
	                        GivePlayerCash(playerid, -price);

							BusinessInfo[businessid][bCash] += price;
	                        BusinessInfo[businessid][bProducts]--;

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE businesses SET cash = %i, products = %i WHERE id = %i", BusinessInfo[businessid][bCash], BusinessInfo[businessid][bProducts], BusinessInfo[businessid][bID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET fishingrod = 1 WHERE uid = %i", PlayerInfo[playerid][pID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da thanh toan $%i cho nguoi ban hang va nhan duoc can cau.", GetPlayerRPName(playerid), price);
	                        SendClientMessage(playerid, COLOR_WHITE, "Da mua can cau ca. Su dung /fish Tai cang tau hoac ben thuyen de cau ca.");
						}
						case 8:
						{
						    new price = 100;

						    if(PlayerInfo[playerid][pCash] < price)
	                        {
	                            return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong co du tien. Ban khong the mua vat pham nay.");
	                        }
						    if(PlayerInfo[playerid][pFishingBait] + 10 > 20)
						    {
						        return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong the mua qua 20 mieng moi cau ca.");
						    }

						    if(PlayerInfo[playerid][pTraderUpgrade] > 0)
	                        {
								price -= percent(price, (PlayerInfo[playerid][pTraderUpgrade] * 10));
								SendClientMessageEx(playerid, COLOR_YELLOW3, "Trader Perk: Cap do cua ban %i/3 dac quyen thuong nhan da giam gia mat hang nay xuong $%i.", PlayerInfo[playerid][pTraderUpgrade], price);
	                        }

						    PlayerInfo[playerid][pFishingBait] += 10;
	                        GivePlayerCash(playerid, -price);

							BusinessInfo[businessid][bCash] += price;
	                        BusinessInfo[businessid][bProducts]--;

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE businesses SET cash = %i, products = %i WHERE id = %i", BusinessInfo[businessid][bCash], BusinessInfo[businessid][bProducts], BusinessInfo[businessid][bID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET fishingbait = %i WHERE uid = %i", PlayerInfo[playerid][pFishingBait], PlayerInfo[playerid][pID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da thanh toan $%i cho nguoi ban hang va nhan duoc moi cau ca.", GetPlayerRPName(playerid), price);
	                        SendClientMessage(playerid, COLOR_WHITE, "Da mua moi cau ca. Su dung moi cau ca de bat nhung con ca lon.");
						}
						case 9:
						{
						    new price = 500;

						    if(PlayerInfo[playerid][pCash] < price)
	                        {
	                            return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong co du tien. Ban khong the mua vat pham nay.");
	                        }
						    if(PlayerInfo[playerid][pMuriaticAcid] + 1 > 10)
						    {
						        return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong the mua qua 10 chai Axit Muriatic.");
						    }

						    if(PlayerInfo[playerid][pTraderUpgrade] > 0)
	                        {
								price -= percent(price, (PlayerInfo[playerid][pTraderUpgrade] * 10));
								SendClientMessageEx(playerid, COLOR_YELLOW3, "Trader Perk: Cap do cua ban %i/3 dac quyen thuong nhan da giam gia mat hang nay xuong $%i.", PlayerInfo[playerid][pTraderUpgrade], price);
	                        }

						    PlayerInfo[playerid][pMuriaticAcid] += 1;
	                        GivePlayerCash(playerid, -price);

							BusinessInfo[businessid][bCash] += price;
	                        BusinessInfo[businessid][bProducts]--;

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE businesses SET cash = %i, products = %i WHERE id = %i", BusinessInfo[businessid][bCash], BusinessInfo[businessid][bProducts], BusinessInfo[businessid][bID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET muriaticacid = %i WHERE uid = %i", PlayerInfo[playerid][pMuriaticAcid], PlayerInfo[playerid][pID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da thanh toan $%i hay den quay thhu ngan va nhan Chai Axit Muriatic.", GetPlayerRPName(playerid), price);
	                        SendClientMessage(playerid, COLOR_WHITE, "Da mua Axit Muriatic.");
						}
						case 10:
						{
						    new price = 200;

						    if(PlayerInfo[playerid][pCash] < price)
	                        {
	                            return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong co du tien. Ban khong the mua vat pham nay.");
	                        }
						    if(PlayerInfo[playerid][pBakingSoda] + 1 > 3)
						    {
						        return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong the mua qua 3 chai Soda.");
						    }

						    if(PlayerInfo[playerid][pTraderUpgrade] > 0)
	                        {
								price -= percent(price, (PlayerInfo[playerid][pTraderUpgrade] * 10));
								SendClientMessageEx(playerid, COLOR_YELLOW3, "Trader Perk: Cap do cua ban %i/3 dac quyen thuong nhan da giam gia mat hang nay xuong $%i.", PlayerInfo[playerid][pTraderUpgrade], price);
	                        }

						    PlayerInfo[playerid][pBakingSoda] += 1;
	                        GivePlayerCash(playerid, -price);

							BusinessInfo[businessid][bCash] += price;
	                        BusinessInfo[businessid][bProducts]--;

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE businesses SET cash = %i, products = %i WHERE id = %i", BusinessInfo[businessid][bCash], BusinessInfo[businessid][bProducts], BusinessInfo[businessid][bID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET bakingsoda = %i WHERE uid = %i", PlayerInfo[playerid][pBakingSoda], PlayerInfo[playerid][pID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da thanh toan $%i cho nguoi ban hang va nhan duoc baking soda.", GetPlayerRPName(playerid), price);
	                        SendClientMessage(playerid, COLOR_WHITE, "Da mua Soda.");
						}
						case 11:
						{
						    new price = 600;

						    if(PlayerInfo[playerid][pCash] < price)
	                        {
	                            return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong co du tien. Ban khong the mua vat pham nay.");
	                        }
						    if(PlayerInfo[playerid][pWatch])
						    {
						        return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban da co 1 chiec dong ho bo tui roi.");
						    }

						    if(PlayerInfo[playerid][pTraderUpgrade] > 0)
	                        {
								price -= percent(price, (PlayerInfo[playerid][pTraderUpgrade] * 10));
								SendClientMessageEx(playerid, COLOR_YELLOW3, "Trader Perk: Cap do cua ban %i/3 dac quyen thuong nhan da giam gia mat hang nay xuong $%i.", PlayerInfo[playerid][pTraderUpgrade], price);
	                        }

						    PlayerInfo[playerid][pWatch] = 1;
	                        GivePlayerCash(playerid, -price);

							BusinessInfo[businessid][bCash] += price;
	                        BusinessInfo[businessid][bProducts]--;

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE businesses SET cash = %i, products = %i WHERE id = %i", BusinessInfo[businessid][bCash], BusinessInfo[businessid][bProducts], BusinessInfo[businessid][bID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET watch = 1 WHERE uid = %i", PlayerInfo[playerid][pID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da thanh toan $%i cho nguoi ban hang va nhan duoc mot chiec dong ho.", GetPlayerRPName(playerid), price);
	                        SendClientMessage(playerid, COLOR_WHITE, "Da mua dong ho bo tui. Su dung /watch de tat no.");
						}
						case 12:
						{
						    new price = 200;

						    if(PlayerInfo[playerid][pCash] < price)
	                        {
	                            return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong co du tien. Ban khong the mua vat pham nay.");
	                        }
						    if(PlayerInfo[playerid][pGPS])
						    {
						        return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban da co mot chiec GPS roi.");
						    }

						    if(PlayerInfo[playerid][pTraderUpgrade] > 0)
	                        {
								price -= percent(price, (PlayerInfo[playerid][pTraderUpgrade] * 10));
								SendClientMessageEx(playerid, COLOR_YELLOW3, "Trader Perk: Cap do cua ban %i/3 dac quyen thuong nhan da giam gia mat hang nay xuong $%i.", PlayerInfo[playerid][pTraderUpgrade], price);
	                        }

						    PlayerInfo[playerid][pGPS] = 1;
	                        GivePlayerCash(playerid, -price);

							BusinessInfo[businessid][bCash] += price;
	                        BusinessInfo[businessid][bProducts]--;

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE businesses SET cash = %i, products = %i WHERE id = %i", BusinessInfo[businessid][bCash], BusinessInfo[businessid][bProducts], BusinessInfo[businessid][bID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET gps = 1 WHERE uid = %i", PlayerInfo[playerid][pID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da thanh toan $%i cho nguoi ban hang va nhan duoc GPS.", GetPlayerRPName(playerid), price);
	                        SendClientMessage(playerid, COLOR_WHITE, "Da mua GPS. Su dung /gps de hoat dong.");
						}
						case 13:
						{
						    new price = 100;

						    if(PlayerInfo[playerid][pCash] < price)
	                        {
	                            return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong co du tien. Ban khong the mua vat pham nay.");
	                        }
						    if(PlayerInfo[playerid][pGasCan] + 5 > 20)
						    {
						        return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong the co nhieu hon 20 lit xang.");
						    }

						    if(PlayerInfo[playerid][pTraderUpgrade] > 0)
	                        {
								price -= percent(price, (PlayerInfo[playerid][pTraderUpgrade] * 10));
								SendClientMessageEx(playerid, COLOR_YELLOW3, "Trader Perk: Cap do cua ban %i/3 dac quyen thuong nhan da giam gia mat hang nay xuong $%i.", PlayerInfo[playerid][pTraderUpgrade], price);
	                        }

						    PlayerInfo[playerid][pGasCan] += 5;
	                        GivePlayerCash(playerid, -price);

							BusinessInfo[businessid][bCash] += price;
	                        BusinessInfo[businessid][bProducts]--;

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE businesses SET cash = %i, products = %i WHERE id = %i", BusinessInfo[businessid][bCash], BusinessInfo[businessid][bProducts], BusinessInfo[businessid][bID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET gascan = %i WHERE uid = %i", PlayerInfo[playerid][pGasCan], PlayerInfo[playerid][pID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da thanh toan $%i cho nguoi ban hang va nhan duoc 5 lit xang.", GetPlayerRPName(playerid), price);
	                        SendClientMessage(playerid, COLOR_WHITE, "Da mua binh xang. Su dung /gascan trong mot chiec xe de do day nhien lieu.");
						}
						case 14:
						{
						    new price = 20;

						    if(PlayerInfo[playerid][pCash] < price)
	                        {
	                            return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong co du tien. Ban khong the mua vat pham nay.");
	                        }
						    if(PlayerInfo[playerid][pRope] + 2 > 10)
						    {
						        return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong the co nhieu hon 10 soi day.");
						    }

						    if(PlayerInfo[playerid][pTraderUpgrade] > 0)
	                        {
								price -= percent(price, (PlayerInfo[playerid][pTraderUpgrade] * 10));
								SendClientMessageEx(playerid, COLOR_YELLOW3, "Trader Perk: Cap do cua ban %i/3 dac quyen thuong nhan da giam gia mat hang nay xuong $%i.", PlayerInfo[playerid][pTraderUpgrade], price);
	                        }

						    PlayerInfo[playerid][pRope] += 2;
	                        GivePlayerCash(playerid, -price);

							BusinessInfo[businessid][bCash] += price;
	                        BusinessInfo[businessid][bProducts]--;

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE businesses SET cash = %i, products = %i WHERE id = %i", BusinessInfo[businessid][bCash], BusinessInfo[businessid][bProducts], BusinessInfo[businessid][bID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET rope = %i WHERE uid = %i", PlayerInfo[playerid][pRope], PlayerInfo[playerid][pID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da thanh toan $%i to the shopkeeper and received 2 ropes.", GetPlayerRPName(playerid), price);
	                        SendClientMessage(playerid, COLOR_WHITE, "Da mua soi day. Su dung /tie de troi nguoi nao do trong xe.");
						}
						case 15:
						{
						    new price = 5000;

						    if(PlayerInfo[playerid][pCash] < price)
	                        {
	                            return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong co du tien. Ban khong the mua vat pham nay.");
	                        }
						    if(PlayerInfo[playerid][pMask])
						    {
						        return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban da co mat na.");
						    }

						    if(PlayerInfo[playerid][pTraderUpgrade] > 0)
	                        {
								price -= percent(price, (PlayerInfo[playerid][pTraderUpgrade] * 10));
								SendClientMessageEx(playerid, COLOR_YELLOW3, "Trader Perk: Cap do cua ban %i/3 dac quyen thuong nhan da giam gia mat hang nay xuong $%i.", PlayerInfo[playerid][pTraderUpgrade], price);
	                        }

						    PlayerInfo[playerid][pMask] = 1;
	                        GivePlayerCash(playerid, -price);

							BusinessInfo[businessid][bCash] += price;
	                        BusinessInfo[businessid][bProducts]--;

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE businesses SET cash = %i, products = %i WHERE id = %i", BusinessInfo[businessid][bCash], BusinessInfo[businessid][bProducts], BusinessInfo[businessid][bID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET mask = 1 WHERE uid = %i", PlayerInfo[playerid][pID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da thanh toan $%i cho nguoi ban hang va nhan duoc mat na.", GetPlayerRPName(playerid), price);
	                        SendClientMessage(playerid, COLOR_WHITE, "Da mua Mat Na. Su dung /mask de mang no.");
						}
					}
				}/*
				else if(BusinessInfo[businessid][bType] == BUSINESS_GUNSHOP)
				{
				    if(PlayerInfo[playerid][pHours] < 2 || PlayerInfo[playerid][pWeaponRestricted])
				    {
				        return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban bi han che vu khi hoac ban choi it hon 2 gio. Ban khong the mua hang o day.");
					}

				    switch(listitem)
					{
				        case 0:
				        {
				            new price = 1500;

				            if(PlayerInfo[playerid][pCash] < price)
	                        {
	                            return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong co du tien. Ban khong the mua vat pham nay.");
	                        }
	                        if(PlayerHasWeapon(playerid, 22))
	                        {
	                            return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban da co vu khi nay roi.");
							}

							if(PlayerInfo[playerid][pTraderUpgrade] > 0)
	                        {
								price -= percent(price, (PlayerInfo[playerid][pTraderUpgrade] * 10));
								SendClientMessageEx(playerid, COLOR_YELLOW3, "Trader Perk: Cap do cua ban %i/3 dac quyen thuong nhan da giam gia mat hang nay xuong $%i.", PlayerInfo[playerid][pTraderUpgrade], price);
	                        }

	                        GivePlayerCash(playerid, -price);
	                        GivePlayerWeaponEx(playerid, 22);

							BusinessInfo[businessid][bCash] += price;
	                        BusinessInfo[businessid][bProducts]--;

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE businesses SET cash = %i, products = %i WHERE id = %i", BusinessInfo[businessid][bCash], BusinessInfo[businessid][bProducts], BusinessInfo[businessid][bID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da thanh toan $%i cho chu cua hang va nhan mat khau sung 9mm.", GetPlayerRPName(playerid), price);
	                        SendClientMessage(playerid, COLOR_WHITE, "Da mua 9mm pistol.");
				        }
				        case 1:
				        {
				            new price = 2000;

				            if(PlayerInfo[playerid][pCash] < price)
	                        {
	                            return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong co du tien. Ban khong the mua vat pham nay.");
	                        }
	                        if(PlayerHasWeapon(playerid, 25))
	                        {
	                            return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban da co vu khi nay roi.");
							}

							if(PlayerInfo[playerid][pTraderUpgrade] > 0)
	                        {
								price -= percent(price, (PlayerInfo[playerid][pTraderUpgrade] * 10));
								SendClientMessageEx(playerid, COLOR_YELLOW3, "Trader Perk: Cap do cua ban %i/3 dac quyen thuong nhan da giam gia mat hang nay xuong $%i.", PlayerInfo[playerid][pTraderUpgrade], price);
	                        }

	                        GivePlayerCash(playerid, -price);
	                        GivePlayerWeaponEx(playerid, 25);

							BusinessInfo[businessid][bCash] += price;
	                        BusinessInfo[businessid][bProducts]--;

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE businesses SET cash = %i, products = %i WHERE id = %i", BusinessInfo[businessid][bCash], BusinessInfo[businessid][bProducts], BusinessInfo[businessid][bID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da thanh toan $%i cho chu cua hang va nhan duoc Shotgun.", GetPlayerRPName(playerid), price);
	                        SendClientMessage(playerid, COLOR_WHITE, "Da mua Shotgun.");
				        }
				        case 2:
				        {
				            new price = 4000;

				            if(PlayerInfo[playerid][pCash] < price)
	                        {
	                            return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong co du tien. Ban khong the mua vat pham nay.");
	                        }
	                        if(PlayerHasWeapon(playerid, 33))
	                        {
	                            return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban da co vu khi nay roi.");
							}

							if(PlayerInfo[playerid][pTraderUpgrade] > 0)
	                        {
								price -= percent(price, (PlayerInfo[playerid][pTraderUpgrade] * 10));
								SendClientMessageEx(playerid, COLOR_YELLOW3, "Trader Perk: Cap do cua ban %i/3 dac quyen thuong nhan da giam gia mat hang nay xuong $%i.", PlayerInfo[playerid][pTraderUpgrade], price);
	                        }

	                        GivePlayerCash(playerid, -price);
	                        GivePlayerWeaponEx(playerid, 33);

							BusinessInfo[businessid][bCash] += price;
	                        BusinessInfo[businessid][bProducts]--;

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE businesses SET cash = %i, products = %i WHERE id = %i", BusinessInfo[businessid][bCash], BusinessInfo[businessid][bProducts], BusinessInfo[businessid][bID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da thanh toan $%i cho chu cua hang va nhan duoc country rifle.", GetPlayerRPName(playerid), price);
	                        SendClientMessage(playerid, COLOR_WHITE, "Da mua Country rifle.");
				        }
				        case 3:
				        {
				            new price = 1500;

				            if(PlayerInfo[playerid][pCash] < price)
	                        {
	                            return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong co du tien. Ban khong the mua vat pham nay.");
	                        }

							if(PlayerInfo[playerid][pTraderUpgrade] > 0)
	                        {
								price -= percent(price, (PlayerInfo[playerid][pTraderUpgrade] * 10));
								SendClientMessageEx(playerid, COLOR_YELLOW3, "Trader Perk: Cap do cua ban %i/3 dac quyen thuong nhan da giam gia mat hang nay xuong $%i.", PlayerInfo[playerid][pTraderUpgrade], price);
	                        }

	                        SetScriptArmour(playerid, 35.0);
	                        GivePlayerCash(playerid, -price);

							BusinessInfo[businessid][bCash] += price;
	                        BusinessInfo[businessid][bProducts]--;

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE businesses SET cash = %i, products = %i WHERE id = %i", BusinessInfo[businessid][bCash], BusinessInfo[businessid][bProducts], BusinessInfo[businessid][bID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da thanh toan $%i cho chu cua hang va nhan duoc Giap Nhe.", GetPlayerRPName(playerid), price);
	                        SendClientMessage(playerid, COLOR_WHITE, "Da mua ao giap nhe (35 diem).");
				        }
				        case 4:
				        {
				            new price = 2500;

				            if(PlayerInfo[playerid][pCash] < price)
	                        {
	                            return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong co du tien. Ban khong the mua vat pham nay.");
	                        }

							if(PlayerInfo[playerid][pTraderUpgrade] > 0)
	                        {
								price -= percent(price, (PlayerInfo[playerid][pTraderUpgrade] * 10));
								SendClientMessageEx(playerid, COLOR_YELLOW3, "Trader Perk: Cap do cua ban %i/3 dac quyen thuong nhan da giam gia mat hang nay xuong $%i.", PlayerInfo[playerid][pTraderUpgrade], price);
	                        }

	                        SetScriptArmour(playerid, 60.0);
	                        GivePlayerCash(playerid, -price);

							BusinessInfo[businessid][bCash] += price;
	                        BusinessInfo[businessid][bProducts]--;

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE businesses SET cash = %i, products = %i WHERE id = %i", BusinessInfo[businessid][bCash], BusinessInfo[businessid][bProducts], BusinessInfo[businessid][bID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da thanh toan $%i cho chu cua hang va nhan duoc Ao giap trung binh.", GetPlayerRPName(playerid), price);
	                        SendClientMessage(playerid, COLOR_WHITE, "Da mua ao giap trung binh (60 diem).");
				        }
					}
				}*/
				else if(BusinessInfo[businessid][bType] == BUSINESS_CLOTHES)
				{
				    new
						string[128];

	                format(string, sizeof(string), "%s's %s [%i san pham]", BusinessInfo[businessid][bOwner], bizInteriors[BusinessInfo[businessid][bType]][intType], BusinessInfo[businessid][bProducts]);

				    if(listitem == 0)
					{
						//ShowDialogToPlayer(playerid, DIALOG_BUYCLOTHES);
						ShowPlayerSelectionMenu(playerid, MODEL_SELECTION_CLOTHES, "Shop Quan Ao", clothesShopSkins, sizeof(clothesShopSkins));
					}
					else
					{
						PlayerInfo[playerid][pCategory] = listitem - 1;
						ShowDialogToPlayer(playerid, DIALOG_BUYCLOTHINGTYPE);
				    }
				}
				else if(BusinessInfo[businessid][bType] == BUSINESS_GYM)
				{
				    switch(listitem)
				    {
				        case 0:
				        {
	                        if(PlayerInfo[playerid][pFightStyle] == FIGHT_STYLE_NORMAL)
	                        {
	                            return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban da co phong cach chien dau nay.");
	                        }

	                        PlayerInfo[playerid][pFightStyle] = FIGHT_STYLE_NORMAL;
	                        SetPlayerFightingStyle(playerid, PlayerInfo[playerid][pFightStyle]);

							mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET fightstyle = %i WHERE uid = %i", PlayerInfo[playerid][pFightStyle], PlayerInfo[playerid][pID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        SendClientMessage(playerid, COLOR_WHITE, "Ban da chon phong cach chien dau binh thuong.");
						}
						case 1:
						{
						    new price = 75;

						    if(PlayerInfo[playerid][pCash] < price)
	                        {
	                            return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong co du tien. Ban khong the mua vat pham nay.");
	                        }
	                        if(PlayerInfo[playerid][pFightStyle] == FIGHT_STYLE_BOXING)
	                        {
	                            return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban da co phong cach chien dau nay.");
	                        }

							if(PlayerInfo[playerid][pTraderUpgrade] > 0)
	                        {
								price -= percent(price, (PlayerInfo[playerid][pTraderUpgrade] * 10));
								SendClientMessageEx(playerid, COLOR_YELLOW3, "Trader Perk: Cap do cua ban %i/3 dac quyen thuong nhan da giam gia mat hang nay xuong $%i.", PlayerInfo[playerid][pTraderUpgrade], price);
	                        }

	                        GivePlayerCash(playerid, -price);
	                        BusinessInfo[businessid][bCash] += price;

                            PlayerInfo[playerid][pFightStyle] = FIGHT_STYLE_BOXING;
	                        SetPlayerFightingStyle(playerid, PlayerInfo[playerid][pFightStyle]);

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE businesses SET cash = %i WHERE id = %i", BusinessInfo[businessid][bCash], BusinessInfo[businessid][bID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET fightstyle = %i WHERE uid = %i", PlayerInfo[playerid][pFightStyle], PlayerInfo[playerid][pID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        SendClientMessageEx(playerid, COLOR_WHITE, "Ban da mua phong cach chien dau boxing voi gia $%i.", price);
						}
						case 2:
						{
						    new price = 60;

						    if(PlayerInfo[playerid][pCash] < price)
	                        {
	                            return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong co du tien. Ban khong the mua vat pham nay.");
	                        }
	                        if(PlayerInfo[playerid][pFightStyle] == FIGHT_STYLE_KUNGFU)
	                        {
	                            return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban da co phong cach chien dau nay.");
	                        }

							if(PlayerInfo[playerid][pTraderUpgrade] > 0)
	                        {
								price -= percent(price, (PlayerInfo[playerid][pTraderUpgrade] * 10));
								SendClientMessageEx(playerid, COLOR_YELLOW3, "Trader Perk: Cap do cua ban %i/3 dac quyen thuong nhan da giam gia mat hang nay xuong $%i.", PlayerInfo[playerid][pTraderUpgrade], price);
	                        }

	                        GivePlayerCash(playerid, -price);
	                        BusinessInfo[businessid][bCash] += price;

	                        PlayerInfo[playerid][pFightStyle] = FIGHT_STYLE_KUNGFU;
	                        SetPlayerFightingStyle(playerid, PlayerInfo[playerid][pFightStyle]);

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE businesses SET cash = %i WHERE id = %i", BusinessInfo[businessid][bCash], BusinessInfo[businessid][bID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET fightstyle = %i WHERE uid = %i", PlayerInfo[playerid][pFightStyle], PlayerInfo[playerid][pID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        SendClientMessageEx(playerid, COLOR_WHITE, "Ban da mua phong cach chien dau Kung-Fu voi gia $%i.", price);
						}
						case 3:
						{
						    new price = 75;

						    if(PlayerInfo[playerid][pCash] < price)
	                        {
	                            return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong co du tien. Ban khong the mua vat pham nay.");
	                        }
	                        if(PlayerInfo[playerid][pFightStyle] == FIGHT_STYLE_KNEEHEAD)
	                        {
	                            return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban da co phong cach chien dau nay.");
	                        }

							if(PlayerInfo[playerid][pTraderUpgrade] > 0)
	                        {
								price -= percent(price, (PlayerInfo[playerid][pTraderUpgrade] * 10));
								SendClientMessageEx(playerid, COLOR_YELLOW3, "Trader Perk: Cap do cua ban %i/3 dac quyen thuong nhan da giam gia mat hang nay xuong $%i.", PlayerInfo[playerid][pTraderUpgrade], price);
	                        }

	                        GivePlayerCash(playerid, -price);
	                        BusinessInfo[businessid][bCash] += price;

	                        PlayerInfo[playerid][pFightStyle] = FIGHT_STYLE_KNEEHEAD;
	                        SetPlayerFightingStyle(playerid, PlayerInfo[playerid][pFightStyle]);

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE businesses SET cash = %i WHERE id = %i", BusinessInfo[businessid][bCash], BusinessInfo[businessid][bID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET fightstyle = %i WHERE uid = %i", PlayerInfo[playerid][pFightStyle], PlayerInfo[playerid][pID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        SendClientMessageEx(playerid, COLOR_WHITE, "Ban da mua phong cach chien dau Kneehead voi gia $%i.", price);
						}
						case 4:
						{
						    new price = 45;

						    if(PlayerInfo[playerid][pCash] < price)
	                        {
	                            return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong co du tien. Ban khong the mua vat pham nay.");
	                        }
	                        if(PlayerInfo[playerid][pFightStyle] == FIGHT_STYLE_GRABKICK)
	                        {
	                            return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban da co phong cach chien dau nay.");
	                        }

							if(PlayerInfo[playerid][pTraderUpgrade] > 0)
	                        {
								price -= percent(price, (PlayerInfo[playerid][pTraderUpgrade] * 10));
								SendClientMessageEx(playerid, COLOR_YELLOW3, "Trader Perk: Cap do cua ban %i/3 dac quyen thuong nhan da giam gia mat hang nay xuong $%i.", PlayerInfo[playerid][pTraderUpgrade], price);
	                        }

	                        GivePlayerCash(playerid, -price);
	                        BusinessInfo[businessid][bCash] += price;

	                        PlayerInfo[playerid][pFightStyle] = FIGHT_STYLE_GRABKICK;
	                        SetPlayerFightingStyle(playerid, PlayerInfo[playerid][pFightStyle]);

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE businesses SET cash = %i WHERE id = %i", BusinessInfo[businessid][bCash], BusinessInfo[businessid][bID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET fightstyle = %i WHERE uid = %i", PlayerInfo[playerid][pFightStyle], PlayerInfo[playerid][pID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        SendClientMessageEx(playerid, COLOR_WHITE, "Ban da mua phong cach chien dau Grabkick voi gia $%i.", price);
						}
						case 5:
						{
						    new price = 35;

						    if(PlayerInfo[playerid][pCash] < price)
	                        {
	                            return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong co du tien. Ban khong the mua vat pham nay.");
	                        }
	                        if(PlayerInfo[playerid][pFightStyle] == FIGHT_STYLE_ELBOW)
	                        {
	                            return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban da co phong cach chien dau nay.");
	                        }

							if(PlayerInfo[playerid][pTraderUpgrade] > 0)
	                        {
								price -= percent(price, (PlayerInfo[playerid][pTraderUpgrade] * 10));
								SendClientMessageEx(playerid, COLOR_YELLOW3, "Trader Perk: Cap do cua ban %i/3 dac quyen thuong nhan da giam gia mat hang nay xuong $%i.", PlayerInfo[playerid][pTraderUpgrade], price);
	                        }

	                        GivePlayerCash(playerid, -price);
	                        BusinessInfo[businessid][bCash] += price;

	                        PlayerInfo[playerid][pFightStyle] = FIGHT_STYLE_ELBOW;
	                        SetPlayerFightingStyle(playerid, PlayerInfo[playerid][pFightStyle]);

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE businesses SET cash = %i WHERE id = %i", BusinessInfo[businessid][bCash], BusinessInfo[businessid][bID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET fightstyle = %i WHERE uid = %i", PlayerInfo[playerid][pFightStyle], PlayerInfo[playerid][pID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        SendClientMessageEx(playerid, COLOR_WHITE, "Ban da mua phong cach chien dua Elbow voi gia $%i.", price);
						}
					}
				}
				else if(BusinessInfo[businessid][bType] == BUSINESS_RESTAURANT)
				{
				    switch(listitem)
				    {
				        case 0:
				        {
				            new price = 6;

				            if(PlayerInfo[playerid][pCash] < price)
	                        {
	                            return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong co du tien. Ban khong the mua vat pham nay.");
	                        }

							if(PlayerInfo[playerid][pTraderUpgrade] > 0)
	                        {
								price -= percent(price, (PlayerInfo[playerid][pTraderUpgrade] * 10));
								SendClientMessageEx(playerid, COLOR_YELLOW3, "Trader Perk: Cap do cua ban %i/3 dac quyen thuong nhan da giam gia mat hang nay xuong $%i.", PlayerInfo[playerid][pTraderUpgrade], price);
	                        }

	                        GivePlayerCash(playerid, -price);
	                        PlayerInfo[playerid][pThirsty] += 20;

							BusinessInfo[businessid][bCash] += price;
	                        BusinessInfo[businessid][bProducts]--;

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE businesses SET cash = %i, products = %i WHERE id = %i", BusinessInfo[businessid][bCash], BusinessInfo[businessid][bProducts], BusinessInfo[businessid][bID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET thirsty = %i WHERE uid = %i", PlayerInfo[playerid][pThirsty], PlayerInfo[playerid][pID]);
		                    mysql_tquery(connectionID, queryBuffer);

	                        SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da thanh toan $%i cho nha hang va mua duoc 1 chai nuoc.", GetPlayerRPName(playerid), price);
						}
						case 1:
				        {
				            new price = 8;

				            if(PlayerInfo[playerid][pCash] < price)
	                        {
	                            return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong co du tien. Ban khong the mua vat pham nay.");
	                        }

							if(PlayerInfo[playerid][pTraderUpgrade] > 0)
	                        {
								price -= percent(price, (PlayerInfo[playerid][pTraderUpgrade] * 10));
								SendClientMessageEx(playerid, COLOR_YELLOW3, "Trader Perk: Cap do cua ban %i/3 dac quyen thuong nhan da giam gia mat hang nay xuong $%i.", PlayerInfo[playerid][pTraderUpgrade], price);
	                        }

	                        GivePlayerCash(playerid, -price);
	                        PlayerInfo[playerid][pThirsty] += 30;

							BusinessInfo[businessid][bCash] += price;
	                        BusinessInfo[businessid][bProducts]--;

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE businesses SET cash = %i, products = %i WHERE id = %i", BusinessInfo[businessid][bCash], BusinessInfo[businessid][bProducts], BusinessInfo[businessid][bID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET thirsty = %i WHERE uid = %i", PlayerInfo[playerid][pThirsty], PlayerInfo[playerid][pID]);
		                    mysql_tquery(connectionID, queryBuffer);
	                        SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da thanh toan $%i cho nguoi ban hang va nhan duoc mot lon sprunk.", GetPlayerRPName(playerid), price);
						}
						case 2:
				        {
				            new price = 10;

				            if(PlayerInfo[playerid][pCash] < price)
	                        {
	                            return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong co du tien. Ban khong the mua vat pham nay.");
	                        }

							if(PlayerInfo[playerid][pTraderUpgrade] > 0)
	                        {
								price -= percent(price, (PlayerInfo[playerid][pTraderUpgrade] * 10));
								SendClientMessageEx(playerid, COLOR_YELLOW3, "Trader Perk: Cap do cua ban %i/3 dac quyen thuong nhan da giam gia mat hang nay xuong $%i.", PlayerInfo[playerid][pTraderUpgrade], price);
	                        }

	                        GivePlayerCash(playerid, -price);
	                        PlayerInfo[playerid][pThirsty] -= 5;
	                        PlayerInfo[playerid][pHunger] += 15;

							BusinessInfo[businessid][bCash] += price;
	                        BusinessInfo[businessid][bProducts]--;

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE businesses SET cash = %i, products = %i WHERE id = %i", BusinessInfo[businessid][bCash], BusinessInfo[businessid][bProducts], BusinessInfo[businessid][bID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET hunger= %i, thirsty = %i WHERE uid = %i", PlayerInfo[playerid][pHunger], PlayerInfo[playerid][pThirsty], PlayerInfo[playerid][pID]);
		                    mysql_tquery(connectionID, queryBuffer);

	                        SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da thanh toan $%i cho nguoi ban hang va nhan duoc khoai tay chien.", GetPlayerRPName(playerid), price);
						}
						case 3:
				        {
				            new price = 13;

				            if(PlayerInfo[playerid][pCash] < price)
	                        {
	                            return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong co du tien. Ban khong the mua vat pham nay.");
	                        }

							if(PlayerInfo[playerid][pTraderUpgrade] > 0)
	                        {
								price -= percent(price, (PlayerInfo[playerid][pTraderUpgrade] * 10));
								SendClientMessageEx(playerid, COLOR_YELLOW3, "Trader Perk: Cap do cua ban %i/3 dac quyen thuong nhan da giam gia mat hang nay xuong $%i.", PlayerInfo[playerid][pTraderUpgrade], price);
	                        }

	                        GivePlayerCash(playerid, -price);
	                        PlayerInfo[playerid][pThirsty] -= 7;
	                        PlayerInfo[playerid][pHunger] += 20;

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET hunger= %i, thirsty = %i WHERE uid = %i", PlayerInfo[playerid][pHunger], PlayerInfo[playerid][pThirsty], PlayerInfo[playerid][pID]);
		                    mysql_tquery(connectionID, queryBuffer);

							BusinessInfo[businessid][bCash] += price;
	                        BusinessInfo[businessid][bProducts]--;

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE businesses SET cash = %i, products = %i WHERE id = %i", BusinessInfo[businessid][bCash], BusinessInfo[businessid][bProducts], BusinessInfo[businessid][bID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da thanh toan $%i cho nguoi ban hang va nhan duoc mot chiec banh Hamburger.", GetPlayerRPName(playerid), price);
						}
						case 4:
				        {
				            new price = 15;

				            if(PlayerInfo[playerid][pCash] < price)
	                        {
	                            return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong co du tien. Ban khong the mua vat pham nay.");
	                        }

							if(PlayerInfo[playerid][pTraderUpgrade] > 0)
	                        {
								price -= percent(price, (PlayerInfo[playerid][pTraderUpgrade] * 10));
								SendClientMessageEx(playerid, COLOR_YELLOW3, "Trader Perk: Cap do cua ban %i/3 dac quyen thuong nhan da giam gia mat hang nay xuong $%i.", PlayerInfo[playerid][pTraderUpgrade], price);
	                        }

	                        GivePlayerCash(playerid, -price);
	                        PlayerInfo[playerid][pThirsty] -= 7;
	                        PlayerInfo[playerid][pHunger] += 20;

							BusinessInfo[businessid][bCash] += price;
	                        BusinessInfo[businessid][bProducts]--;

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE businesses SET cash = %i, products = %i WHERE id = %i", BusinessInfo[businessid][bCash], BusinessInfo[businessid][bProducts], BusinessInfo[businessid][bID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET hunger= %i, thirsty = %i WHERE uid = %i", PlayerInfo[playerid][pHunger], PlayerInfo[playerid][pThirsty], PlayerInfo[playerid][pID]);
		                    mysql_tquery(connectionID, queryBuffer);

	                        SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da thanh toan $%i cho nguoi ban hang va nhan duoc banh mi kep thit.", GetPlayerRPName(playerid), price);
						}
						case 5:
				        {
				            new price = 20;

				            if(PlayerInfo[playerid][pCash] < price)
	                        {
	                            return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong co du tien. Ban khong the mua vat pham nay.");
	                        }

							if(PlayerInfo[playerid][pTraderUpgrade] > 0)
	                        {
								price -= percent(price, (PlayerInfo[playerid][pTraderUpgrade] * 10));
								SendClientMessageEx(playerid, COLOR_YELLOW3, "Trader Perk: Cap do cua ban %i/3 dac quyen thuong nhan da giam gia mat hang nay xuong $%i.", PlayerInfo[playerid][pTraderUpgrade], price);
	                        }

	                        PlayerInfo[playerid][pThirsty] -= 7;
	                        PlayerInfo[playerid][pHunger] += 20;

							BusinessInfo[businessid][bCash] += price;
	                        BusinessInfo[businessid][bProducts]--;

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE businesses SET cash = %i, products = %i WHERE id = %i", BusinessInfo[businessid][bCash], BusinessInfo[businessid][bProducts], BusinessInfo[businessid][bID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET hunger= %i, thirsty = %i WHERE uid = %i", PlayerInfo[playerid][pHunger], PlayerInfo[playerid][pThirsty], PlayerInfo[playerid][pID]);
		                    mysql_tquery(connectionID, queryBuffer);

	                        SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da thanh toan $%i cho nguoi ban hang va nhan duoc mac & pho mat.", GetPlayerRPName(playerid), price);
						}
						case 6:
				        {
				            new price = 15;

				            if(PlayerInfo[playerid][pCash] < price)
	                        {
	                            return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong co du tien. Ban khong the mua vat pham nay.");
	                        }

							if(PlayerInfo[playerid][pTraderUpgrade] > 0)
	                        {
								price -= percent(price, (PlayerInfo[playerid][pTraderUpgrade] * 10));
								SendClientMessageEx(playerid, COLOR_YELLOW3, "Trader Perk: Cap do cua ban %i/3 dac quyen thuong nhan da giam gia mat hang nay xuong $%i.", PlayerInfo[playerid][pTraderUpgrade], price);
	                        }

	                        GivePlayerCash(playerid, -price);
	                        PlayerInfo[playerid][pThirsty] -= 7;
	                        PlayerInfo[playerid][pHunger] += 30;

							BusinessInfo[businessid][bCash] += price;
	                        BusinessInfo[businessid][bProducts]--;

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE businesses SET cash = %i, products = %i WHERE id = %i", BusinessInfo[businessid][bCash], BusinessInfo[businessid][bProducts], BusinessInfo[businessid][bID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET hunger= %i, thirsty = %i WHERE uid = %i", PlayerInfo[playerid][pHunger], PlayerInfo[playerid][pThirsty], PlayerInfo[playerid][pID]);
		                    mysql_tquery(connectionID, queryBuffer);

	                        SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da thanh toan $%i cho nguoi ban hang va nhan duoc chiec banh Sandwich.", GetPlayerRPName(playerid), price);
						}
						case 7:
				        {
				            new price = 25;

				            if(PlayerInfo[playerid][pCash] < price)
	                        {
	                            return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong co du tien. Ban khong the mua vat pham nay.");
	                        }

							if(PlayerInfo[playerid][pTraderUpgrade] > 0)
	                        {
								price -= percent(price, (PlayerInfo[playerid][pTraderUpgrade] * 10));
								SendClientMessageEx(playerid, COLOR_YELLOW3, "Trader Perk: Cap do cua ban %i/3 dac quyen thuong nhan da giam gia mat hang nay xuong $%i.", PlayerInfo[playerid][pTraderUpgrade], price);
	                        }

	                        GivePlayerCash(playerid, -price);
	                        PlayerInfo[playerid][pThirsty] -= 7;
	                        PlayerInfo[playerid][pHunger] += 40;

							BusinessInfo[businessid][bCash] += price;
	                        BusinessInfo[businessid][bProducts]--;

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE businesses SET cash = %i, products = %i WHERE id = %i", BusinessInfo[businessid][bCash], BusinessInfo[businessid][bProducts], BusinessInfo[businessid][bID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET hunger= %i, thirsty = %i WHERE uid = %i", PlayerInfo[playerid][pHunger], PlayerInfo[playerid][pThirsty], PlayerInfo[playerid][pID]);
		                    mysql_tquery(connectionID, queryBuffer);

	                        SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da thanh toan $%i cho nguoi ban hang va nhan duoc ca & khoai tay chien.", GetPlayerRPName(playerid), price);
						}
						case 8:
				        {
				            new price = 30;

				            if(PlayerInfo[playerid][pCash] < price)
	                        {
	                            return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong co du tien. Ban khong the mua vat pham nay.");
	                        }

							if(PlayerInfo[playerid][pTraderUpgrade] > 0)
	                        {
								price -= percent(price, (PlayerInfo[playerid][pTraderUpgrade] * 10));
								SendClientMessageEx(playerid, COLOR_YELLOW3, "Trader Perk: Cap do cua ban %i/3 dac quyen thuong nhan da giam gia mat hang nay xuong $%i.", PlayerInfo[playerid][pTraderUpgrade], price);
	                        }

	                        GivePlayerCash(playerid, -price);
	                        PlayerInfo[playerid][pThirsty] -= 7;
	                        PlayerInfo[playerid][pHunger] += 40;

							BusinessInfo[businessid][bCash] += price;
	                        BusinessInfo[businessid][bProducts]--;

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE businesses SET cash = %i, products = %i WHERE id = %i", BusinessInfo[businessid][bCash], BusinessInfo[businessid][bProducts], BusinessInfo[businessid][bID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET hunger= %i, thirsty = %i WHERE uid = %i", PlayerInfo[playerid][pHunger], PlayerInfo[playerid][pThirsty], PlayerInfo[playerid][pID]);
		                    mysql_tquery(connectionID, queryBuffer);

	                        SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da thanh toan $%i cho nguoi ban hang va nhan duoc chien banh Pizza.", GetPlayerRPName(playerid), price);
						}
				    }
				}
				else if(BusinessInfo[businessid][bType] == BUSINESS_BARCLUB)
				{
				    switch(listitem)
				    {
				        case 0:
				        {
				            new price = 6;

				            if(PlayerInfo[playerid][pCash] < price)
	                        {
	                            return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong co du tien. Ban khong the mua vat pham nay.");
	                        }

							if(PlayerInfo[playerid][pTraderUpgrade] > 0)
	                        {
								price -= percent(price, (PlayerInfo[playerid][pTraderUpgrade] * 10));
								SendClientMessageEx(playerid, COLOR_YELLOW3, "Trader Perk: Cap do cua ban %i/3 dac quyen thuong nhan da giam gia mat hang nay xuong $%i.", PlayerInfo[playerid][pTraderUpgrade], price);
	                        }

	                        GivePlayerCash(playerid, -price);
	                        GivePlayerHealth(playerid, 10.0);

							BusinessInfo[businessid][bCash] += price;
	                        BusinessInfo[businessid][bProducts]--;

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE businesses SET cash = %i, products = %i WHERE id = %i", BusinessInfo[businessid][bCash], BusinessInfo[businessid][bProducts], BusinessInfo[businessid][bID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da thanh toan $%i cho nguoi ban hang va nhan duoc nuoc dong chai.", GetPlayerRPName(playerid), price);
						}
						case 1:
				        {
				            new price = 8;

				            if(PlayerInfo[playerid][pCash] < price)
	                        {
	                            return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong co du tien. Ban khong the mua vat pham nay.");
	                        }

							if(PlayerInfo[playerid][pTraderUpgrade] > 0)
	                        {
								price -= percent(price, (PlayerInfo[playerid][pTraderUpgrade] * 10));
								SendClientMessageEx(playerid, COLOR_YELLOW3, "Trader Perk: Cap do cua ban %i/3 dac quyen thuong nhan da giam gia mat hang nay xuong $%i.", PlayerInfo[playerid][pTraderUpgrade], price);
	                        }

	                        GivePlayerCash(playerid, -price);
	                        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_DRINK_SPRUNK);

							BusinessInfo[businessid][bCash] += price;
	                        BusinessInfo[businessid][bProducts]--;

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE businesses SET cash = %i, products = %i WHERE id = %i", BusinessInfo[businessid][bCash], BusinessInfo[businessid][bProducts], BusinessInfo[businessid][bID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da thanh toan $%i cho nguoi ban hang va nhan duoc mot lon sprunk.", GetPlayerRPName(playerid), price);
						}
						case 2:
				        {
				            new price = 8;

				            if(PlayerInfo[playerid][pCash] < price)
	                        {
	                            return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong co du tien. Ban khong the mua vat pham nay.");
	                        }

							if(PlayerInfo[playerid][pTraderUpgrade] > 0)
	                        {
								price -= percent(price, (PlayerInfo[playerid][pTraderUpgrade] * 10));
								SendClientMessageEx(playerid, COLOR_YELLOW3, "Trader Perk: Cap do cua ban %i/3 dac quyen thuong nhan da giam gia mat hang nay xuong $%i.", PlayerInfo[playerid][pTraderUpgrade], price);
	                        }

	                        GivePlayerCash(playerid, -price);
	                        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_DRINK_BEER);

							BusinessInfo[businessid][bCash] += price;
	                        BusinessInfo[businessid][bProducts]--;

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE businesses SET cash = %i, products = %i WHERE id = %i", BusinessInfo[businessid][bCash], BusinessInfo[businessid][bProducts], BusinessInfo[businessid][bID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da thanh toan $%i to the shopkeeper and received a bottle of beer.", GetPlayerRPName(playerid), price);
						}
						case 3:
				        {
				            new price = 20;

				            if(PlayerInfo[playerid][pCash] < price)
	                        {
	                            return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong co du tien. Ban khong the mua vat pham nay.");
	                        }

							if(PlayerInfo[playerid][pTraderUpgrade] > 0)
	                        {
								price -= percent(price, (PlayerInfo[playerid][pTraderUpgrade] * 10));
								SendClientMessageEx(playerid, COLOR_YELLOW3, "Trader Perk: Cap do cua ban %i/3 dac quyen thuong nhan da giam gia mat hang nay xuong $%i.", PlayerInfo[playerid][pTraderUpgrade], price);
	                        }

	                        GivePlayerCash(playerid, -price);
	                        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_DRINK_WINE);

							BusinessInfo[businessid][bCash] += price;
	                        BusinessInfo[businessid][bProducts]--;

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE businesses SET cash = %i, products = %i WHERE id = %i", BusinessInfo[businessid][bCash], BusinessInfo[businessid][bProducts], BusinessInfo[businessid][bID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da thanh toan $%i to the shopkeeper and received a bottle of wine.", GetPlayerRPName(playerid), price);
						}
						case 4:
				        {
				            new price = 25;

				            if(PlayerInfo[playerid][pCash] < price)
	                        {
	                            return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong co du tien. Ban khong the mua vat pham nay.");
	                        }

							if(PlayerInfo[playerid][pTraderUpgrade] > 0)
	                        {
								price -= percent(price, (PlayerInfo[playerid][pTraderUpgrade] * 10));
								SendClientMessageEx(playerid, COLOR_YELLOW3, "Trader Perk: Cap do cua ban %i/3 dac quyen thuong nhan da giam gia mat hang nay xuong $%i.", PlayerInfo[playerid][pTraderUpgrade], price);
	                        }

	                        GivePlayerCash(playerid, -price);
	                        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_DRINK_WINE);

							BusinessInfo[businessid][bCash] += price;
	                        BusinessInfo[businessid][bProducts]--;

	                        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE businesses SET cash = %i, products = %i WHERE id = %i", BusinessInfo[businessid][bCash], BusinessInfo[businessid][bProducts], BusinessInfo[businessid][bID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da thanh toan $%i cho chu cua hang va nhan duoc mot ly whiskey.", GetPlayerRPName(playerid), price);
						}
					}
				}
				/*else if(BusinessInfo[businessid][bType] == BUSINESS_TOOLSHOP)
				{
				    //First aid kit\t500 materials\nBody repair kit\t1000 materials\nPolice scanner\t2000 materials\nRimkit\t4000 materials

				    switch(listitem)
				    {
				        case 0:
				        {
				            if(PlayerInfo[playerid][pMaterials] < 500)
				            {
				                return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong co nhieu vat lieu.");
				            }
				            if(PlayerInfo[playerid][pFirstAid] + 1 > 20)
				            {
				                return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong the mang qua 20 bo so cuu.");
				            }

				            PlayerInfo[playerid][pFirstAid]++;
				            PlayerInfo[playerid][pMaterials] -= 500;

				            mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET firstaid = %i, materials = %i WHERE uid = %i", PlayerInfo[playerid][pFirstAid], PlayerInfo[playerid][pMaterials], PlayerInfo[playerid][pID]);
				            mysql_tquery(connectionID, queryBuffer);

				            BusinessInfo[businessid][bMaterials] += 500;
				            BusinessInfo[businessid][bProducts]--;

				            mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE businesses SET materials = %i, products = %i WHERE id = %i", BusinessInfo[businessid][bMaterials], BusinessInfo[businessid][bProducts], BusinessInfo[businessid][bID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s doi 500 vat lieu cho chu tiem va nhan mot bo so cuu.", GetPlayerRPName(playerid));
	                        SendClientMessage(playerid, COLOR_WHITE, "HUONG DAN: Su dung /firstaid de su dung bo so cuu.");
						}
						case 1:
				        {
				            if(PlayerInfo[playerid][pMaterials] < 1000)
				            {
				                return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong co nhieu vat lieu.");
				            }
				            if(PlayerInfo[playerid][pBodykits] + 1 > 10)
				            {
				                return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong the mang nhieu hon 10 bo phu kien xe.");
				            }

				            PlayerInfo[playerid][pBodykits]++;
				            PlayerInfo[playerid][pMaterials] -= 1000;

				            mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET bodykits = %i, materials = %i WHERE uid = %i", PlayerInfo[playerid][pBodykits], PlayerInfo[playerid][pMaterials], PlayerInfo[playerid][pID]);
				            mysql_tquery(connectionID, queryBuffer);

				            BusinessInfo[businessid][bMaterials] += 1000;
				            BusinessInfo[businessid][bProducts]--;

				            mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE businesses SET materials = %i, products = %i WHERE id = %i", BusinessInfo[businessid][bMaterials], BusinessInfo[businessid][bProducts], BusinessInfo[businessid][bID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da trao doi 1000 vat lieu cho chu tiem va nhan duoc mot bo phu kien xe.", GetPlayerRPName(playerid));
	                        SendClientMessage(playerid, COLOR_WHITE, "HUONG DAN: Su dung /bodykit trong mot chiec xe de sua chua xe va hoi phuc cho no.");
						}
						case 2:
				        {
				            if(PlayerInfo[playerid][pMaterials] < 2000)
				            {
				                return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong co nhieu vat lieu.");
				            }
				            if(PlayerInfo[playerid][pPoliceScanner])
				            {
				                return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban da co cai nay roi.");
				            }

				            PlayerInfo[playerid][pPoliceScanner] = 1;
				            PlayerInfo[playerid][pMaterials] -= 2000;

				            mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET policescanner = 1, materials = %i WHERE uid = %i", PlayerInfo[playerid][pMaterials], PlayerInfo[playerid][pID]);
				            mysql_tquery(connectionID, queryBuffer);

				            BusinessInfo[businessid][bMaterials] += 2000;
				            BusinessInfo[businessid][bProducts]--;

				            mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE businesses SET materials = %i, products = %i WHERE id = %i", BusinessInfo[businessid][bMaterials], BusinessInfo[businessid][bProducts], BusinessInfo[businessid][bID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s trao doi 2000 vat lieu cho chu tiem va nhan duoc mot may quet canh sat.", GetPlayerRPName(playerid));
	                        SendClientMessage(playerid, COLOR_WHITE, "HUONG DAN: Su dung /scanner de nghe cuoc tro chuyen.");
						}
						case 3:
				        {
				            if(PlayerInfo[playerid][pMaterials] < 4000)
				            {
				                return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong co nhieu vat lieu.");
				            }
				            if(PlayerInfo[playerid][pRimkits] + 1 > 5)
				            {
				                return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong duoc mang qua 5 rimkits.");
				            }

				            PlayerInfo[playerid][pRimkits]++;
				            PlayerInfo[playerid][pMaterials] -= 4000;

				            mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET rimkits = %i, materials = %i WHERE uid = %i", PlayerInfo[playerid][pRimkits], PlayerInfo[playerid][pMaterials], PlayerInfo[playerid][pID]);
				            mysql_tquery(connectionID, queryBuffer);

				            BusinessInfo[businessid][bMaterials] += 4000;
				            BusinessInfo[businessid][bProducts]--;

				            mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE businesses SET materials = %i, products = %i WHERE id = %i", BusinessInfo[businessid][bMaterials], BusinessInfo[businessid][bProducts], BusinessInfo[businessid][bID]);
	                        mysql_tquery(connectionID, queryBuffer);

	                        SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s trao doi 4000 vat lieu cho chu tiem va nhan rimkits.", GetPlayerRPName(playerid));
	                        SendClientMessage(playerid, COLOR_WHITE, "HUONG DAN: Su dung /rimkit trong xe cua ban de lap bo vanh moi.");
						}
					}
				}*/
	        }
	    }
	    case DIALOG_BUYCLOTHES:
	    {
	        // Disabled. See OnPlayerSelectionMenuResponse for the new clothes shop code.
	    }
	    case DIALOG_PICKLOAD:
	    {
	        if(response)
	        {
	            if(!PlayerHasJob(playerid, JOB_COURIER))
				{
				    return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong the su dung lenh nay vi ban khong phai la Chuyen Phat Nhanh.");
				}
				if(GetVehicleModel(GetPlayerVehicleID(playerid)) != 414 && GetVehicleModel(GetPlayerVehicleID(playerid)) != 498)
				{
				    return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban can lai xe Mule hoac Boxville.");
				}
				if(!IsPlayerInRangeOfPoint(playerid, 8.0, -63.4372, -1121.4932, 1.1103))
				{
				    return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong o noi lay hang.");
				}

				switch(listitem)
				{
				    case 0:
				    {
				        SendClientMessage(playerid, COLOR_AQUA, "Ban da chon {FF6347}Grocery supplies{33CCFF}. Su dung /deliver tai bat ky Sieu thi nao de giao hang.");
						PlayerInfo[playerid][pShipment] = BUSINESS_STORE;
	                }
	                case 1:
				    {
				        SendClientMessage(playerid, COLOR_AQUA, "Ban da chon {FF6347}Ammunition{33CCFF}. Su dung /deliver tai bat ky Cua hang vu khi nao de giao hang.");
						PlayerInfo[playerid][pShipment] = BUSINESS_GUNSHOP;
	                }
	                case 2:
				    {
				        SendClientMessage(playerid, COLOR_AQUA, "Ban da chon {FF6347}Clothing items{33CCFF}. Su dung /deliver tai bat ky Cua hang quan ao nao de giao hang.");
						PlayerInfo[playerid][pShipment] = BUSINESS_CLOTHES;
	                }
	                case 3:
				    {
				        SendClientMessage(playerid, COLOR_AQUA, "Ban da chon {FF6347}Food & drinks{33CCFF}. Su dung /deliver tai bat ky Nha hang nao de giao hang.");
						PlayerInfo[playerid][pShipment] = BUSINESS_RESTAURANT;
	                }
	                case 4:
				    {
				        SendClientMessage(playerid, COLOR_AQUA, "Ban da chon {FF6347}Beverages{33CCFF}. Su dung /deliver tai bat ky Club/Bar nao de giao hang.");
						PlayerInfo[playerid][pShipment] = BUSINESS_BARCLUB;
	                }
	                case 5:
				    {
				        SendClientMessage(playerid, COLOR_AQUA, "Ban da chon {FF6347}Tools & equipment{33CCFF}. Su dung /deliver tai bat ky Cua hang phu kien nao de giao hang.");
						PlayerInfo[playerid][pShipment] = BUSINESS_TOOLSHOP;
	                }
				}

				PlayerInfo[playerid][pLastLoad] = gettime();
	        }
	    }
	    case DIALOG_UNREADTEXTS:
	    {
	        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "DELETE FROM texts WHERE recipient_number = %i ORDER BY date DESC LIMIT 25", PlayerInfo[playerid][pPhone]);
	        mysql_tquery(connectionID, queryBuffer);

	        if(response)
	        {
				callcmd::texts(playerid, "\1");
	        }
	    }
	    case DIALOG_ATM:
	    {
	        if(response)
	        {
	            if(listitem == 0)
	            {
	                ShowDialogToPlayer(playerid, DIALOG_ATMDEPOSIT);
	            }
	            else
	            {
	                ShowDialogToPlayer(playerid, DIALOG_ATMWITHDRAW);
	            }
	        }
	    }
		case DIALOG_ATMDEPOSIT:
		{
			if(response)
	        {
	            new amount, fee;

	            if(sscanf(inputtext, "i", amount))
	            {
					return ShowDialogToPlayer(playerid, DIALOG_ATM);
	            }
	            if(amount < 1 || amount > PlayerInfo[playerid][pCash])
	            {
	                SendClientMessage(playerid, COLOR_LIGHTRED, "So tien khong du. Vui long thu lai.");
	                ShowDialogToPlayer(playerid, DIALOG_ATMDEPOSIT);
	                return 1;
	            }
	            if(amount > 1000000)
	            {
	                SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong the gui nhieu hon $1.000.000 cung mot luc.");
	                ShowDialogToPlayer(playerid, DIALOG_ATMDEPOSIT);
	                return 1;
	            }

	            PlayerInfo[playerid][pBank] += amount;
	            GivePlayerCash(playerid, -amount);

	            if(PlayerInfo[playerid][pVIPPackage] == 0)
	            {
	                fee = percent(amount, 3);

	                PlayerInfo[playerid][pBank] -= fee;
	            }

	            mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET bank = %i WHERE uid = %i", PlayerInfo[playerid][pBank], PlayerInfo[playerid][pID]);
	            mysql_tquery(connectionID, queryBuffer);

	            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s nhan nut va gui mot it tien mat vao ATM.", GetPlayerRPName(playerid));
	            SendClientMessageEx(playerid, COLOR_AQUA, "Ban da gui %s vao tai khoan cua minh. So du moi la %s.", FormatNumber(amount), FormatNumber(PlayerInfo[playerid][pBank]));

				if(fee)
				{
				    SendClientMessageEx(playerid, COLOR_WHITE, "Khoan phi tien loi 3 phan tram la %s da duoc khau tru vao tai khoan ngan hang cua ban.", FormatNumber(fee));
				    AddToTaxVault(fee);
	            }
	            else if(PlayerInfo[playerid][pVIPPackage] > 0)
	            {
					SendClientMessage(playerid, COLOR_VIP, "VIP Perk: Ban khong phai tra phi tien loi 3 phan tram vi ban la VIP!");
	            }
	        }
		}
	    case DIALOG_ATMWITHDRAW:
	    {
	        if(response)
	        {
	            new amount, fee;

	            if(sscanf(inputtext, "i", amount))
	            {
					return ShowDialogToPlayer(playerid, DIALOG_ATMWITHDRAW);
	            }
	            if(amount < 1 || amount > PlayerInfo[playerid][pBank])
	            {
	                SendClientMessage(playerid, COLOR_LIGHTRED, "So tien khong du. Vui long thu lai.");
	                ShowDialogToPlayer(playerid, DIALOG_ATMWITHDRAW);
	                return 1;
	            }
	            if(amount > 1000000)
	            {
	                SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong the rut nhieu hon $1.000.000 cung mot luc.");
	                ShowDialogToPlayer(playerid, DIALOG_ATMWITHDRAW);
	                return 1;
	            }

	            PlayerInfo[playerid][pBank] -= amount;
	            GivePlayerCash(playerid, amount);

	            if(PlayerInfo[playerid][pVIPPackage] == 0)
	            {
	                fee = percent(amount, 3);

	                PlayerInfo[playerid][pBank] -= fee;
	            }

	            mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET bank = %i WHERE uid = %i", PlayerInfo[playerid][pBank], PlayerInfo[playerid][pID]);
	            mysql_tquery(connectionID, queryBuffer);

	            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s nhan nut va rut mot so tien tu trong ATM.", GetPlayerRPName(playerid));
	            SendClientMessageEx(playerid, COLOR_AQUA, "Ban da rut %s tu tai kohoan. So du hien tai la %s.", FormatNumber(amount), FormatNumber(PlayerInfo[playerid][pBank]));

				if(fee)
				{
				    SendClientMessageEx(playerid, COLOR_WHITE, "Khoan phi tien le 3 phan tram la %s da duoc khau tru vao tai khoan ngan hang cua ban.", FormatNumber(fee));
				    AddToTaxVault(fee);
	            }
	            else if(PlayerInfo[playerid][pVIPPackage] > 0)
	            {
					SendClientMessage(playerid, COLOR_VIP, "VIP Perk: Ban khong phai tra phi tien loi 3 phan tram vi ban la VIP!");
	            }
	        }
		}
		case DIALOG_CHANGEPASS:
		{
		    if(response)
		    {
		        if(strlen(inputtext) < 4)
		        {
		            return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban can nhap mat khau lon hon 4 ky tu.");
		        }

				new
				    password[129];

				WP_Hash(password, sizeof(password), inputtext);

				mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET password = '%s', passwordchanged = '1' WHERE uid = %i", password, PlayerInfo[playerid][pID]);
				mysql_tquery(connectionID, queryBuffer);

				SendClientMessage(playerid, COLOR_WHITE, "Mat khau tai khoan cua ban da duoc thay doi thanh cong.");
    		}
		}
		case DIALOG_BUYCLOTHINGTYPE:
		{
		    if(response)
		    {
		        PlayerInfo[playerid][pMenuType] = listitem;

		        if(listitem == 0)
					ShowClothingSelectionMenu(playerid);
				else
					ShowDialogToPlayer(playerid, DIALOG_BUYCLOTHING);
		    }
		    else
		    {
		        callcmd::buy(playerid, "\1");
			}
		}
		case DIALOG_BUYCLOTHING:
		{
		    if(response)
		    {
		        PreviewClothing(playerid, listitem + PlayerInfo[playerid][pClothingIndex]);
		    }
		    else
		    {
		        ShowDialogToPlayer(playerid, DIALOG_BUYCLOTHINGTYPE);
			}
		}
		case DIALOG_CLOTHING:
		{
		    if(response)
		    {
		        if(!ClothingInfo[playerid][listitem][cExists])
		        {
		            return SendClientMessage(playerid, COLOR_LIGHTRED, "Vi tri ban da chon khong chua bat ky mat hang quan ao nao.");
		        }

		        if(ClothingInfo[playerid][listitem][cAttached]) {
					ShowPlayerDialog(playerid, DIALOG_CLOTHINGMENU, DIALOG_STYLE_LIST, ClothingInfo[playerid][listitem][cName], "Tach ra\nChinh sua\nXoa", "Chon", "Huy bo");
		        } else {
                    ShowPlayerDialog(playerid, DIALOG_CLOTHINGMENU, DIALOG_STYLE_LIST, ClothingInfo[playerid][listitem][cName], "Dinh kem\nChinh sua\nXoa", "Chon", "Huy bo");
		        }

		        PlayerInfo[playerid][pSelected] = listitem;
			}
		}
		case DIALOG_CLOTHINGMENU:
		{
		    if(response)
		    {
		        new clothingid = PlayerInfo[playerid][pSelected];

		        switch(listitem)
		        {
		            case 0:
		            {
		                if(!ClothingInfo[playerid][clothingid][cAttached])
		                {
		                    ClothingInfo[playerid][clothingid][cAttachedIndex] = GetAvailableAttachedSlot(playerid);

		                    if(ClothingInfo[playerid][clothingid][cAttachedIndex] >= 0)
		                    {
			                    ClothingInfo[playerid][clothingid][cAttached] = 1;

			                    SetPlayerAttachedObject(playerid, ClothingInfo[playerid][clothingid][cAttachedIndex], ClothingInfo[playerid][clothingid][cModel], ClothingInfo[playerid][clothingid][cBone], ClothingInfo[playerid][clothingid][cPosX], ClothingInfo[playerid][clothingid][cPosY], ClothingInfo[playerid][clothingid][cPosZ], ClothingInfo[playerid][clothingid][cRotX], ClothingInfo[playerid][clothingid][cRotY], ClothingInfo[playerid][clothingid][cRotZ],
									ClothingInfo[playerid][clothingid][cScaleX], ClothingInfo[playerid][clothingid][cScaleY], ClothingInfo[playerid][clothingid][cScaleZ]);
								SendClientMessageEx(playerid, COLOR_WHITE, "%s gan the vao khe %i/5.", ClothingInfo[playerid][clothingid][cName], ClothingInfo[playerid][clothingid][cAttachedIndex] + 1);

								mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE clothing SET attached = 1 WHERE id = %i", ClothingInfo[playerid][clothingid][cID]);
								mysql_tquery(connectionID, queryBuffer);

								for(new i = 0, count = 0; i < MAX_PLAYER_CLOTHING; i ++)
								{
								    if(ClothingInfo[playerid][i][cExists] && ClothingInfo[playerid][i][cAttached])
								    {
								        count++;

								        if(count == 5)
								        {
								            AwardAchievement(playerid, "Dress up");
										}
									}
								}
							}
							else
							{
							    SendClientMessage(playerid, COLOR_LIGHTRED, "Khong co vung dinh kem. Ban chi co the dinh kem toi da nam mat hang quan ao cung mot luc.");
		                    }
		                }
		                else
		                {
		                    RemovePlayerAttachedObject(playerid, ClothingInfo[playerid][clothingid][cAttachedIndex]);
		                    ClothingInfo[playerid][clothingid][cAttached] = 0;
		                    ClothingInfo[playerid][clothingid][cAttachedIndex] = -1;

		                    mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE clothing SET attached = 0 WHERE id = %i", ClothingInfo[playerid][clothingid][cID]);
							mysql_tquery(connectionID, queryBuffer);

							SendClientMessageEx(playerid, COLOR_WHITE, "%s tach ra va them vao kho.", ClothingInfo[playerid][clothingid][cName]);
		                }
		            }
					case 1:
					{
				    	ShowPlayerDialog(playerid, DIALOG_CLOTHINGEDIT, DIALOG_STYLE_LIST, "Bang chinh sua", "Chinh su vi tri\nThay doi noi dat", "Chon", "Huy bo");
					}
					case 2:
					{
				    	RemovePlayerAttachedObject(playerid, ClothingInfo[playerid][clothingid][cAttachedIndex]);
				    	SendClientMessageEx(playerid, COLOR_WHITE, "%s da xoa khoi kho quan ao cua ban.", ClothingInfo[playerid][clothingid][cName]);

				    	mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "DELETE FROM clothing WHERE id = %i", ClothingInfo[playerid][clothingid][cID]);
				    	mysql_tquery(connectionID, queryBuffer);

					    ClothingInfo[playerid][clothingid][cAttached] = 0;
			            ClothingInfo[playerid][clothingid][cAttachedIndex] = -1;
					    ClothingInfo[playerid][clothingid][cExists] = 0;
					    ClothingInfo[playerid][clothingid][cID] = 0;
					    ClothingInfo[playerid][clothingid][cName] = 0;
					}
				}
			}
		}
		case DIALOG_CLOTHINGEDIT:
		{
		    if(response)
		    {
		        switch(listitem)
		        {
		            case 0:
		            {
		                PlayerInfo[playerid][pEditType] = EDIT_CLOTHING;

		                if(!ClothingInfo[playerid][PlayerInfo[playerid][pSelected]][cAttached]) {
		                    SetPlayerAttachedObject(playerid, 9, ClothingInfo[playerid][PlayerInfo[playerid][pSelected]][cModel], ClothingInfo[playerid][PlayerInfo[playerid][pSelected]][cBone], ClothingInfo[playerid][PlayerInfo[playerid][pSelected]][cPosX], ClothingInfo[playerid][PlayerInfo[playerid][pSelected]][cPosY], ClothingInfo[playerid][PlayerInfo[playerid][pSelected]][cPosZ],
								ClothingInfo[playerid][PlayerInfo[playerid][pSelected]][cRotX], ClothingInfo[playerid][PlayerInfo[playerid][pSelected]][cRotY], ClothingInfo[playerid][PlayerInfo[playerid][pSelected]][cRotZ], ClothingInfo[playerid][PlayerInfo[playerid][pSelected]][cScaleX], ClothingInfo[playerid][PlayerInfo[playerid][pSelected]][cScaleY], ClothingInfo[playerid][PlayerInfo[playerid][pSelected]][cScaleZ]);

							EditAttachedObject(playerid, 9);
		                }
		                else {
		                    EditAttachedObject(playerid, ClothingInfo[playerid][PlayerInfo[playerid][pSelected]][cAttachedIndex]);
		                }

		                GameTextForPlayer(playerid, "~w~Editing Mode~n~~g~Nhan vao dia de luu~n~~r~Nhan ECS de thoat", 5000, 1);
					}
					case 1:
					{
						ShowPlayerDialog(playerid, DIALOG_CLOTHINGBONE, DIALOG_STYLE_LIST, "Chon mot vi tri moi co vat pham nay.", "Xuong song\nDau\nCanh tay trai\nCanh tay phai\nTay trai\nTay phai\nDui trai\nDui phai\nBan chan trai\nBan chan phai\nBap chan phai\nBap chan trai\nCang tay trai\nCang tay phai\nVai trai\nVai phai\nCai co\nHam", "Chon", "Huy bo");
					}
				}
			}
		}
		case DIALOG_CLOTHINGBONE:
		{
		    if(response)
		    {
		        ClothingInfo[playerid][PlayerInfo[playerid][pSelected]][cBone] = listitem + 1;

		        if(ClothingInfo[playerid][PlayerInfo[playerid][pSelected]][cAttached])
		        {
		            RemovePlayerAttachedObject(playerid, ClothingInfo[playerid][PlayerInfo[playerid][pSelected]][cAttachedIndex]);
		            SetPlayerAttachedObject(playerid, ClothingInfo[playerid][PlayerInfo[playerid][pSelected]][cAttachedIndex], ClothingInfo[playerid][PlayerInfo[playerid][pSelected]][cModel], ClothingInfo[playerid][PlayerInfo[playerid][pSelected]][cBone], ClothingInfo[playerid][PlayerInfo[playerid][pSelected]][cPosX], ClothingInfo[playerid][PlayerInfo[playerid][pSelected]][cPosY], ClothingInfo[playerid][PlayerInfo[playerid][pSelected]][cPosZ],
		                ClothingInfo[playerid][PlayerInfo[playerid][pSelected]][cRotX], ClothingInfo[playerid][PlayerInfo[playerid][pSelected]][cRotY], ClothingInfo[playerid][PlayerInfo[playerid][pSelected]][cRotZ], ClothingInfo[playerid][PlayerInfo[playerid][pSelected]][cScaleX], ClothingInfo[playerid][PlayerInfo[playerid][pSelected]][cScaleY], ClothingInfo[playerid][PlayerInfo[playerid][pSelected]][cScaleZ]);
				}

				mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE clothing SET boneid = %i WHERE id = %i", ClothingInfo[playerid][PlayerInfo[playerid][pSelected]][cBone], ClothingInfo[playerid][PlayerInfo[playerid][pSelected]][cID]);
				mysql_tquery(connectionID, queryBuffer);

				SendClientMessageEx(playerid, COLOR_WHITE, "Vi tri {00AA00}%s{FFFFFF} doi thanh '%s'.", ClothingInfo[playerid][PlayerInfo[playerid][pSelected]][cName], inputtext);
		    }
		}
		case DIALOG_BUYVEHICLE:
		{
		    if(response)
		    {
		        if(PlayerInfo[playerid][pCash] < vehicleArray[listitem][carPrice])
		        {
		            return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong co kha nang mua chiec xe nay.");
		        }

		        new
		            string[128];

		        PlayerInfo[playerid][pSelected] = listitem;

				format(string, sizeof(string), "{FFD700}Xac nhan:\nBan co chac chan mua %s voi gia {00AA00}$%i{FFD700}?", vehicleNames[vehicleArray[listitem][carModel] - 400], vehicleArray[listitem][carPrice]);
				ShowPlayerDialog(playerid, DIALOG_BUYVEHICLE2, DIALOG_STYLE_MSGBOX, "Xac nhan mua hang", string, "Co", "Khong");
			}
		}
		case DIALOG_BUYBOAT:
		{
		    if(response)
		    {
		        for(new i = 0; i < sizeof(vehicleArray); i ++)
		        {
		            if(!strcmp(vehicleArray[i][carCategory], "Boats"))
		            {
		                listitem += i;

		                if(PlayerInfo[playerid][pCash] < vehicleArray[listitem][carPrice])
				        {
				            return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong co kha nang mua phuong tien nay.");
				        }

				        new
				            string[128];

				        PlayerInfo[playerid][pSelected] = listitem;

						format(string, sizeof(string), "{FFD700}Xac nhan:\nBan co chac chan mua %s voi gia {00AA00}$%i{FFD700}?", vehicleNames[vehicleArray[listitem][carModel] - 400], vehicleArray[listitem][carPrice]);
						ShowPlayerDialog(playerid, DIALOG_BUYVEHICLE2, DIALOG_STYLE_MSGBOX, "Xac nhan mua hang", string, "Co", "Khong");
						return 1;
					}
				}
		    }
		}
		case DIALOG_BUYAIRCRAFT:
		{
		    if(response)
		    {
		        for(new i = 0; i < sizeof(vehicleArray); i ++)
		        {
		            if(!strcmp(vehicleArray[i][carCategory], "Aircraft"))
		            {
		                listitem += i;

		                if(PlayerInfo[playerid][pCash] < vehicleArray[listitem][carPrice])
				        {
				            return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong co kha nang mua phuong tien nay.");
				        }

				        new
				            string[128];

				        PlayerInfo[playerid][pSelected] = listitem;

						format(string, sizeof(string), "{FFD700}Xac nhan:\nBan co chan chan mua %s voi gia {00AA00}$%i{FFD700}?", vehicleNames[vehicleArray[listitem][carModel] - 400], vehicleArray[listitem][carPrice]);
						ShowPlayerDialog(playerid, DIALOG_BUYVEHICLE2, DIALOG_STYLE_MSGBOX, "Xac nhan mua hang", string, "Co", "Khong");
						return 1;
					}
				}
		    }
		}
		case DIALOG_BUYVEHICLE2:
		{
		    if(response)
		    {
		        if(PlayerInfo[playerid][pGangCar])
		        {
		            new
		                string[20];

		            listitem = PlayerInfo[playerid][pSelected];

		            if(PlayerInfo[playerid][pCash] < vehicleArray[listitem][carPrice])
			        {
			            return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong co kha nang mua phuong tien nay.");
			        }
			        if(PlayerInfo[playerid][pGang] == -1 || PlayerInfo[playerid][pGangRank] < 5)
					{
					    return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong phai la Rank 5+ trong bat ky bang dang nao.");
					}
					if(GetGangVehicles(PlayerInfo[playerid][pGang]) >= GetGangVehicleLimit(PlayerInfo[playerid][pGang]))
				    {
				        return SendClientMessageEx(playerid, COLOR_LIGHTRED, "Bang dang cua ban khong the co nhieu hon %i phuong tien o cap do nay.", GetGangVehicleLimit(PlayerInfo[playerid][pGang]));
				    }

		            new
						Float:x,
						Float:y,
						Float:z,
						Float:angle;

		            if(IsPlayerInRangeOfPoint(playerid, 3.0, 542.0433, -1293.5909, 17.2422))
					{
						switch(random(3))
			    	    {
			        	    case 0: x = 562.3970, y = -1283.8485, z = 17.0007, angle = 0.0000;
			            	case 1: x = 557.8670, y = -1283.9822, z = 17.0007, angle = 0.0000;
			            	case 2: x = 552.8177, y = -1284.1307, z = 17.0007, angle = 0.0000;
						}
					}
					else if(IsPlayerInRangeOfPoint(playerid, 3.0, 154.2223, -1946.3030, 5.1920))
					{
					    switch(random(4))
			    	    {
			        	    case 0: x = 138.0530, y = -1828.8923, z = -0.4000, angle = 90.0000;
			            	case 1: x = 138.0067, y = -1819.7065, z = -0.4000, angle = 90.0000;
			            	case 2: x = 137.9428, y = -1810.7821, z = -0.4000, angle = 90.0000;
			            	case 3: x = 137.0448, y = -1801.4567, z = -0.4000, angle = 90.0000;
						}
					}
					else if(IsPlayerInRangeOfPoint(playerid, 3.0, 1892.6315, -2328.6721, 13.5469))
					{
					    switch(random(3))
			    	    {
			        	    case 0: x = 1806.3048, y = -2424.4480, z = 15.0087, angle = 180.0000;
			            	case 1: x = 1847.3726, y = -2428.7100, z = 15.0087, angle = 180.0000;
			            	case 2: x = 1891.6610, y = -2433.3047, z = 15.0087, angle = 180.0000;
						}
					}

					mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "INSERT INTO vehicles (modelid, price, pos_x, pos_y, pos_z, pos_a, gangid, respawndelay) VALUES(%i, %i, '%f', '%f', '%f', '%f', %i, 600)", vehicleArray[listitem][carModel], vehicleArray[listitem][carPrice], x, y, z, angle, PlayerInfo[playerid][pGang]);
					mysql_tquery(connectionID, queryBuffer);

                    AddPointMoney(POINT_AUTOEXPORT, percent(vehicleArray[listitem][carPrice], 3));
			        mysql_tquery(connectionID, "SELECT * FROM vehicles WHERE id = LAST_INSERT_ID()", "OnQueryFinished", "ii", THREAD_LOAD_VEHICLES, -1);

			        format(string, sizeof(string), "~r~-$%i", vehicleArray[listitem][carPrice]);
		    	    GameTextForPlayer(playerid, string, 5000, 1);

					GivePlayerCash(playerid, -vehicleArray[listitem][carPrice]);
					PlayerInfo[playerid][pGangCar] = 0;

			        SendClientMessageEx(playerid, COLOR_GREEN, "%s da mua cho bang dang cua ban voi gia $%i. /ganghelp de xem lenh.", vehicleNames[vehicleArray[listitem][carModel] - 400], vehicleArray[listitem][carPrice]);
		    	    Log_Write("log_give", "%s (uid: %i) da mua %s cho %s voi gia $%i.", GetPlayerNameEx(playerid), PlayerInfo[playerid][pID], vehicleNames[vehicleArray[listitem][carModel] - 400], GangInfo[PlayerInfo[playerid][pGang]][gName], vehicleArray[listitem][carPrice]);
		        }
		        else
		        {
			        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "SELECT COUNT(*) FROM vehicles WHERE ownerid = %i", PlayerInfo[playerid][pID]);
			        mysql_tquery(connectionID, queryBuffer, "OnPlayerAttemptBuyVehicle", "ii", playerid, PlayerInfo[playerid][pSelected]);
				}
			}
		}
  		case DIALOG_SPAWNCAR:
		{
		    if(response)
		    {
				mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "SELECT * FROM vehicles WHERE ownerid = %i LIMIT %i, 1", PlayerInfo[playerid][pID], listitem);
				mysql_tquery(connectionID, queryBuffer, "OnPlayerSpawnVehicle", "ii", playerid, false);
		    }
		}
		case DIALOG_DESPAWNCAR:
		{
		    if(response)
		    {
		        new count;

		        foreach(new i: Vehicle)
			 	{
			 	    if((VehicleInfo[i][vID] > 0 && IsVehicleOwner(playerid, i)) && (count++ == listitem))
			 	    {
			 	        if(IsVehicleOccupied(i) && GetVehicleDriver(i) != playerid)
			 	        {
			 	            return SendClientMessage(playerid, COLOR_LIGHTRED, "Phuong tien nay bi chiem.");
			 	        }

			 	        SendClientMessageEx(playerid, COLOR_AQUA, "{FF6347}%s{33CCFF} cua ban nam o %s da duoc cat.", GetVehicleName(i), GetVehicleZoneName(i));
            			DespawnVehicle(i);
            			return 1;
			 	    }
		        }
		    }
		}
		case DIALOG_CARSTORAGE:
		{
		    if(response)
		    {
		        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "SELECT id FROM vehicles WHERE ownerid = %i LIMIT %i, 1", PlayerInfo[playerid][pID], listitem);
		        mysql_tquery(connectionID, queryBuffer, "OnPlayerUseCarStorage", "i", playerid);
			}
		}
		case DIALOG_FINDCAR:
		{
		    if(response)
		    {
		        new count, garageid;

		        foreach(new i: Vehicle)
			 	{
			 	    if((VehicleInfo[i][vID] > 0 && IsVehicleOwner(playerid, i)) && (count++ == listitem))
			 	    {
                        PlayerInfo[playerid][pCP] = CHECKPOINT_MISC;

			            if((garageid = GetVehicleGarage(i)) >= 0)
			            {
			                SetPlayerCheckpoint(playerid, GarageInfo[garageid][gPosX], GarageInfo[garageid][gPosY], GarageInfo[garageid][gPosZ], 3.0);
			                SendClientMessageEx(playerid, COLOR_YELLOW, "Your %s nam trong Garage. Diem checkpoint duoc danh dau tai vi tri Garage.", GetVehicleName(i));
			            }
			            else
			            {
			                new
			                    Float:x,
			                    Float:y,
			                    Float:z;

			                GetVehiclePos(i, x, y, z);
			                SetPlayerCheckpoint(playerid, x, y, z, 3.0);
			                SendClientMessageEx(playerid, COLOR_YELLOW, "%s cua ban nam o %s. Checkpoint duoc danh dau tai vi tri.", GetVehicleName(i), GetZoneName(x, y, z));
			            }

			            return 1;
		            }
				}
			}
		}
		case DIALOG_BIZINTERIOR:
		{
		    if(response)
		    {
		        new businessid = PlayerInfo[playerid][pSelected];

		        foreach(new i : Player)
		        {
		            if(GetInsideBusiness(i) == businessid)
		            {
						SetPlayerPos(i, bizInteriorArray[listitem][intX], bizInteriorArray[listitem][intY], bizInteriorArray[listitem][intZ]);
						SetPlayerFacingAngle(i, bizInteriorArray[listitem][intA]);
						SetPlayerInterior(i, bizInteriorArray[listitem][intID]);
						SetCameraBehindPlayer(i);
		            }
		        }

                BusinessInfo[businessid][bIntX] = bizInteriorArray[listitem][intX];
                BusinessInfo[businessid][bIntY] = bizInteriorArray[listitem][intY];
                BusinessInfo[businessid][bIntZ] = bizInteriorArray[listitem][intZ];
                BusinessInfo[businessid][bIntA] = bizInteriorArray[listitem][intA];
			    BusinessInfo[businessid][bInterior] = bizInteriorArray[listitem][intID];

			    mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE businesses SET int_x = '%f', int_y = '%f', int_z = '%f', int_a = '%f', interior = %i WHERE id = %i", BusinessInfo[businessid][bIntX], BusinessInfo[businessid][bIntY], BusinessInfo[businessid][bIntZ], BusinessInfo[businessid][bIntA], BusinessInfo[businessid][bInterior], BusinessInfo[businessid][bID]);
			    mysql_tquery(connectionID, queryBuffer);

				ReloadBusiness(businessid);
			    SendClientMessageEx(playerid, COLOR_AQUA, "Ban da thay doi noi that cua doanh nghiep %i thanh %s.", businessid, bizInteriorArray[listitem][intName]);
		    }
		}
		case DIALOG_FACTIONLOCKER:
		{
		    if((response) && PlayerInfo[playerid][pFaction] >= 0 && IsPlayerInRangeOfLocker(playerid, PlayerInfo[playerid][pFaction]))
		    {
				switch(FactionInfo[PlayerInfo[playerid][pFaction]][fType])
				{
					case FACTION_POLICE, FACTION_MEDIC, FACTION_FEDERAL, FACTION_ARMY:
					{
					    if(listitem == 0) // Toggle duty
					    {
					        if(!PlayerInfo[playerid][pDuty])
					        {
					            if(IsLawEnforcement(playerid))
					            {
					                SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s lay thiet bi canh sat trong tu do.", GetPlayerRPName(playerid));
								}
								else if(FactionInfo[PlayerInfo[playerid][pFaction]][fType] == FACTION_MEDIC)
					            {
					                SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s lay do y te cua ho trong tu do.", GetPlayerRPName(playerid));
								}

                                PlayerInfo[playerid][pDuty] = 1;

								SetPlayerHealth(playerid, 100.0);
								SetScriptArmour(playerid, 100.0);
							}
							else
							{
							    PlayerInfo[playerid][pDuty] = 0;
							    //ResetPlayerWeaponsEx(playerid);

							    //SetScriptArmour(playerid, 0.0);
								SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s lay phu hieu ra va cat lai thiet bi cua ho vao tu.", GetPlayerRPName(playerid));
							}
						}
						else if(listitem == 1) // Equipment
						{
						    ShowDialogToPlayer(playerid, DIALOG_FACTIONEQUIPMENT);
		    				/*if(IsLawEnforcement(playerid))
		    				{
						    	ShowPlayerDialog(playerid, DIALOG_FACTIONEQUIPMENT, DIALOG_STYLE_LIST, "Equipment", "Kevlar Vest\nMedkit\nNitestick\nSpraycan\nDesert Eagle\nShotgun\nMP5\nM4\nSPAS-12\nSniper Rifle", "Select", "Huy bo");
							}
							else
							{
							    ShowPlayerDialog(playerid, DIALOG_FACTIONEQUIPMENT, DIALOG_STYLE_LIST, "Equipment", "Kevlar Vest\nMedkit\nFire Extinguisher\nDesert Eagle\nPainkillers", "Select", "Huy bo");
							}*/
						}
						else if(listitem == 2) // Uniforms
						{
						    if(!GetFactionSkinCount(PlayerInfo[playerid][pFaction]))
						    {
						        return SendClientMessage(playerid, COLOR_LIGHTRED, "Khong co thiet lap dong phuc nao cho to chuc cua ban.");
							}
							if(PlayerInfo[playerid][pClothes] >= 0)
							{
							    PlayerInfo[playerid][pSkin] = PlayerInfo[playerid][pClothes];
							    PlayerInfo[playerid][pClothes] = -1;

							    mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET skin = %i, clothes = -1 WHERE uid = %i", PlayerInfo[playerid][pSkin], PlayerInfo[playerid][pID]);
							    mysql_tquery(connectionID, queryBuffer);

							    SetPlayerSkin(playerid, PlayerInfo[playerid][pSkin]);
							    SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s tro lai trang phuc cu cua ho.", GetPlayerRPName(playerid));
							}
							else
							{
	                            PlayerInfo[playerid][pSkinSelected] = -1;
							    ShowPlayerDialog(playerid, DIALOG_FACTIONSKINS, DIALOG_STYLE_MSGBOX, "Lua chon dong phuc", "Nhan {00AA00}>> Tiep{A9C4E4} de xem nhung bo dong phuc co san.", ">> Tiep", "Xac nhan");
							}
						}
						else if(listitem == 3 && FactionInfo[PlayerInfo[playerid][pFaction]][fType] != FACTION_MEDIC)
						{
                            ShowCopClothingMenu(playerid);
						}
					}
					case FACTION_GOVERNMENT, FACTION_NEWS:
					{
					    if(listitem == 0) // Equipment
					    {
					        ShowDialogToPlayer(playerid, DIALOG_FACTIONEQUIPMENT);
					        /*if(FactionInfo[PlayerInfo[playerid][pFaction]][fType] == FACTION_GOVERNMENT)
          					{
          					    ShowPlayerDialog(playerid, DIALOG_FACTIONEQUIPMENT, DIALOG_STYLE_LIST, "Equipment", "Kevlar Vest\nMedkit\nDesert Eagle\nShotgun\nMP5\nM4\nSPAS-12", "Select", "Huy bo");
							}
							else
							{
							    ShowPlayerDialog(playerid, DIALOG_FACTIONEQUIPMENT, DIALOG_STYLE_LIST, "Equipment", "Kevlar Vest\nMedkit\nCamera", "Select", "Huy bo");
							}*/
						}
						else if(listitem == 1) // Uniforms
						{
						    if(!GetFactionSkinCount(PlayerInfo[playerid][pFaction]))
						    {
						        return SendClientMessage(playerid, COLOR_LIGHTRED, "Khong co thiet lap dong phuc nao cho to chuc cua ban.");
							}
							if(PlayerInfo[playerid][pClothes] >= 0)
							{
							    PlayerInfo[playerid][pSkin] = PlayerInfo[playerid][pClothes];
							    PlayerInfo[playerid][pClothes] = -1;

							    mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET skin = %i, clothes = -1 WHERE uid = %i", PlayerInfo[playerid][pSkin], PlayerInfo[playerid][pID]);
							    mysql_tquery(connectionID, queryBuffer);

							    SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s tro lai trang phuc cu cua ho.", GetPlayerRPName(playerid));
							}
							else
							{
							    PlayerInfo[playerid][pSkinSelected] = -1;
						    	ShowPlayerDialog(playerid, DIALOG_FACTIONSKINS, DIALOG_STYLE_MSGBOX, "Lua chon dong phuc", "Nhan {00AA00}>> Tiep{A9C4E4} de xem nhung bo dong phuc co san.", ">> Tiep", "Xac nhan");
							}
						}
					}
					case FACTION_HITMAN:
					{
					    if(listitem == 0) // Order weapons
					    {
					        ShowPlayerDialog(playerid, DIALOG_FACTIONEQUIPMENT, DIALOG_STYLE_LIST, "Lay vu khi", "Ao giap ($1,000)\nKnife ($1,500)\nSilenced pistol ($1,000)\nShotgun ($1,500)\nDesert Eagle ($2,000)\nMP5 ($2,500)\nCountry rifle ($4,000)\nAK-47 ($6,000)\nM4 ($8,000)\nSPAS-12 ($8,500)\nSniper rifle ($9,000)\nBom ($15,000)", "Lay", "Huy bo");
						}
						else if(listitem == 1) // Change clothes
						{
						    ShowPlayerDialog(playerid, DIALOG_HITMANCLOTHES, DIALOG_STYLE_INPUT, "Thay doi dong phuc", "Vui long nhap ID skin ban muon thay doi.\n(( Danh sach skin: http://wiki.sa-mp.com/wiki/Skins:All ))", "Gui", "Huy bo");
						}
					}
		        }
		    }
		}
		case DIALOG_FACTIONEQUIPMENT:
		{
		    if((response) && PlayerInfo[playerid][pFaction] >= 0 && IsPlayerInRangeOfLocker(playerid, PlayerInfo[playerid][pFaction]))
		    {
				switch(FactionInfo[PlayerInfo[playerid][pFaction]][fType])
				{
					/*case FACTION_POLICE, FACTION_FEDERAL, FACTION_ARMY:
					{
					    switch(listitem)
					    {
					        case 0:
					        {
					            SetScriptArmour(playerid, 100.0);
					            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s grabs a kevlar vest from the locker and puts it on.", GetPlayerRPName(playerid));
					        }
					        case 1:
					        {
					            SetPlayerHealth(playerid, 100.0);
					            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s grabs a medkit from the locker and opens it.", GetPlayerRPName(playerid));
					        }
					        case 2:
					        {
                                GivePlayerWeaponEx(playerid, 3);
					            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s grabs a nitestick from the locker.", GetPlayerRPName(playerid));
					        }
					        case 3:
					        {
                                GivePlayerWeaponEx(playerid, 41);
					            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s grabs a can of pepper spray from the locker.", GetPlayerRPName(playerid));
					        }
					        case 4:
					        {
								GivePlayerWeaponEx(playerid, 24);
					            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s grabs a Desert Eagle from the locker.", GetPlayerRPName(playerid));
					        }
					        case 5:
					        {
					            GivePlayerWeaponEx(playerid, 25);
					            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s grabs a Shotgun from the locker.", GetPlayerRPName(playerid));
					        }
					        case 6:
					        {
					            GivePlayerWeaponEx(playerid, 29);
					            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s grabs an MP5 from the locker.", GetPlayerRPName(playerid));
					        }
					        case 7:
					        {
					            GivePlayerWeaponEx(playerid, 31);
					            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s grabs an M4 from the locker.", GetPlayerRPName(playerid));
					        }
					        case 8:
					        {
					            GivePlayerWeaponEx(playerid, 27);
					            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s grabs a SPAS-12 from the locker.", GetPlayerRPName(playerid));
					        }
					        case 9:
					        {
					            GivePlayerWeaponEx(playerid, 34);
					            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s grabs a Sniper Rifle from the locker.", GetPlayerRPName(playerid));
					        }
						}
					}
					case FACTION_MEDIC:
					{
					    switch(listitem)
					    {
					        case 0:
					        {
					            SetScriptArmour(playerid, 100.0);
					            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s grabs a kevlar vest from the locker and puts it on.", GetPlayerRPName(playerid));
					        }
					        case 1:
					        {
					            SetPlayerHealth(playerid, 100.0);
					            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s grabs a medkit from the locker and opens it.", GetPlayerRPName(playerid));
					        }
					        case 2:
					        {
                                GivePlayerWeaponEx(playerid, 42);
					            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s grabs a fire extinguisher from the locker.", GetPlayerRPName(playerid));
					        }
					        case 3:
					        {
                 				GivePlayerWeaponEx(playerid, 24);
					            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s grabs a Desert Eagle from the locker.", GetPlayerRPName(playerid));
					        }
					        case 4:
					        {
					            PlayerInfo[playerid][pPainkillers] = 5;
					            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s grabs a five pack of painkillers from the locker.", GetPlayerRPName(playerid));

					            mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET painkillers = %i WHERE uid = %i", PlayerInfo[playerid][pPainkillers], PlayerInfo[playerid][pID]);
					            mysql_tquery(connectionID, queryBuffer);
					        }
						}
					}
					case FACTION_GOVERNMENT:
					{
					    switch(listitem)
					    {
					        case 0:
					        {
					            SetScriptArmour(playerid, 100.0);
					            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s grabs a kevlar vest from the locker and puts it on.", GetPlayerRPName(playerid));
					        }
					        case 1:
					        {
					            SetPlayerHealth(playerid, 100.0);
					            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s grabs a medkit from the locker and opens it.", GetPlayerRPName(playerid));
					        }
					        case 2:
					        {
					            GivePlayerWeaponEx(playerid, 24);
					            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s grabs a Desert Eagle from the locker.", GetPlayerRPName(playerid));
					        }
					        case 3:
					        {
					            GivePlayerWeaponEx(playerid, 25);
					            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s grabs a Shotgun from the locker.", GetPlayerRPName(playerid));
					        }
					        case 4:
					        {
					            GivePlayerWeaponEx(playerid, 29);
					            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s grabs an MP5 from the locker.", GetPlayerRPName(playerid));
					        }
					        case 5:
					        {
					            GivePlayerWeaponEx(playerid, 31);
					            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s grabs an M4 from the locker.", GetPlayerRPName(playerid));
					        }
					        case 6:
					        {
					            GivePlayerWeaponEx(playerid, 27);
					            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s grabs a SPAS-12 from the locker.", GetPlayerRPName(playerid));
					        }
					        case 7:
					        {
					            GivePlayerWeaponEx(playerid, 34);
					            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s grabs a Sniper Rifle from the locker.", GetPlayerRPName(playerid));
					        }
					    }
					}
					case FACTION_NEWS:
					{
					    switch(listitem)
					    {
					        case 0:
					        {
					            SetScriptArmour(playerid, 100.0);
					            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s grabs a kevlar vest from the locker and puts it on.", GetPlayerRPName(playerid));
					        }
					        case 1:
					        {
					            SetPlayerHealth(playerid, 100.0);
					            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s grabs a medkit from the locker and opens it.", GetPlayerRPName(playerid));
					        }
					        case 2:
					        {
					            GivePlayerWeaponEx(playerid, 43);
					            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s grabs a digital camera from the locker.", GetPlayerRPName(playerid));
					        }
					    }
					}*/
					case FACTION_HITMAN:
					{
					    switch(listitem)
					    {
					        case 0:
							{
							    if(PlayerInfo[playerid][pCash] < 1000)
							    {
							        return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong the mua duoc vu khi nay.");
					            }

					            GivePlayerCash(playerid, -1000);
					            SetScriptArmour(playerid, 100.0);

					            SendClientMessageEx(playerid, COLOR_AQUA, "** You ordered a kevlar vest for $1,000.");
					            GameTextForPlayer(playerid, "~r~-$1000", 5000, 1);
					    	}
							case 1:
							{
							    if(PlayerInfo[playerid][pCash] < 1500)
							    {
							        return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong the mua duoc vu khi nay.");
					            }

					            GivePlayerWeaponEx(playerid, 4);
					            GivePlayerCash(playerid, -1500);

					            SendClientMessageEx(playerid, COLOR_AQUA, "** You ordered a knife for $1,500.");
					            GameTextForPlayer(playerid, "~r~-$1500", 5000, 1);
					    	}
					    	case 2:
							{
							    if(PlayerInfo[playerid][pCash] < 1000)
							    {
							        return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong the mua duoc vu khi nay.");
					            }

								GivePlayerWeaponEx(playerid, 23);
					            GivePlayerCash(playerid, -1000);

					            SendClientMessageEx(playerid, COLOR_AQUA, "** You ordered a silenced pistol for $1,000.");
					            GameTextForPlayer(playerid, "~r~-$1000", 5000, 1);
					    	}
					    	case 3:
							{
							    if(PlayerInfo[playerid][pCash] < 1500)
							    {
							        return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong the mua duoc vu khi nay.");
					            }

								GivePlayerWeaponEx(playerid, 25);
					            GivePlayerCash(playerid, -1500);

					            SendClientMessageEx(playerid, COLOR_AQUA, "** You ordered a shotgun for $1,500.");
					            GameTextForPlayer(playerid, "~r~-$1500", 5000, 1);
					    	}
					    	case 4:
							{
							    if(PlayerInfo[playerid][pCash] < 2000)
							    {
							        return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong the mua duoc vu khi nay.");
					            }

								GivePlayerWeaponEx(playerid, 24);
					            GivePlayerCash(playerid, -2000);

					            SendClientMessageEx(playerid, COLOR_AQUA, "** You ordered a Desert Eagle for $2,000.");
					            GameTextForPlayer(playerid, "~r~-$2000", 5000, 1);
					    	}
					    	case 5:
							{
							    if(PlayerInfo[playerid][pCash] < 2500)
							    {
							        return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong the mua duoc vu khi nay.");
					            }

								GivePlayerWeaponEx(playerid, 29);
					            GivePlayerCash(playerid, -2500);

					            SendClientMessageEx(playerid, COLOR_AQUA, "** You ordered an MP5 for $2,500.");
					            GameTextForPlayer(playerid, "~r~-$2500", 5000, 1);
					    	}
					    	case 6:
							{
							    if(PlayerInfo[playerid][pCash] < 4000)
							    {
							        return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong the mua duoc vu khi nay.");
					            }

								GivePlayerWeaponEx(playerid, 33);
					            GivePlayerCash(playerid, -4000);

					            SendClientMessageEx(playerid, COLOR_AQUA, "** You ordered a country rifle for $4,000.");
					            GameTextForPlayer(playerid, "~r~-$4000", 5000, 1);
					    	}
					    	case 7:
							{
							    if(PlayerInfo[playerid][pCash] < 6000)
							    {
							        return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong the mua duoc vu khi nay.");
					            }

								GivePlayerWeaponEx(playerid, 30);
					            GivePlayerCash(playerid, -6000);

					            SendClientMessageEx(playerid, COLOR_AQUA, "** You ordered an AK-47 for $6,000.");
					            GameTextForPlayer(playerid, "~r~-$6000", 5000, 1);
					    	}
					    	case 8:
							{
							    if(PlayerInfo[playerid][pCash] < 8000)
							    {
							        return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong the mua duoc vu khi nay.");
					            }

								GivePlayerWeaponEx(playerid, 31);
					            GivePlayerCash(playerid, -8000);

					            SendClientMessageEx(playerid, COLOR_AQUA, "** You ordered an M4 for $8,000.");
					            GameTextForPlayer(playerid, "~r~-$8000", 5000, 1);
					    	}
					    	case 9:
							{
							    if(PlayerInfo[playerid][pCash] < 8500)
							    {
							        return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong the mua duoc vu khi nay.");
					            }

								GivePlayerWeaponEx(playerid, 27);
					            GivePlayerCash(playerid, -8500);

					            SendClientMessageEx(playerid, COLOR_AQUA, "** You ordered a SPAS-12 for $8,500.");
					            GameTextForPlayer(playerid, "~r~-$8500", 5000, 1);
					    	}
					    	case 10:
							{
							    if(PlayerInfo[playerid][pCash] < 9000)
							    {
							        return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong the mua duoc vu khi nay.");
					            }

								GivePlayerWeaponEx(playerid, 34);
					            GivePlayerCash(playerid, -9000);

					            SendClientMessageEx(playerid, COLOR_AQUA, "** You ordered a sniper rifle for $9,000.");
					            GameTextForPlayer(playerid, "~r~-$9000", 5000, 1);
					    	}
					    	case 11:
							{
							    if(PlayerInfo[playerid][pCash] < 15000)
							    {
							        return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong the mua duoc vu khi nay.");
					            }
					            if(PlayerInfo[playerid][pBombs] > 3)
					            {
					                return SendClientMessage(playerid, COLOR_LIGHTRED, "You have more than 3 bombs. You can't buy anymore.");
								}

					            PlayerInfo[playerid][pBombs]++;
					            GivePlayerCash(playerid, -15000);

								mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET bombs = %i WHERE uid = %i", PlayerInfo[playerid][pBombs], PlayerInfo[playerid][pID]);
								mysql_tquery(connectionID, queryBuffer);

					            SendClientMessageEx(playerid, COLOR_AQUA, "** You ordered a bomb for $15,000. /plantbomb to place the bomb.");
					            GameTextForPlayer(playerid, "~r~-$15000", 5000, 1);
					    	}
					    }
					}
					default:
					{
					    new amount, weapon, locker = GetNearbyLocker(playerid);
						if(strfind(inputtext, "Kevlar Vest", true) != -1)
						{
						    amount = LockerInfo[locker][locKevlar][1];
                            if(PlayerInfo[playerid][pCash] < amount)
						    {
						        return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong the mua duoc vu khi nay.");
				            }

							SetScriptArmour(playerid, 100.0);
				            GivePlayerCash(playerid, -amount);

				            SendClientMessageEx(playerid, COLOR_AQUA, "** Ban da nhan duoc mot chiec ao giap voi gia $%i.", amount);
						}
						else if(strfind(inputtext, "Medkit", true) != -1)
						{
						    amount = LockerInfo[locker][locMedKit][1];
                            if(PlayerInfo[playerid][pCash] < amount)
						    {
						        return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong the mua duoc vu khi nay.");
				            }

							SetPlayerHealth(playerid, 100.0);
				            GivePlayerCash(playerid, -amount);

				            SendClientMessageEx(playerid, COLOR_AQUA, "** Ban da nhan duoc mot medkit voi gia $%i.", amount);
						}
						else if(strfind(inputtext, "Nitestick", true) != -1)
						{
							amount = LockerInfo[locker][locNitestick][1]; weapon = 3;
						    if(PlayerInfo[playerid][pCash] < amount)
						    {
						        return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong the mua duoc vu khi nay.");
				            }

							GivePlayerWeaponEx(playerid, weapon);
				            GivePlayerCash(playerid, -amount);

				            SendClientMessageEx(playerid, COLOR_AQUA, "** Ban da nhan duoc mot %s voi gia $%i.", GetWeaponNameEx(weapon), amount);
						}
						else if(strfind(inputtext, "Mace", true) != -1)
						{
							amount = LockerInfo[locker][locMace][1]; weapon = 41;
						    if(PlayerInfo[playerid][pCash] < amount)
						    {
						        return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong the mua duoc vu khi nay.");
				            }

							GivePlayerWeaponEx(playerid, weapon);
				            GivePlayerCash(playerid, -amount);

				            SendClientMessageEx(playerid, COLOR_AQUA, "** Ban da nhan duoc mot %s voi gia $%i.", GetWeaponNameEx(weapon), amount);
						}
                        else if(strfind(inputtext, "Deagle", true) != -1)
						{
							amount = LockerInfo[locker][locDeagle][1]; weapon = 24;
						    if(PlayerInfo[playerid][pCash] < amount)
						    {
						        return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong the mua duoc vu khi nay.");
				            }

							GivePlayerWeaponEx(playerid, weapon);
				            GivePlayerCash(playerid, -amount);

				            SendClientMessageEx(playerid, COLOR_AQUA, "** Ban da nhan duoc mot %s voi gia $%i.", GetWeaponNameEx(weapon), amount);
						}
						else if(strfind(inputtext, "Shotgun", true) != -1)
						{
							amount = LockerInfo[locker][locShotgun][1]; weapon = 25;
						    if(PlayerInfo[playerid][pCash] < amount)
						    {
						        return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong the mua duoc vu khi nay.");
				            }

							GivePlayerWeaponEx(playerid, weapon);
				            GivePlayerCash(playerid, -amount);

				            SendClientMessageEx(playerid, COLOR_AQUA, "** Ban da nhan duoc mot %s voi gia $%i.", GetWeaponNameEx(weapon), amount);
						}
						else if(strfind(inputtext, "MP5", true) != -1)
						{
							amount = LockerInfo[locker][locMP5][1]; weapon = 29;
						    if(PlayerInfo[playerid][pCash] < amount)
						    {
						        return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong the mua duoc vu khi nay.");
				            }

							GivePlayerWeaponEx(playerid, weapon);
				            GivePlayerCash(playerid, -amount);

				            SendClientMessageEx(playerid, COLOR_AQUA, "** Ban da nhan duoc mot %s voi gia $%i.", GetWeaponNameEx(weapon), amount);
						}
						else if(strfind(inputtext, "M4", true) != -1)
						{
							amount = LockerInfo[locker][locM4][1]; weapon = 31;
						    if(PlayerInfo[playerid][pCash] < amount)
						    {
						        return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong the mua duoc vu khi nay.");
				            }

							GivePlayerWeaponEx(playerid, weapon);
				            GivePlayerCash(playerid, -amount);

				            SendClientMessageEx(playerid, COLOR_AQUA, "** Ban da nhan duoc mot %s voi gia $%i.", GetWeaponNameEx(weapon), amount);
						}
						else if(strfind(inputtext, "SPAS-12", true) != -1)
						{
							amount = LockerInfo[locker][locSpas12][1]; weapon = 27;
						    if(PlayerInfo[playerid][pCash] < amount)
						    {
						        return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong the mua duoc vu khi nay.");
				            }

							GivePlayerWeaponEx(playerid, weapon);
				            GivePlayerCash(playerid, -amount);

				            SendClientMessageEx(playerid, COLOR_AQUA, "** Ban da nhan duoc mot %s voi gia $%i.", GetWeaponNameEx(weapon), amount);
						}
						else if(strfind(inputtext, "Sniper", true) != -1)
						{
							amount = LockerInfo[locker][locSniper][1]; weapon = 34;
						    if(PlayerInfo[playerid][pCash] < amount)
						    {
						        return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong the mua duoc vu khi nay.");
				            }

							GivePlayerWeaponEx(playerid, weapon);
				            GivePlayerCash(playerid, -amount);

				            SendClientMessageEx(playerid, COLOR_AQUA, "** Ban da nhan duoc mot %s voi gia $%i.", GetWeaponNameEx(weapon), amount);
						}
						else if(strfind(inputtext, "Camera", true) != -1)
						{
							amount = LockerInfo[locker][locCamera][1]; weapon = 43;
						    if(PlayerInfo[playerid][pCash] < amount)
						    {
						        return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong the mua duoc vu khi nay.");
				            }

							GivePlayerWeaponEx(playerid, weapon);
				            GivePlayerCash(playerid, -amount);

				            SendClientMessageEx(playerid, COLOR_AQUA, "** Ban da nhan duoc mot %s voi gia $%i.", GetWeaponNameEx(weapon), amount);
						}
						else if(strfind(inputtext, "Fire Extinguisher", true) != -1)
						{
							amount = LockerInfo[locker][locFireExt][1]; weapon = 42;
						    if(PlayerInfo[playerid][pCash] < amount)
						    {
						        return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong the mua duoc vu khi nay.");
				            }

							GivePlayerWeaponEx(playerid, weapon);
				            GivePlayerCash(playerid, -amount);

				            SendClientMessageEx(playerid, COLOR_AQUA, "** Ban da nhan duoc mot %s voi gia $%i.", GetWeaponNameEx(weapon), amount);
						}
						else if(strfind(inputtext, "Painkillers", true) != -1)
						{
							amount = LockerInfo[locker][locPainKillers][1];
						    if(PlayerInfo[playerid][pCash] < amount)
						    {
						        return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong the mua duoc vu khi nay.");
				            }

                            PlayerInfo[playerid][pPainkillers] = 5;
				            GivePlayerCash(playerid, -amount);

				            SendClientMessageEx(playerid, COLOR_AQUA, "** Ban nhan duoc painkillers voi gia $%i.", amount);
						}
					}
				}
			}
		}
		case DIALOG_FACTIONSKINS:
		{
		    if(PlayerInfo[playerid][pFaction] >= 0 && IsPlayerInRangeOfLocker(playerid, PlayerInfo[playerid][pFaction]))
		    {
		        if(response)
		        {
					new index = PlayerInfo[playerid][pSkinSelected] + 1;

					if(index >= MAX_FACTION_SKINS)
					{
					    // When the player is shown the dialog for the first time, their skin isn't changed until they click >> Next.
					    SetPlayerSkin(playerid, PlayerInfo[playerid][pSkin]);
					    PlayerInfo[playerid][pSkinSelected] = -1;
					}
					else
					{
					    // Find the next skin in the array.
						for(new i = index; i < MAX_FACTION_SKINS; i ++)
						{
						    if(FactionInfo[PlayerInfo[playerid][pFaction]][fSkins][i] != 0)
						    {
						        SetPlayerSkin(playerid, FactionInfo[PlayerInfo[playerid][pFaction]][fSkins][i]);
						        PlayerInfo[playerid][pSkinSelected] = i;
						        break;
					        }
		                }

		                if(index == PlayerInfo[playerid][pSkinSelected] + 1)
		                {
		                    // Looks like there was no skin found. So, we'll go back to the very first valid skin in the skin array.
		                    for(new i = 0; i < MAX_FACTION_SKINS; i ++)
							{
						    	if(FactionInfo[PlayerInfo[playerid][pFaction]][fSkins][i] != 0)
						    	{
		                            SetPlayerSkin(playerid, FactionInfo[PlayerInfo[playerid][pFaction]][fSkins][i]);
						        	PlayerInfo[playerid][pSkinSelected] = i;
						        	break;
								}
							}
		                }
		            }

		            ShowPlayerDialog(playerid, DIALOG_FACTIONSKINS, DIALOG_STYLE_MSGBOX, "Lua chon dong phuc", "Nhan {00AA00}>> Tiep{A9C4E4} de xem nhung bo dong phuc co san.", ">> Tiep", "Xac nhan");
		        }
		        else
		        {
		            PlayerInfo[playerid][pClothes] = PlayerInfo[playerid][pSkin];
		            PlayerInfo[playerid][pSkin] = GetPlayerSkin(playerid);
		            PlayerInfo[playerid][pSkinSelected] = -1;

		            mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET skin = %i, clothes = %i WHERE uid = %i", PlayerInfo[playerid][pSkin], PlayerInfo[playerid][pClothes], PlayerInfo[playerid][pID]);
		            mysql_tquery(connectionID, queryBuffer);

		            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s lay dong phuc ra khoi tu va mac vao.", GetPlayerRPName(playerid));
				}
		    }
		}
		case DIALOG_HITMANCLOTHES:
		{
		    if((response) && PlayerInfo[playerid][pFaction] >= 0 && IsPlayerInRangeOfLocker(playerid, PlayerInfo[playerid][pFaction]))
		    {
				new skinid;

		    	if(sscanf(inputtext, "i", skinid))
				{
					return ShowPlayerDialog(playerid, DIALOG_HITMANCLOTHES, DIALOG_STYLE_INPUT, "Thay doi trang phuc", "Vui long nhap ID Skin ban muon thay.\n(( Danh sach: http://wiki.sa-mp.com/wiki/Skins:All ))", "Gui", "Huy bo");
		        }
		        if(!(0 <= skinid <= 311))
		        {
		            SendClientMessage(playerid, COLOR_LIGHTRED, "Skin khong hop le.");
		            return ShowPlayerDialog(playerid, DIALOG_HITMANCLOTHES, DIALOG_STYLE_INPUT, "Thay doi trang phuc", "Vui long nhap ID Skin ban muon thay.\n(( Danh sach: http://wiki.sa-mp.com/wiki/Skins:All ))", "Gui", "Huy bo");
		        }

		        SetScriptSkin(playerid, skinid);
				GameTextForPlayer(playerid, "~w~Thay doi trang phuc mien phi", 3000, 3);
		    }
		}
		case DIALOG_MDC:
		{
		    if((response) && IsLawEnforcement(playerid))
		    {
		        switch(listitem)
		        {
		            case 0:
		            {
		                static string[2048], count;

		                string = "Nghi Pham\tVi tri\tCap do truy na";

		                count = 0;

						foreach(new i : Player)
						{
						    if(PlayerInfo[i][pWantedLevel] > 0)
						    {
						        format(string, sizeof(string), "%s\n%s\t%s\t%i/6", string, GetPlayerRPName(i), GetPlayerZoneName(i), PlayerInfo[i][pWantedLevel]);
						        count++;
						    }
						}

						if(!count)
						{
						    return SendClientMessage(playerid, COLOR_LIGHTRED, "Hien khong co nghi pham bi truy na dang truc tuyen");
						}

						ShowPlayerDialog(playerid, DIALOG_MDCWANTED, DIALOG_STYLE_TABLIST_HEADERS, "Nghi pham truy na", string, "Theo doi", "Huy bo");
					}
					case 1:
					{
					    ShowPlayerDialog(playerid, DIALOG_PLAYERLOOKUP, DIALOG_STYLE_INPUT, "Tra cuu nguoi choi", "Nhap ten day du cua nguoi choi de tra cuu:", "Gui", "Huy bo");
					}
					case 2:
					{
					    ShowPlayerDialog(playerid, DIALOG_VEHICLELOOKUP1, DIALOG_STYLE_INPUT, "Tra cuu phuong tien", "Nhap ID cua xe de tra cuu.\n(( Ban co the tim ra ID cua xe bang cach su dung /dl. ))", "Gui", "Huy bo");
					}
				}
			}
		}
		case DIALOG_MDCWANTED:
		{
		    if((response) && IsLawEnforcement(playerid))
		    {
		        foreach(new i : Player)
				{
    				if(!strcmp(GetPlayerRPName(i), inputtext))
    				{
    				    new
    				        Float:x,
    				        Float:y,
    				        Float:z;

    				    GetPlayerPosEx(i, x, y, z);

    				    PlayerInfo[playerid][pCP] = CHECKPOINT_MISC;

    				    SetPlayerCheckpoint(playerid, x, y, z, 3.0);
    				    SendClientMessage(playerid, COLOR_WHITE, "Tram kiem soat duoc danh dau tai vi tri cuoi cung cua nghi pham.");
						return 1;
					}
				}

				SendClientMessage(playerid, COLOR_LIGHTRED, "Nghi pham da [Kicked/Dissconec].");
			}
		}
		case DIALOG_PLAYERLOOKUP:
		{
		    if((response) && IsLawEnforcement(playerid))
		    {
		        new username[MAX_PLAYER_NAME];

		        if(sscanf(inputtext, "s[24]", username))
		        {
		            return ShowPlayerDialog(playerid, DIALOG_PLAYERLOOKUP, DIALOG_STYLE_INPUT, "Tra cuu nguoi choi", "Nhap ten day du cua nguoi choi de check:", "Dong y", "Huy bo");
				}

				mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "SELECT uid, gioi tinh, tuoi, muc do truy na, toi ac, bi bat, giay phep lai xe tu nguoi choi = '%e'", username);
				mysql_tquery(connectionID, queryBuffer, "MDC_PlayerLookup", "is", playerid, username);
			}
		}
		case DIALOG_MDCPLAYER1:
		{
		    if((response) && IsLawEnforcement(playerid))
		    {
		        ShowPlayerDialog(playerid, DIALOG_MDCPLAYER2, DIALOG_STYLE_LIST, "Tuy chon", "Hien thi cac khoan phi hoat dong\nXoa cac khoan phi", "Chon", "Huy");
			}
		}
		case DIALOG_MDCPLAYER2:
		{
		    if((response) && IsLawEnforcement(playerid))
		    {
		        switch(listitem)
		        {
		            case 0:
		            {
		                mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "Chon * FROM charges WHERE uid = %i", PlayerInfo[playerid][pSelected]);
		                mysql_tquery(connectionID, queryBuffer, "MDC_ListCharges", "i", playerid);
		            }
		            case 1:
		            {
		                mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "SELECT username FROM users WHERE uid = %i", PlayerInfo[playerid][pSelected]);
		                mysql_tquery(connectionID, queryBuffer, "MDC_ClearCharges", "i", playerid);
		            }
				}
		    }
		}
		case DIALOG_MDCCHARGES:
		{
		    ShowPlayerDialog(playerid, DIALOG_MDCPLAYER2, DIALOG_STYLE_LIST, "Tuy chon", "Hien thi cac khoan phi hoat dong\nXoa cac khoan phi", "Chon", "Huy");
		}
		case DIALOG_VEHICLELOOKUP1:
		{
		    if((response) && IsLawEnforcement(playerid))
		    {
			    new vehicleid, string[128];

			    if(sscanf(inputtext, "i", vehicleid))
			    {
		    	    return ShowPlayerDialog(playerid, DIALOG_VEHICLELOOKUP1, DIALOG_STYLE_INPUT, "Tra cuu phuong tien", "Nhap ID phuong tien de tra cuu.\n(( Ban co the tim ID phuong tien bang cach /dl. ))", "Dong y", "Huy");
				}
				if(!IsValidVehicle(vehicleid) || !VehicleInfo[vehicleid][vOwnerID])
				{
				    SendClientMessage(playerid, COLOR_LIGHTRED, "ID xe duoc tra cuu khong thuoc chu so huu nao.");
			    	return ShowPlayerDialog(playerid, DIALOG_VEHICLELOOKUP1, DIALOG_STYLE_INPUT, "Tra cuu phuong tien", "Nhap ID phuong tien de tra cuu.\n(( Ban co the tim ID phuong tien bang cach /dl. ))", "Dong y", "Huy");
				}

				PlayerInfo[playerid][pSelected] = vehicleid;

				format(string, sizeof(string), "Name: %s\nOwner: %s\nTickets: $%i\nLocation: %s", GetVehicleName(vehicleid), VehicleInfo[vehicleid][vOwner], VehicleInfo[vehicleid][vTickets], GetVehicleZoneName(vehicleid));
            	ShowPlayerDialog(playerid, DIALOG_VEHICLELOOKUP2, DIALOG_STYLE_MSGBOX, "Tra cuu phuong tien", string, "Theo doi", "Huy");
			}
		}
		case DIALOG_VEHICLELOOKUP2:
		{
			if((response) && IsLawEnforcement(playerid))
		    {
				new garageid, vehicleid = PlayerInfo[playerid][pSelected];

				if((garageid = GetVehicleGarage(vehicleid)) >= 0)
				{
				    SetPlayerCheckpoint(playerid, GarageInfo[garageid][gPosX], GarageInfo[garageid][gPosY], GarageInfo[garageid][gPosZ], 3.0);
				    SendClientMessage(playerid, COLOR_WHITE, "Tram kiem soat duoc danh dau phuong tien.");
				}
				else
				{
				    new
						Float:x,
						Float:y,
						Float:z;

                    SendClientMessage(playerid, COLOR_WHITE, "Tram kiem soat duoc danh dau tai vi tri cua cung cua phuong tien.");

					GetVehiclePos(vehicleid, x, y, z);
					SetPlayerCheckpoint(playerid, x, y, z, 3.0);
				}

    			PlayerInfo[playerid][pCP] = CHECKPOINT_MISC;
			}
		}
		case DIALOG_FACTIONPAY1:
		{
		    if(response)
		    {
		        PlayerInfo[playerid][pSelected] = listitem;
		        ShowPlayerDialog(playerid, DIALOG_FACTIONPAY2, DIALOG_STYLE_INPUT, "PAYCHECK", "Nhap so tien luong moi cho muc Rank nay:", "Dong y", "Quay lai");
		    }
		}
		case DIALOG_FACTIONPAY2:
		{
		    if(GetFactionType(playerid) != FACTION_NONE)
		    {
		        if(response)
		        {
		            new amount, factionid = PlayerInfo[playerid][pFaction], rankid = PlayerInfo[playerid][pSelected];

		            if(sscanf(inputtext, "i", amount))
		            {
		                return ShowPlayerDialog(playerid, DIALOG_FACTIONPAY2, DIALOG_STYLE_INPUT, "PAYCHECK", "Nhap so tien luong moi cho muc Rank nay:", "Dong y", "Quay lai");
					}
					if(!(1 <= amount <= 50000))
					{
					    SendClientMessage(playerid, COLOR_LIGHTRED, "Khoan tien luong chi nam trong 10$ - 50.000$.");
					    return ShowPlayerDialog(playerid, DIALOG_FACTIONPAY2, DIALOG_STYLE_INPUT, "PAYCHECK", "Nhap so tien luong moi cho muc Rank nay:", "Dong y", "Quay lai");
					}
					if(GetTotalFactionPay(factionid) - FactionInfo[factionid][fPaycheck][rankid] + amount > FactionInfo[factionid][fFund])
					{
						return SendClientMessageEx(playerid, COLOR_LIGHTRED, "Faction cua ban chi co ngan sach $%i con lai! co the dieu chinh o do.", (FactionInfo[factionid][fFund] - GetTotalFactionPay(factionid)));
					}

					FactionInfo[factionid][fPaycheck][rankid] = amount;

				    mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "INSERT INTO factionpay VALUES(%i, %i, %i) ON DUPLICATE KEY UPDATE amount = %i", factionid, rankid, amount, amount);
				    mysql_tquery(connectionID, queryBuffer);

					SendClientMessageEx(playerid, COLOR_AQUA, "Ban da dat tien luong cho Rank %i den $%i.", rankid, amount);
				    Log_Write("log_faction", "%s (uid: %i) set %s's (id: %i) tien luong cho Rank %i to $%i.", GetPlayerNameEx(playerid), PlayerInfo[playerid][pID], FactionInfo[factionid][fName], factionid, rankid, amount);
		        }

				ShowDialogToPlayer(playerid, DIALOG_FACTIONPAY1);
		    }
		}
		case DIALOG_PHONEBOOK:
		{
		    if(response)
		    {
		        if(!strcmp(inputtext, ">> trang ke tiep", true))
		        {
		            PlayerInfo[playerid][pPage]++;
		            ShowDialogToPlayer(playerid, DIALOG_PHONEBOOK);
		        }
		        else if(!strcmp(inputtext, "<< Go back", true) && PlayerInfo[playerid][pPage] > 1)
		        {
		            PlayerInfo[playerid][pPage]--;
		            ShowDialogToPlayer(playerid, DIALOG_PHONEBOOK);
		        }
		    }
		}
		case DIALOG_CREATEZONE:
		{
		    if((response) && (PlayerInfo[playerid][pAdmin] >= 8 || PlayerInfo[playerid][pGangMod] || PlayerInfo[playerid][pDynamicAdmin]))
		    {
		        PlayerInfo[playerid][pMinX] = 0.0;
		        PlayerInfo[playerid][pMinY] = 0.0;
		        PlayerInfo[playerid][pMaxX] = 0.0;
		        PlayerInfo[playerid][pMaxY] = 0.0;

		        if(PlayerInfo[playerid][pZoneType] == ZONETYPE_LAND)
				{
			        PlayerInfo[playerid][pZoneCreation] = ZONETYPE_LAND;
			        SendClientMessage(playerid, COLOR_WHITE, "Dat cua ban nam o trong hinh vuong hoac hinh chu nhat. /confirm de thiet lap 4 diem ranh gioi.");
				}
				else if(PlayerInfo[playerid][pZoneType] == ZONETYPE_TURF)
				{
			        PlayerInfo[playerid][pZoneCreation] = ZONETYPE_TURF;
			        SendClientMessage(playerid, COLOR_WHITE, "Your turf needs to be within a square or rectangle. /confirm to set the four boundary points.");
				}
		    }
		}
		case DIALOG_CONFIRMZONE:
		{
		    if(response)
		    {
		        if(PlayerInfo[playerid][pZoneCreation] == ZONETYPE_LAND)
		        {
			        for(new i = 0; i < MAX_LANDS; i ++)
					{
					    if(!LandInfo[i][lExists])
					    {
					        new
					            Float:minx = PlayerInfo[playerid][pMinX],
					            Float:miny = PlayerInfo[playerid][pMinY],
					            Float:maxx = PlayerInfo[playerid][pMaxX],
					            Float:maxy = PlayerInfo[playerid][pMaxY],
					            Float:z;

	            			GetPlayerPos(playerid, z, z, z);

					        if(minx > maxx)
							{
	                            PlayerInfo[playerid][pMinX] = maxx;
	                            PlayerInfo[playerid][pMaxX] = minx;
					        }
					        if(miny > maxy)
							{
					            PlayerInfo[playerid][pMinY] = maxy;
					            PlayerInfo[playerid][pMaxY] = miny;
					        }

							mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "INSERT INTO lands (price, min_x, min_y, max_x, max_y, height) VALUES(%i, '%f', '%f', '%f', '%f', '%f')", PlayerInfo[playerid][pLandCost], PlayerInfo[playerid][pMinX], PlayerInfo[playerid][pMinY], PlayerInfo[playerid][pMaxX], PlayerInfo[playerid][pMaxY], z);
							mysql_tquery(connectionID, queryBuffer, "OnAdminCreateLand", "iiifffff", playerid, i, PlayerInfo[playerid][pLandCost], PlayerInfo[playerid][pMinX], PlayerInfo[playerid][pMinY], PlayerInfo[playerid][pMaxX], PlayerInfo[playerid][pMaxY], z);
	      					CancelZoneCreation(playerid);
							return 1;
						}
					}

					SendClientMessage(playerid, COLOR_LIGHTRED, "Cac khu da da day, /baocao de yeu cau nha phat trien cap nhat.");
					CancelZoneCreation(playerid);
		    	}
		    	else if(PlayerInfo[playerid][pZoneCreation] == ZONETYPE_TURF)
		    	{
           			for(new i = 0; i < MAX_TURFS; i ++)
					{
					    if(!TurfInfo[i][tExists])
					    {
					        new
					            Float:minx = PlayerInfo[playerid][pMinX],
					            Float:miny = PlayerInfo[playerid][pMinY],
					            Float:maxx = PlayerInfo[playerid][pMaxX],
					            Float:maxy = PlayerInfo[playerid][pMaxY],
					            Float:z;

	            			GetPlayerPos(playerid, z, z, z);

					        if(minx > maxx)
							{
	                            PlayerInfo[playerid][pMinX] = maxx;
	                            PlayerInfo[playerid][pMaxX] = minx;
					        }
					        if(miny > maxy)
							{
					            PlayerInfo[playerid][pMinY] = maxy;
					            PlayerInfo[playerid][pMaxY] = miny;
					        }

							mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "INSERT INTO turfs (id, name, type, min_x, min_y, max_x, max_y, height) VALUES(%i, '%e', %i, '%f', '%f', '%f', '%f', '%f')", i, PlayerInfo[playerid][pTurfName], PlayerInfo[playerid][pTurfType], PlayerInfo[playerid][pMinX], PlayerInfo[playerid][pMinY], PlayerInfo[playerid][pMaxX], PlayerInfo[playerid][pMaxY], z);
							mysql_tquery(connectionID, queryBuffer, "OnAdminCreateTurf", "iisifffff", playerid, i, PlayerInfo[playerid][pTurfName], PlayerInfo[playerid][pTurfType], PlayerInfo[playerid][pMinX], PlayerInfo[playerid][pMinY], PlayerInfo[playerid][pMaxX], PlayerInfo[playerid][pMaxY], z);
	      					CancelZoneCreation(playerid);
							return 1;
						}
					}

					SendClientMessage(playerid, COLOR_LIGHTRED, "Cac khu TURFS da day, /baocao de yeu cau nha phat trien cap nhat.");
					CancelZoneCreation(playerid);
		    	}
			}
			else
			{
			    CancelZoneCreation(playerid);

		        if(PlayerInfo[playerid][pZoneType] == ZONETYPE_LAND)
				{
					SendClientMessage(playerid, COLOR_WHITE, "Khu dat cua ban chi o trong hinh vuong hoac hinh chu nhat. /confirm de dat ranh gioi 4 huong.");
					SendClientMessage(playerid, COLOR_WHITE, "Note: You can use /landcancel to exit land creation mode.");
					PlayerInfo[playerid][pZoneCreation] = ZONETYPE_LAND;
				}
				else if(PlayerInfo[playerid][pZoneType] == ZONETYPE_TURF)
				{
					SendClientMessage(playerid, COLOR_WHITE, "TURFS cua ban chi o trong hinh vuong hoac hinh chu nhat. /confirm de dat ranh gioi 4 huong.");
					SendClientMessage(playerid, COLOR_WHITE, "Note: ban co the /turfscancel de huy bo.");
					PlayerInfo[playerid][pZoneCreation] = ZONETYPE_TURF;
				}
			}
		}
		case DIALOG_LANDBUILDTYPE:
		{
		    new landid = GetNearbyLand(playerid);

		    if(landid == -1 || !HasLandPerms(playerid, landid))
			{
				return 0;
			}

	   	    if(response)
	        {
				PlayerInfo[playerid][pMenuType] = listitem;
				ShowDialogToPlayer(playerid, DIALOG_LANDBUILD1);
			}
		    else
		    {
		        ShowDialogToPlayer(playerid, DIALOG_LANDMENU);
			}
		}
        case DIALOG_LANDBUILD1:
	    {
	        new landid = GetNearbyLand(playerid);

		    if(landid == -1 || !HasLandPerms(playerid, landid))
			{
				return 0;
			}

	   	    if(response)
	        {
	            switch(PlayerInfo[playerid][pMenuType])
	            {
	                case 0: // Model selection
	                {
						PlayerInfo[playerid][pCategory] = listitem;
						ShowObjectSelectionMenu(playerid, MODEL_SELECTION_LANDOBJECTS);
	                }
	                case 1:
	                {
						PlayerInfo[playerid][pCategory] = listitem;
						ShowDialogToPlayer(playerid, DIALOG_LANDBUILD2);
					}
     	       }
			}
	        else
	        {
	            ShowDialogToPlayer(playerid, DIALOG_LANDBUILDTYPE);
			}
	    }
	    case DIALOG_LANDBUILD2:
	    {
	        new landid = GetNearbyLand(playerid);

		    if(landid == -1 || !HasLandPerms(playerid, landid))
			{
				return 0;
			}

	        if(response)
	        {
                PurchaseLandObject(playerid, landid, listitem + PlayerInfo[playerid][pFurnitureIndex]);
			}
			else
			{
			    ShowDialogToPlayer(playerid, DIALOG_LANDBUILD1);
			}
	    }
	    case DIALOG_LANDMENU:
	    {
	        new landid = GetNearbyLand(playerid);

	        if(landid == -1 || !HasLandPerms(playerid, landid))
	        {
	            return 1;
	        }

	        if(response)
	        {
		        switch(listitem)
		        {
		            case 0:
		            {
		                mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "SELECT COUNT(*) FROM landobjects WHERE landid = %i", LandInfo[landid][lID]);
						mysql_tquery(connectionID, queryBuffer, "OnQueryFinished", "ii", THREAD_COUNT_LANDOBJECTS, playerid);
					}
					case 1:
					{
					    ShowPlayerDialog(playerid, DIALOG_LANDEDITOBJECT, DIALOG_STYLE_INPUT, "Edit object", "Vui long nhap ID Object:\nBan co the tim ID Object bang cach bat danh sach ID Object.", "Dong y", "Quay lai");
					}
					case 2:
					{
						if(!LandInfo[landid][lLabels])
					    {
					        LandInfo[landid][lLabels] = 1;
					        SendClientMessage(playerid, COLOR_AQUA, "Bay gio ban co the thay nhung object xuat hien tren Land cua ban.");
					    }
					    else
					    {
					        LandInfo[landid][lLabels] = 0;
					        SendClientMessage(playerid, COLOR_AQUA, "Ban se khong thay nhung object xuat hien tren Land cua ban");
					    }

					    ReloadAllLandObjects(landid);
					    ShowDialogToPlayer(playerid, DIALOG_LANDMENU);
					}
					case 3:
					{
					    PlayerInfo[playerid][pPage] = 1;
					    ShowDialogToPlayer(playerid, DIALOG_LANDOBJECTS);
					}
					case 4:
					{
					    ShowPlayerDialog(playerid, DIALOG_LANDSELLALL, DIALOG_STYLE_MSGBOX, "Xoa objects", "Tuy chon nay se ban cac object cua ban. Ban se nhan duoc\n75 phan tram tong chi phi cua tat ca objects cua ban.\n\nNhan {FF6347}Dong y{A9C4E4} de xac dinh.", "Dong y", "Quay lai");
					}
					case 5:
					{
					    if(LandInfo[landid][lLevel] >= 3)
					    {
					        return SendClientMessage(playerid, COLOR_LIGHTRED, "Land cua ban khong the nang cap duoc nua.");
					    }

					    new
					        string[224];

					    format(string, sizeof(string), "Ban da nang cap Land cua minh len cap %i/5.\n\nNang cap nay ban se mat {00AA00}$100,000{A9C4E4} va mo ra %i nhieu\nobjects nhieu khu trong cho Land cua ban.\n\nBan co chac ban muon nang cap Land?", LandInfo[landid][lLevel] + 1, GetLandObjectCapacity(LandInfo[landid][lLevel] + 1) - GetLandObjectCapacity(LandInfo[landid][lLevel]));
						ShowPlayerDialog(playerid, DIALOG_LANDUPGRADE, DIALOG_STYLE_MSGBOX, "Upgrade land", string, "Co", "No");
					}
					case 6:
					{
					    ShowPlayerDialog(playerid, DIALOG_LANDPERMS, DIALOG_STYLE_INPUT, "Quyen", "Vui long nhap ID cua nguoi choi de giao quyen:", "Dong y", "Quay lai");
					}
   				}
	        }
	    }
	    case DIALOG_LANDUPGRADE:
	    {
	        new landid = GetNearbyLand(playerid);

	        if(landid == -1 || !HasLandPerms(playerid, landid))
	        {
	            return 1;
	        }

	        if(response)
	        {
	            if(LandInfo[landid][lLevel] < 5)
            	{
	                if(PlayerInfo[playerid][pCash] < 100000)
	                {
	                    return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong du kha nang nang cap Land cua minh.");
	                }

	                LandInfo[landid][lLevel]++;

	                mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE lands SET level = level + 1 WHERE id = %i", LandInfo[landid][lID]);
	                mysql_tquery(connectionID, queryBuffer);

	                GivePlayerCash(playerid, -100000);
	                GameTextForPlayer(playerid, "~r~-$100000", 5000, 1);
	                SendClientMessageEx(playerid, COLOR_GREEN, "Ban da chi tra $100,000 cho viec nang cap Land len cap do %i/5. Land cua ban bay gio co toi da %i objects.", LandInfo[landid][lLevel], GetLandObjectCapacity(LandInfo[landid][lLevel]));
	            }
	        }
	        else
	        {
	            ShowDialogToPlayer(playerid, DIALOG_LANDMENU);
	        }
	    }
	    case DIALOG_LANDEDITOBJECT:
	    {
	        new landid = GetNearbyLand(playerid);

	        if(landid == -1 || !HasLandPerms(playerid, landid))
	        {
	            return 1;
	        }

	        if(response)
	        {
	            new objectid;

	            if(sscanf(inputtext, "i", objectid))
	            {
	                return ShowPlayerDialog(playerid, DIALOG_LANDEDITOBJECT, DIALOG_STYLE_INPUT, "Chinh sua object", "Vui long nhap ID Object ma ban muon chinh sua:\nYBan co the tim ID Object bang cach Togle labels.", "Dong y", "Quay lai");
				}
				if(!IsValidDynamicObject(objectid) || Streamer_GetExtraInt(objectid, E_OBJECT_TYPE) != E_OBJECT_LAND)
				{
				    SendClientMessage(playerid, COLOR_LIGHTRED, "Khong xac dinh object. Ban co the tim object's ID bang cach bat labels.");
				    return ShowPlayerDialog(playerid, DIALOG_LANDEDITOBJECT, DIALOG_STYLE_INPUT, "Chinh sua object", "Vui long nhap ID Object ma ban muon chinh sua:\nBan co the tim ID Object bang cach Togle labels.", "Dong y", "Quay lai");
		        }
		        if(Streamer_GetExtraInt(objectid, E_OBJECT_EXTRA_ID) != LandInfo[landid][lID])
		        {
		            SendClientMessage(playerid, COLOR_LIGHTRED, "Invalid object. This land object is not apart of your land.");
		            return ShowPlayerDialog(playerid, DIALOG_LANDEDITOBJECT, DIALOG_STYLE_INPUT, "Chinh sua object", "Vui long nhap ID Object ma ban muon chinh sua:\nBan co the tim ID Object bang cach Togle labels.", "Dong y", "Quay lai");
		        }

		        PlayerInfo[playerid][pSelected] = objectid;
				ShowDialogToPlayer(playerid, DIALOG_LANDOBJECTMENU);
	        }
	        else
	        {
	            ShowDialogToPlayer(playerid, DIALOG_LANDMENU);
			}
		}
	    case DIALOG_LANDOBJECTMENU:
	    {
            new landid = GetNearbyLand(playerid);

	        if(landid == -1 || !HasLandPerms(playerid, landid))
	        {
	            return 1;
	        }

	        if(response)
	        {
	            new objectid = PlayerInfo[playerid][pSelected];

	            if(!strcmp(inputtext, " Chinh sua object"))
	            {
	                if(Streamer_GetExtraInt(objectid, E_OBJECT_OPENED))
					{
					    return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong the chinh sua gate cua ban khi no mo.");
					}
	    	        PlayerInfo[playerid][pEditType] = EDIT_LAND_OBJECT;
		    	    PlayerInfo[playerid][pEditObject] = objectid;
	        		PlayerInfo[playerid][pObjectLand] = landid;

					EditDynamicObject(playerid, objectid);
	    		    GameTextForPlayer(playerid, "~w~Chinh sua Mode~n~~g~Nhap chuot vao disk de luu~n~~r~Nhan ESC de huy bo", 5000, 1);
	            }
	            else if(!strcmp(inputtext, "Chinh sua vi tri cua gate"))
	            {
	                if(Streamer_GetExtraInt(objectid, E_OBJECT_OPENED))
					{
					    return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong the chinh sua gate cua ban khi no mo.");
					}

			        PlayerInfo[playerid][pEditType] = EDIT_LAND_GATE_MOVE;
			        PlayerInfo[playerid][pEditObject] = objectid;
			        PlayerInfo[playerid][pObjectLand] = landid;

					EditDynamicObject(playerid, objectid);
					SendClientMessage(playerid, COLOR_WHITE, "Bay gio ban da chinh sua vi tri cua gate.");
			        GameTextForPlayer(playerid, "~w~Chinh sua Mode~n~~g~Nhap chuot vao disk de luu~n~~r~Nhan ESC de huy bo", 5000, 1);
	            }
	            else if(!strcmp(inputtext, "Duplicate object"))
	            {
	                PlayerInfo[playerid][pSelected] = objectid;
	                PlayerInfo[playerid][pObjectLand] = landid;
                    mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "SELECT COUNT(*) FROM landobjects WHERE landid = %i", LandInfo[landid][lID]);
        			mysql_tquery(connectionID, queryBuffer, "OnQueryFinished", "ii", THREAD_DUPLICATE_LANDOBJ, playerid);

	            }
	            else if(!strcmp(inputtext, "Sell object"))
	            {
	                PlayerInfo[playerid][pSelected] = objectid;

			        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "SELECT name, price FROM landobjects WHERE id = %i", Streamer_GetExtraInt(objectid, E_OBJECT_INDEX_ID));
			        mysql_tquery(connectionID, queryBuffer, "OnQueryFinished", "ii", THREAD_SELL_LANDOBJECT, playerid);
				}
			}
			else
			{
			    ShowDialogToPlayer(playerid, DIALOG_LANDMENU);

			    //ShowPlayerDialog(playerid, DIALOG_LANDEDITOBJECT, DIALOG_STYLE_INPUT, "Edit object", "Please enter the object ID of the object to edit:\nYou can find out the ID of objects by toggling labels in the menu.", "Chap nhan", "Huy");
			}
		}
		case DIALOG_LANDOBJECTS:
		{
		    if(response)
		    {
		        if(!strcmp(inputtext, ">> trang ke tiep", true))
		        {
		            PlayerInfo[playerid][pPage]++;
		            ShowDialogToPlayer(playerid, DIALOG_LANDOBJECTS);
		        }
		        else if(!strcmp(inputtext, "<< Go Huy", true) && PlayerInfo[playerid][pPage] > 1)
		        {
		            PlayerInfo[playerid][pPage]--;
		            ShowDialogToPlayer(playerid, DIALOG_LANDOBJECTS);
		        }
		        else
		        {
		            new objectid = strval(inputtext);

		            if(IsValidDynamicObject(objectid) && Streamer_GetExtraInt(objectid, E_OBJECT_TYPE) == E_OBJECT_LAND)
		            {
			            PlayerInfo[playerid][pSelected] = objectid;
						ShowDialogToPlayer(playerid, DIALOG_LANDOBJECTMENU);
					}
		        }
		    }
		    else
		    {
		        ShowDialogToPlayer(playerid, DIALOG_LANDMENU);
			}
		}
		case DIALOG_LANDSELLALL:
		{
		    new landid = GetNearbyLand(playerid);

	        if(landid == -1 || !HasLandPerms(playerid, landid))
	        {
	            return 1;
	        }

	        if(response)
	        {
		    	mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "SELECT price FROM landobjects WHERE landid = %i", LandInfo[landid][lID]);
        		mysql_tquery(connectionID, queryBuffer, "OnQueryFinished", "ii", THREAD_CLEAR_LANDOBJECTS, playerid);
			}
			else
			{
			    ShowDialogToPlayer(playerid, DIALOG_LANDMENU);
			}
		}
		/*case DIALOG_LANDPERMS:
		{
		    new landid = GetNearbyLand(playerid), targetid;

	        if(landid == -1 || !HasLandPerms(playerid, landid))
	        {
	            return 1;
	        }

	        if(response)
	        {
				if(sscanf(inputtext, "u", targetid))
				{
					return ShowPlayerDialog(playerid, DIALOG_LANDPERMS, DIALOG_STYLE_INPUT, "Permissions", "Vui long nhap ID hoac ten cua nguoi choi de trao quyen:", "Chap nhan", "Huy");
		        }
		        if(!IsPlayerConnected(targetid))
		        {
		            SendClientMessage(playerid, COLOR_LIGHTRED, "Nguoi choi do da bi mat ket noi.");
		            return ShowPlayerDialog(playerid, DIALOG_LANDPERMS, DIALOG_STYLE_INPUT, "Permissions", "Vui long nhap ID hoac ten cua nguoi choi de trao quyen:", "Chap nhan", "Huy");
		        }
		        if(targetid == playerid)
				{
					SendClientMessage(playerid, COLOR_LIGHTRED, "You can't give permissions to yourself.");
					return ShowPlayerDialog(playerid, DIALOG_LANDPERMS, DIALOG_STYLE_INPUT, "Permissions", "Vui long nhap ID hoac ten cua nguoi choi de trao quyen:", "Chap nhan", "Huy");
				}

		        if(PlayerInfo[targetid][pLandPerms] == landid)
		        {
		            PlayerInfo[targetid][pLandPerms] = -1;

		            SendClientMessageEx(targetid, COLOR_AQUA, "%s has removed your access to their land's objects.", GetPlayerRPName(playerid));
					SendClientMessageEx(playerid, COLOR_AQUA, "You have removed %s's access to your land's objects.", GetPlayerRPName(targetid));
				}
				else
				{
				    PlayerInfo[targetid][pLandPerms] = landid;

		            SendClientMessageEx(targetid, COLOR_AQUA, "%s has granted you access to their land's objects.", GetPlayerRPName(playerid));
					SendClientMessageEx(playerid, COLOR_AQUA, "You have granted %s access to your land's objects.", GetPlayerRPName(targetid));
				}
			}

			ShowDialogToPlayer(playerid, DIALOG_LANDMENU);
		}*/
		case DIALOG_LANDPERMS:
		{
		    new landid = GetNearbyLand(playerid), targetid;

	        if(landid == -1 || !IsLandOwner(playerid, landid))
	        {
	            return 1;
	        }

	        if(response)
	        {
				if(sscanf(inputtext, "u", targetid))
				{
					return ShowPlayerDialog(playerid, DIALOG_LANDPERMS, DIALOG_STYLE_INPUT, "Quyen", "Vui long nhap ID hoac ten cua nguoi choi de trao quyen:", "Dong y", "Quay lai");
		        }
		        if(!IsPlayerConnected(targetid))
		        {
		            SendClientMessage(playerid, COLOR_LIGHTRED, "Nguoi choi do da bi mat ket noi.");
		            return ShowPlayerDialog(playerid, DIALOG_LANDPERMS, DIALOG_STYLE_INPUT, "Quyen", "Vui long nhap ID hoac ten cua nguoi choi de trao quyen:", "Dong y", "Quay lai");
		        }
		        if(targetid == playerid)
				{
					SendClientMessage(playerid, COLOR_LIGHTRED, "You can't give permissions to yourself.");
					return ShowPlayerDialog(playerid, DIALOG_LANDPERMS, DIALOG_STYLE_INPUT, "Quyen", "Vui long nhap ID hoac ten cua nguoi choi de trao quyen:", "Dong y", "Quay lai");
				}

		        if(PlayerInfo[targetid][pLandPerms] == landid)
		        {
		            PlayerInfo[targetid][pLandPerms] = -1;

		            SendClientMessageEx(targetid, COLOR_AQUA, "%s da xoa object tren Land cua ho.", GetPlayerRPName(playerid));
					SendClientMessageEx(playerid, COLOR_AQUA, "Ban da xoa %s's object tren Land.", GetPlayerRPName(targetid));
					mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET landkeys = %i WHERE uid = %i", LandInfo[landid][lID], PlayerInfo[targetid][pID]);
					mysql_tquery(connectionID, queryBuffer);
				}
				else if(PlayerInfo[targetid][pLandPerms] == -1)
				{
				    PlayerInfo[targetid][pLandPerms] = landid;

		            SendClientMessageEx(targetid, COLOR_AQUA, "%s da trao cho ban quyen chinh sua Objects tren Land cua ho.", GetPlayerRPName(playerid));
					SendClientMessageEx(playerid, COLOR_AQUA, "Ban da cap %s quyen chinh sua cua minh cho ho.", GetPlayerRPName(targetid));
					mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET landkeys = 0 WHERE uid = %i", PlayerInfo[targetid][pID]);
					mysql_tquery(connectionID, queryBuffer);
				}
				else
				{
				    SendClientMessage(playerid, COLOR_AQUA, "Nguoi choi do da co quyen chinh sua Land cua ai do. (/droplandkeys)");
				}
			}

			ShowDialogToPlayer(playerid, DIALOG_LANDMENU);
		}
		case DIALOG_MP3PLAYER:
		{
      		if(response)
		    {
		        switch(listitem)
		        {
		            case 0:
		            {
		                ShowPlayerDialog(playerid, DIALOG_MP3URL, DIALOG_STYLE_INPUT, "Custom URL", "Vui long nhap URL bai hat ma ban thich:", "Dong y", "Huy bo");
		            }
		            case 1:
		            {
                  		ShowPlayerDialog(playerid, DIALOG_MP3MUSIC, DIALOG_STYLE_INPUT, "Uploaded Music", "Vui long ten bai hat .mp3 de phat:\n(Su dung /music de hien thi danh sach nhung bai hat HOT o thanh pho.)", "Dong y", "Huy bo");
		            }
		            case 2:
		            {
						if(!radioConnectionID)
						{
						    return SendClientMessage(playerid, COLOR_LIGHTRED, "Trong co so du lieu khong kha dung.");
						}

						ShowDialogToPlayer(playerid, DIALOG_MP3RADIO);
					}
      			     case 3:
 			       	  {
						switch(PlayerInfo[playerid][pMusicType])
						{
      						case MUSIC_MP3PLAYER:
							{
        					   	SetMusicStream(MUSIC_MP3PLAYER, playerid, "");
	                			SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da tat MP3 cua ho.", GetPlayerRPName(playerid));
							}
							case MUSIC_BOOMBOX:
							{
							    SetMusicStream(MUSIC_BOOMBOX, playerid, "");
								SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da tat boombox cua ho.", GetPlayerRPName(playerid));
							}
							case MUSIC_VEHICLE:
							{
							    if(IsPlayerInAnyVehicle(playerid))
							    {
								    SetMusicStream(MUSIC_VEHICLE, GetPlayerVehicleID(playerid), "");
									SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da tat radio trong xe.", GetPlayerRPName(playerid));
								}
							}
						}
					}
					case 4:
					{
						 if(PlayerInfo[playerid][pVIPPackage] < 1)
						 {
							 return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban phai la VIP moi co the su dung");
						 }
						 ShowPlayerDialog(playerid, DIALOG_VIPMUSIC, DIALOG_STYLE_INPUT, "VIP Uploaded Music", "Vui long nhap ten bai hai .mp3 de phat:", "Dong y", "Huy bo");
					}
          		}
			}
		}
		case DIALOG_MP3MUSIC:
		{
		    if(response)
		    {
		        new url[128];

		        if(isnull(inputtext) || strfind(inputtext, ".mp3", true) == -1)
		        {
		            return ShowPlayerDialog(playerid, DIALOG_MP3MUSIC, DIALOG_STYLE_INPUT, "Uploaded Music", "Vui long nhap ten bai hat .mp3 de phat:\n(Su dung /music de hien thi danh sach nhung bai hat HOT o thanh pho.)", "Dong y", "Huy bo");
				}

				for(new i = 0, l = strlen(inputtext); i < l; i ++)
				{
				    switch(inputtext[i])
				    {
				        case 'A'..'Z', 'a'..'z', '0'..'9', '_', '.', '\'', ' ':
				        {
							continue;
						}
						default:
						{
						    SendClientMessage(playerid, COLOR_LIGHTRED, "Ten cua bai hai .mp3 co chua cac ki tu khong hop le, vui long thu lai.");
						    return ShowPlayerDialog(playerid, DIALOG_MP3MUSIC, DIALOG_STYLE_INPUT, "Uploaded Music", "Vui long nhap ten bai hat .mp3 de phat:\n(Use /music for a list of all music uploaded to the thanh pho.)", "Chap nhan", "Huy");
						}
				    }
				}

				format(url, sizeof(url), "http://%s/%s", SERVER_MUSIC_URL, inputtext);

				switch(PlayerInfo[playerid][pMusicType])
				{
		            case MUSIC_MP3PLAYER:
		            {
		                SetMusicStream(MUSIC_MP3PLAYER, playerid, url);
  						SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da doi bai nhac tren MP3 cua ho.", GetPlayerRPName(playerid));
					}
					case MUSIC_BOOMBOX:
					{
					    SetMusicStream(MUSIC_BOOMBOX, playerid, url);
						SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da doi bai nhac tren boombox cua ho.", GetPlayerRPName(playerid));
					}
					case MUSIC_VEHICLE:
					{
					    if(IsPlayerInAnyVehicle(playerid))
					    {
						    SetMusicStream(MUSIC_VEHICLE, GetPlayerVehicleID(playerid), url);
							SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da doi bai nhac tren radio.", GetPlayerRPName(playerid));
						}
					}
				}

				SendClientMessageEx(playerid, COLOR_AQUA, "Ban dat bat dau phat lai bai hat {00AA00}%s{33CCFF}.", inputtext);
		    }
		    else
		    {
		        ShowDialogToPlayer(playerid, DIALOG_MP3PLAYER);
			}
		}
		case DIALOG_VIPMUSIC:
		{
		    if(response)
		    {
		        new url[128];

		        if(isnull(inputtext))
		        {
		            return ShowPlayerDialog(playerid, DIALOG_VIPMUSIC, DIALOG_STYLE_INPUT, "VIP Uploaded Music", "Vui long nhap ten bai hat .mp3 de phat:", "Chap nhan", "Huy");
				}

				for(new i = 0, l = strlen(inputtext); i < l; i ++)
				{
				    switch(inputtext[i])
				    {
				        case 'A'..'Z', 'a'..'z', '0'..'9', '_', '.', '\'', ' ':
				        {
							continue;
						}
						default:
						{
						    SendClientMessage(playerid, COLOR_LIGHTRED, "Ten cua bai hat .mp3 chua cac ki tu khong hop le, vui long thu lai.");
						    return ShowPlayerDialog(playerid, DIALOG_VIPMUSIC, DIALOG_STYLE_INPUT, "VIP Uploaded Music", "Vui long nhap ten bai hat .mp3 de phat:", "Dong y", "Huy");
						}
				    }
				}

				format(url, sizeof(url), "http://%s/%d/%s", VIP_MUSIC_URL, PlayerInfo[playerid][pID], inputtext);
				switch(PlayerInfo[playerid][pMusicType])
				{
		            case MUSIC_MP3PLAYER:
		            {
		                SetMusicStream(MUSIC_MP3PLAYER, playerid, url);
        		  		SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da doi bai nhac tren MP3 cua ho.", GetPlayerRPName(playerid));
					}
					case MUSIC_BOOMBOX:
					{
					    SetMusicStream(MUSIC_BOOMBOX, playerid, url);
						SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da doi bai nhac tren boombox cua ho.", GetPlayerRPName(playerid));
					}
					case MUSIC_VEHICLE:
					{
					    if(IsPlayerInAnyVehicle(playerid))
					    {
						    SetMusicStream(MUSIC_VEHICLE, GetPlayerVehicleID(playerid), url);
							SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da doi bai nhac tren radio.", GetPlayerRPName(playerid));
						}
					}
				}

				SendClientMessageEx(playerid, COLOR_AQUA, "Ban da bat dau phat {00AA00}%s{33CCFF}.", inputtext);
		    }
		    else
		    {
		        ShowDialogToPlayer(playerid, DIALOG_MP3PLAYER);
			}
		}
		case DIALOG_MP3URL:
		{
		    if(response)
		    {
		        if(isnull(inputtext))
		        {
		            return ShowPlayerDialog(playerid, DIALOG_MP3URL, DIALOG_STYLE_INPUT, "Custom URL", "Please enter the URL of the stream you want to play:", "Dong y", "Huy");
          		}
				if(!IsValidYoutubeUrl(inputtext) && strfind(inputtext, ".mp3", true) == -1)
				{
				    return ShowPlayerDialog(playerid, DIALOG_MP3URL, DIALOG_STYLE_INPUT, "Custom URL", ".MP3 hoac Youtube link! Vui long nhap URL", "Dong y", "Huy");
				}

          		switch(PlayerInfo[playerid][pMusicType])
				{
		            case MUSIC_MP3PLAYER:
		            {
		                SetMusicStream(MUSIC_MP3PLAYER, playerid, inputtext);
        		  		SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da doi bai nhac tren MP3 cua ho.", GetPlayerRPName(playerid));
					}
					case MUSIC_BOOMBOX:
					{
					    SetMusicStream(MUSIC_BOOMBOX, playerid, inputtext);
						SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da doi bai nhac tren boombox cua ho.", GetPlayerRPName(playerid));
					}
					case MUSIC_VEHICLE:
					{
					    if(IsPlayerInAnyVehicle(playerid))
					    {
						    SetMusicStream(MUSIC_VEHICLE, GetPlayerVehicleID(playerid), inputtext);
							SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da doi bai nhac tren radio.", GetPlayerRPName(playerid));
						}
					}
				}
		    }
		    else
		    {
		        ShowDialogToPlayer(playerid, DIALOG_MP3PLAYER);
			}
		}
		case DIALOG_MP3RADIO:
		{
		    if(response)
		    {
		        switch(listitem)
		        {
		            case 0:
		            {
		                ShowDialogToPlayer(playerid, DIALOG_MP3RADIOGENRES);
		            }
		            case 1:
		            {
		                ShowDialogToPlayer(playerid, DIALOG_MP3RADIOSEARCH);
		            }
		            /*case 2:
		            {
		                ShowDialogToPlayer(playerid, DIALOG_MP3APISEARCH);
		            }*/
		        }
		    }
		    else
		    {
		        ShowDialogToPlayer(playerid, DIALOG_MP3PLAYER);
			}
		}
		case DIALOG_MP3RADIOGENRES:
		{
		    if(response)
		    {
		        strcpy(PlayerInfo[playerid][pGenre], inputtext, 32);
		        ShowDialogToPlayer(playerid, DIALOG_MP3RADIOSUBGENRES);
			}
			else
			{
			    ShowDialogToPlayer(playerid, DIALOG_MP3RADIO);
		    }
		}
		case DIALOG_MP3RADIOSUBGENRES:
		{
		    if(response)
		    {
		        PlayerInfo[playerid][pPage] = 1;
	     		PlayerInfo[playerid][pSearch] = 0;

		        strcpy(PlayerInfo[playerid][pSubgenre], inputtext, 32);
		        if(!PlayerInfo[playerid][pStationEdit])
		        {
	     			ShowDialogToPlayer(playerid, DIALOG_MP3RADIORESULTS);
				}
				else
				{
				    ShowDialogToPlayer(playerid, DIALOG_ADDSTATION);
				}
			}
			else
			{
			    ShowDialogToPlayer(playerid, DIALOG_MP3RADIOGENRES);
			}
		}
		case DIALOG_MP3RADIORESULTS:
		{
		    if(response)
		    {
		        if(!strcmp(inputtext, ">> Trang ke tiep", true))
		        {
		            PlayerInfo[playerid][pPage]++;
		            ShowDialogToPlayer(playerid, DIALOG_MP3RADIORESULTS);
		        }
		        else if(!strcmp(inputtext, "<< Quay lai", true) && PlayerInfo[playerid][pPage] > 1)
		        {
		            PlayerInfo[playerid][pPage]--;
		            ShowDialogToPlayer(playerid, DIALOG_MP3RADIORESULTS);
		        }
		        else
		        {
			        listitem = ((PlayerInfo[playerid][pPage] - 1) * MAX_LISTED_STATIONS) + listitem;

					if(PlayerInfo[playerid][pSearch])
					{
					    mysql_format(radioConnectionID, queryBuffer, sizeof(queryBuffer), "SELECT name, url FROM radiostations WHERE name LIKE '%%%e%%' OR subgenre LIKE '%%%e%%' ORDER BY name LIMIT %i, 1", PlayerInfo[playerid][pGenre], PlayerInfo[playerid][pGenre], listitem);
						mysql_tquery(radioConnectionID, queryBuffer, "Radio_PlayStation", "i", playerid);
					}
					else
					{
						mysql_format(radioConnectionID, queryBuffer, sizeof(queryBuffer), "SELECT name, url FROM radiostations WHERE genre = '%e' AND subgenre = '%e' ORDER BY name LIMIT %i, 1", PlayerInfo[playerid][pGenre], PlayerInfo[playerid][pSubgenre], listitem);
			        	mysql_tquery(radioConnectionID, queryBuffer, "Radio_PlayStation", "i", playerid);
					}
				}
			}
			else
			{
			    if(PlayerInfo[playerid][pSearch])
			    {
			        ShowDialogToPlayer(playerid, DIALOG_MP3RADIOSEARCH);
			    }
			    else
			    {
			        ShowDialogToPlayer(playerid, DIALOG_MP3RADIOSUBGENRES);
				}
			}
		}
		case DIALOG_MP3RADIOSEARCH:
		{
		    if(response)
		    {
		        if(strlen(inputtext) < 3)
		        {
		            SendClientMessage(playerid, COLOR_LIGHTRED, "Truy van tim kiem cua ban phai chua 3 ky tu tro len.");
		            return ShowDialogToPlayer(playerid, DIALOG_MP3RADIOSEARCH);
		        }

		        PlayerInfo[playerid][pPage] = 1;
		        PlayerInfo[playerid][pSearch] = 1;

		        strcpy(PlayerInfo[playerid][pGenre], inputtext, 32);
                ShowDialogToPlayer(playerid, DIALOG_MP3RADIORESULTS);
		    }
		    else
		    {
		        ShowDialogToPlayer(playerid, DIALOG_MP3RADIO);
			}
		}
		case DIALOG_USECOOKIES:
		{
		    if(response)
		    {
				/*
				    mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "INSERT INTO flags VALUES(null, %i, '%s', NOW(), '%e')", PlayerInfo[targetid][pID], GetPlayerNameEx(playerid), desc);
					mysql_tquery(connectionID, queryBuffer);
				*/

				if(PlayerInfo[playerid][pJailType] > 0 && listitem != 2)
				{
				    return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong the doi Cookies cua minh khi dang o trong tu.");
				}

		        switch(listitem)
		        {
					case 0:
					{
                        if(PlayerInfo[playerid][pCookies] < 2)
     					{
		                    return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong du Cookies. Ban khong the doi mat hang nay.");
		                }

		                PlayerInfo[playerid][pCookies] -= 2;

						mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET cookies = %i WHERE uid = %i", PlayerInfo[playerid][pCookies], PlayerInfo[playerid][pID]);
						mysql_tquery(connectionID, queryBuffer);

		                SetScriptArmour(playerid, 100.0);
		                SetPlayerHealth(playerid, 100.0);
		                SendClientMessage(playerid, COLOR_AQUA, "Ban da doi 2 Cookies cho {00AA00}Day mau & giap{33CCFF}.");
					}
					case 1:
					{
					    if(PlayerInfo[playerid][pCookies] < 5)
		                {
		                    return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong du Cookies. Ban khong the doi mat hang nay.");
		                }
		                if(PlayerInfo[playerid][pJailType] != 3)
		                {
		                    return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong o trong tu IC.");
						}

		                PlayerInfo[playerid][pCookies] -= 5;
		                PlayerInfo[playerid][pJailTime] /= 2;

						mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET cookies = %i, jailtime = %i WHERE uid = %i", PlayerInfo[playerid][pCookies], PlayerInfo[playerid][pJailTime], PlayerInfo[playerid][pID]);
						mysql_tquery(connectionID, queryBuffer);

		                SendClientMessage(playerid, COLOR_AQUA, "Ban da doi 5 Cookies de duoc giam thoi gian {00AA00}tu IC{33CCFF}.");
					}
					case 2:
					{
                        if(PlayerInfo[playerid][pCookies] < 6)
		                {
		                    return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong du Cookies. Ban khong the doi mat hang nay.");
		                }

		                PlayerInfo[playerid][pCookies] -= 6;
		                PlayerInfo[playerid][pEXP] += 4;

						mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET cookies = %i, exp = %i WHERE uid = %i", PlayerInfo[playerid][pCookies], PlayerInfo[playerid][pEXP], PlayerInfo[playerid][pID]);
						mysql_tquery(connectionID, queryBuffer);

		                SendClientMessage(playerid, COLOR_AQUA, "Ban da doi 6 Cookies cho {00AA00}+4 diem ton trong{33CCFF}.");
					}
					/*case 3:
					{
					    if(PlayerInfo[playerid][pCookies] < 3)
		                {
		                    return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong du Cookies. Ban khong the doi mat hang nay.");
		                }

		                ShowPlayerDialog(playerid, DIALOG_COOKIEWEATHER, DIALOG_STYLE_LIST, "Choose your weather.", "Clear skies\nCloudy\nRainy weather\nFoggy\nDull\nHeatwave\nSandstorm", "Select", "Huy bo");
					}
					case 3:
					{
                        if(PlayerInfo[playerid][pCookies] < 10)
		                {
		                    return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong du Cookies. Ban khong the doi mat hang nay.");
		                }
		                if(PlayerInfo[playerid][pMaterials] + 20000 > GetPlayerCapacity(playerid, CAPACITY_MATERIALS))
						{
			    			return SendClientMessageEx(playerid, COLOR_LIGHTRED, "Ban rat muon %i/%i materials. Ban khong the mang theo nua cho den khi ban nang cap Inventory.", PlayerInfo[playerid][pMaterials], GetPlayerCapacity(playerid, CAPACITY_MATERIALS));
						}

		                PlayerInfo[playerid][pCookies] -= 10;
		                PlayerInfo[playerid][pMaterials] += 20000;

						mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET cookies = %i, materials = %i WHERE uid = %i", PlayerInfo[playerid][pCookies], PlayerInfo[playerid][pMaterials], PlayerInfo[playerid][pID]);
						mysql_tquery(connectionID, queryBuffer);

		                SendClientMessage(playerid, COLOR_AQUA, "Ban da doi 10 Cookies for {00AA00}20000 materials{33CCFF}.");
					}
					case 4:
					{
					    if(PlayerInfo[playerid][pCookies] < 10)
		                {
		                    return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong du Cookies. Ban khong the doi mat hang nay.");
		                }
	                	if(PlayerInfo[playerid][pHours] < 2 || PlayerInfo[playerid][pWeaponRestricted] > 0)
    					{
        					return SendClientMessage(playerid, COLOR_LIGHTRED, "You are either weapon restricted or you played less than two playing hours.");
    					}

		                PlayerInfo[playerid][pCookies] -= 10;

		                GivePlayerWeaponEx(playerid, 24);
		                GivePlayerWeaponEx(playerid, 27);
		                GivePlayerWeaponEx(playerid, 29);
		                GivePlayerWeaponEx(playerid, 31);
		                GivePlayerWeaponEx(playerid, 34);

						mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET cookies = %i WHERE uid = %i", PlayerInfo[playerid][pCookies], PlayerInfo[playerid][pID]);
						mysql_tquery(connectionID, queryBuffer);

		                SendClientMessage(playerid, COLOR_AQUA, "Ban da doi 10 Cookies for a {00AA00}Full weapon set{33CCFF}.");
					}*/
					case 3:
					{
					    if(PlayerInfo[playerid][pCookies] < 10)
		                {
		                    return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong du Cookies. Ban khong the doi mat hang nay.");
		                }

		                ShowPlayerDialog(playerid, DIALOG_COOKIENUMBER, DIALOG_STYLE_INPUT, "Thay doi so dien thoai", "Nhap so dien thoai ma ban muon thay:", "Dong y", "Huy");
					}
					case 4:
					{
					    if(PlayerInfo[playerid][pCookies] < 10)
		                {
		                    return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong du Cookies. Ban khong the doi mat hang nay.");
		                }

					    ShowPlayerDialog(playerid, DIALOG_COOKIEJOB, DIALOG_STYLE_LIST, "Chon mot cong viec de tang cap 1x.", "Courier\nCau ca\nVe si\nSua xe\nBan vu khi\nKe buon thuoc phien\nLuat su\nTham tu\nKe trom", "Chon", "Huy");
					}
					case 5:
					{
                        if(PlayerInfo[playerid][pCookies] < 20)
		                {
		                    return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong du Cookies. Ban khong the doi mat hang nay.");
		                }

		                PlayerInfo[playerid][pCookies] -= 20;
		                PlayerInfo[playerid][pDoubleXP] += 8;

						mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET cookies = %i, doublexp = %i WHERE uid = %i", PlayerInfo[playerid][pCookies], PlayerInfo[playerid][pDoubleXP], PlayerInfo[playerid][pID]);
						mysql_tquery(connectionID, queryBuffer);

		                SendClientMessage(playerid, COLOR_AQUA, "Ban da doi 20 Cookies cho {00AA00}8 gio duoc x2 EXP{33CCFF}.");
					}
					/*
					case 8:
					{
					    if(PlayerInfo[playerid][pCookies] < 30)
		                {
		                    return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong du Cookies. Ban khong the doi mat hang nay.");
		                }

		                PlayerInfo[playerid][pCookies] -= 30;

						mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET cookies = %i WHERE uid = %i", PlayerInfo[playerid][pCookies], PlayerInfo[playerid][pID]);
						mysql_tquery(connectionID, queryBuffer);

		                mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "INSERT INTO flags VALUES(null, %i, 'Cookie prize', NOW(), 'Free vehicle (up to $200k value)')", PlayerInfo[playerid][pID]);
						mysql_tquery(connectionID, queryBuffer);

						SendClientMessage(playerid, COLOR_AQUA, "Ban da doi 30 Cookies for a {00AA00}Free vehicle ticket{33CCFF}. /baocao for your prize.");
						SendAdminMessage(COLOR_YELLOW, "AdmWarning: %s[%i] has a pending flag for a vehicle ticket (up to $200k value).", GetPlayerRPName(playerid), playerid);
					}
					case 9:
					{
					    if(PlayerInfo[playerid][pCookies] < 60)
		                {
		                    return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong du Cookies. Ban khong the doi mat hang nay.");
		                }

		                PlayerInfo[playerid][pCookies] -= 60;

						mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET cookies = %i WHERE uid = %i", PlayerInfo[playerid][pCookies], PlayerInfo[playerid][pID]);
						mysql_tquery(connectionID, queryBuffer);

		                mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "INSERT INTO flags VALUES(null, %i, 'Cookie prize', NOW(), 'Free house (up to $250k value)')", PlayerInfo[playerid][pID]);
						mysql_tquery(connectionID, queryBuffer);

						SendClientMessage(playerid, COLOR_AQUA, "Ban da doi 60 Cookies for a {00AA00}Free house ticket{33CCFF}. /baocao for your prize.");
						SendAdminMessage(COLOR_YELLOW, "AdmWarning: %s[%i] has a pending flag for a house ticket (up to $250k value).", GetPlayerRPName(playerid), playerid);
					}
					case 10:
					{
					    if(PlayerInfo[playerid][pCookies] < 100)
		                {
		                    return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong du Cookies. Ban khong the doi mat hang nay.");
		                }

		                PlayerInfo[playerid][pCookies] -= 100;
		                PlayerInfo[playerid][pVIPPackage] = 1;
		                PlayerInfo[playerid][pVIPTime] = gettime() + 2592000;

		                mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET cookies = %i, vippackage = 1, viptime = %i WHERE uid = %i", PlayerInfo[playerid][pCookies], PlayerInfo[playerid][pVIPTime], PlayerInfo[playerid][pID]);
						mysql_tquery(connectionID, queryBuffer);

						SendClientMessage(playerid, COLOR_AQUA, "Ban da doi 100 Cookies for {00AA00}1 month Silver VIP{33CCFF}.");
					}
					case 11:
					{
					    if(PlayerInfo[playerid][pCookies] < 200)
		                {
		                    return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong du Cookies. Ban khong the doi mat hang nay.");
		                }

		                PlayerInfo[playerid][pCookies] -= 200;

						mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET cookies = %i WHERE uid = %i", PlayerInfo[playerid][pCookies], PlayerInfo[playerid][pID]);
						mysql_tquery(connectionID, queryBuffer);

		                mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "INSERT INTO flags VALUES(null, %i, 'Cookie prize', NOW(), 'Free business of any type')", PlayerInfo[playerid][pID]);
						mysql_tquery(connectionID, queryBuffer);

						SendClientMessage(playerid, COLOR_AQUA, "Ban da doi 200 Cookies for a {00AA00}Free business ticket{33CCFF}. /baocao for your prize.");
						SendAdminMessage(COLOR_YELLOW, "AdmWarning: %s[%i] has a pending flag for a business ticket (any type).", GetPlayerRPName(playerid), playerid);
					}
					*/
				}
		    }
		}
/*		case DIALOG_COOKIEWEATHER:
		{
		    if(response)
		    {
		        if(PlayerInfo[playerid][pCookies] < 3)
                {
                    return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong du Cookies. Ban khong the doi mat hang nay.");
                }

                switch(listitem)
                {
                    case 0: gWeather = 1;
                    case 1: gWeather = 4;
                    case 2: gWeather = 8;
                    case 3: gWeather = 9;
                    case 4: gWeather = 12;
                    case 5: gWeather = 18;
                    case 6: gWeather = 19;
				}

				SetWeather(gWeather);

				PlayerInfo[playerid][pCookies] -= 3;

                mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET cookies = %i WHERE uid = %i", PlayerInfo[playerid][pCookies], PlayerInfo[playerid][pID]);
				mysql_tquery(connectionID, queryBuffer);

				SendClientMessageEx(playerid, COLOR_AQUA, "Ban da doi 3 Cookies for a weather change to {00AA00}%s{33CCFF}.", inputtext);
			}
		}*/
		case DIALOG_COOKIENUMBER:
		{
		    if(response)
		    {
		        new number;

		        if(sscanf(inputtext, "i", number))
		        {
		            return ShowPlayerDialog(playerid, DIALOG_COOKIENUMBER, DIALOG_STYLE_INPUT, "Thay doi so dien thoai", "Nhap so dien thoai ma ban muon thay:", "Dong y", "Huy");
				}
				if(number == 0 || number == 911)
				{
				    SendClientMessage(playerid, COLOR_LIGHTRED, "So luong khong hop le. Ban khong the su dung so luong nay.");
				    return ShowPlayerDialog(playerid, DIALOG_COOKIENUMBER, DIALOG_STYLE_INPUT, "Thay doi so dien thoai", "Nhap so luong ma ban muon thay:", "Dong y", "Huy");
				}
				if(PlayerInfo[playerid][pCookies] < 10)
                {
                    return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong du Cookies. Ban khong the doi mat hang nay.");
                }

                mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "SELECT phone FROM users WHERE phone = %i", number);
                mysql_tquery(connectionID, queryBuffer, "OnPlayerChangeNumber", "ii", playerid, number);
			}
		}
		case DIALOG_COOKIEJOB:
		{
		    new job, level;

		    if(response)
			{
			    switch(listitem)
			    {
			        case 0: job = JOB_COURIER;
				}

				if((level = GetJobLevel(playerid, job)) >= 5)
				{
				    return SendClientMessage(playerid, COLOR_LIGHTRED, "Cap do cua ban cho cong viec nay da o muc toi da.");
			    }
			    if(PlayerInfo[playerid][pCookies] < 10)
                {
                    return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong du Cookies. Ban khong the doi mat hang nay.");
                }

                PlayerInfo[playerid][pCookies] -= 10;

                switch(job)
                {
                    case JOB_COURIER:
                    {
                        if(0 <= PlayerInfo[playerid][pCourierSkill] <= 49) {
					        PlayerInfo[playerid][pCourierSkill] = 50;
						} else if(50 <= PlayerInfo[playerid][pCourierSkill] <= 99) {
							PlayerInfo[playerid][pCourierSkill] = 100;
						} else if(100 <= PlayerInfo[playerid][pCourierSkill] <= 199) {
							PlayerInfo[playerid][pCourierSkill] = 200;
						} else if(200 <= PlayerInfo[playerid][pCourierSkill] <= 349) {
							PlayerInfo[playerid][pCourierSkill] = 350;
						}

						mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET cookies = %i, courierskill = %i WHERE uid = %i", PlayerInfo[playerid][pCookies], PlayerInfo[playerid][pCourierSkill], PlayerInfo[playerid][pID]);
						mysql_tquery(connectionID, queryBuffer);
					}
				}

				SendClientMessageEx(playerid, COLOR_AQUA, "Ban da doi 10 cookies de len {00AA00}%s{33CCFF} level tu %i len %i.", GetJobName(job), level, level + 1);
		    }
		}
		case DIALOG_GANGSTASH:
		{
		    if(PlayerInfo[playerid][pGang] == -1)
		    {
		        return 1;
			}

		    if(response)
		    {
		        switch(listitem)
		        {
		            case 0:
		            {
			            ShowDialogToPlayer(playerid, DIALOG_GANGSTASHWEAPONS1);
		            }
		            case 1:
		            {
		                ShowDialogToPlayer(playerid, DIALOG_GANGSTASHDRUGS1);
		            }
		            case 2:
		            {
		                if(!GetGangSkinCount(PlayerInfo[playerid][pGang]))
					    {
					        return SendClientMessage(playerid, COLOR_LIGHTRED, "Khong co skin nao cho Gang cua ban.");
						}

					    PlayerInfo[playerid][pSkinSelected] = -1;
					    ShowPlayerDialog(playerid, DIALOG_GANGSKINS, DIALOG_STYLE_MSGBOX, "Chon trang phuc", "Nhan {00AA00}>> Tiep{A9C4E4} de xem cac skin bang dang co san.", ">> Tiep", "Dong y");
					}
		            case 3:
		            {
		                PlayerInfo[playerid][pSelected] = ITEM_CASH;
		                ShowDialogToPlayer(playerid, DIALOG_GANGSTASHCASH);
					}
		        }
		    }
		}
		case DIALOG_GANGSTASHVEST:
		{
		    if(PlayerInfo[playerid][pGang] == -1)
	        {
		        return 1;
		    }

			if(response)
			{
			    switch(listitem)
			    {
			        case 0:
			        {
			            if(PlayerInfo[playerid][pGangRank] < GangInfo[PlayerInfo[playerid][pGang]][gVestRank])
		                {
		                    return SendClientMessageEx(playerid, COLOR_LIGHTRED, "Ban it nhat phai dat Level %i+ de tao ao vest Kevlar .", GangInfo[PlayerInfo[playerid][pGang]][gVestRank]);
		                }
						if(GangInfo[PlayerInfo[playerid][pGang]][gMaterials] < 200)
						{
						    return SendClientMessage(playerid, COLOR_LIGHTRED, "Khong du vat lieu de che tao chiec ao vest Kevlar.");
						}
						if(GetPlayerArmourEx(playerid) >= 100)
						{
						    return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban da co day du vest.");
						}

						GangInfo[PlayerInfo[playerid][pGang]][gMaterials] -= 200;
						SetScriptArmour(playerid, 100.0);

						mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET materials = %i WHERE id = %i", GangInfo[PlayerInfo[playerid][pGang]][gMaterials], PlayerInfo[playerid][pGang]);
						mysql_tquery(connectionID, queryBuffer);

						SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s lay kevlar tu locker.", GetPlayerRPName(playerid));
						SendClientMessage(playerid, COLOR_AQUA, "Ban da che tao ao vest Kevlar cho 200 vat lieu.");
					}
					case 1:
					{
					    if(PlayerInfo[playerid][pGangRank] < 6)
					    {
					        return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban can it nhat duoc rank 6+ de thay doi rank vest.");
						}

						ShowPlayerDialog(playerid, DIALOG_GANGSTASHVESTRANK, DIALOG_STYLE_LIST, "Chon mot rank de thay doi :", "R0+\nR1+\nR2+\nR3+\nR4+\nR5+\nR6", "Chon", "Quay lai");
					}
		        }
		    }
		    else
		    {
		        ShowDialogToPlayer(playerid, DIALOG_GANGSTASH);
			}
      	}
      	case DIALOG_GANGSTASHVESTRANK:
      	{
      	    if(PlayerInfo[playerid][pGang] == -1)
	        {
		        return 1;
		    }

      	    if(response)
      	    {
      	        GangInfo[PlayerInfo[playerid][pGang]][gVestRank] = listitem;
                SendClientMessageEx(playerid, COLOR_AQUA, "Ban da thay doi rank vest cho {FF6347}Kevlar vests{33CCFF} den rank %i+.", listitem);

                mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET rank_vest = %i WHERE id = %i", listitem, PlayerInfo[playerid][pGang]);
                mysql_tquery(connectionID, queryBuffer);
			}

			ShowDialogToPlayer(playerid, DIALOG_GANGSTASHVEST);
      	}
		case DIALOG_GANGSTASHWEAPONS1:
		{
	        if(PlayerInfo[playerid][pGang] == -1)
	        {
		        return 1;
		    }

		    if(response)
		    {
		        PlayerInfo[playerid][pSelected] = listitem;
		        ShowPlayerDialog(playerid, DIALOG_GANGSTASHWEAPONS2, DIALOG_STYLE_LIST, "Locker Gang | Vu khi", "Rut\nGui\nThay doi Rank", "Chon", "Quay lai");
			}
			else
			{
			    ShowDialogToPlayer(playerid, DIALOG_GANGSTASH);
		    }
		}
		case DIALOG_GANGSTASHWEAPONS2:
		{
          	if(PlayerInfo[playerid][pGang] == -1)
	        {
		        return 1;
		    }
		    if(response)
		    {
				if(listitem == 0)
				{
				    if(PlayerInfo[playerid][pGangRank] < 1)
				    {
				        return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban can it nhat Rank 1+ de lay vu khi.");
		            }
		            if(PlayerInfo[playerid][pHours] < 2 || PlayerInfo[playerid][pWeaponRestricted] > 0)
					{
    					return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban bi han che vu khi hoac ban choi it hon 2 gio choi.");
					}

				    switch(PlayerInfo[playerid][pSelected])
				    {
				        case GANGWEAPON_9MM:
				        {
				            if(PlayerInfo[playerid][pGangRank] < GangInfo[PlayerInfo[playerid][pGang]][gWeaponRanks][GANGWEAPON_9MM])
				            {
				                return SendClientMessage(playerid, COLOR_LIGHTRED, "Rank cua ban khong du cao de rut vu khi nay.");
							}
				            if(GangInfo[PlayerInfo[playerid][pGang]][gWeapons][GANGWEAPON_9MM] <= 0)
				            {
				                return SendClientMessage(playerid, COLOR_LIGHTRED, "Bang dang khong con vu khi nao.");
				            }
				            if(PlayerHasWeapon(playerid, 22))
				            {
				                return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban da co vu khi nay roi.");
							}

				            GangInfo[PlayerInfo[playerid][pGang]][gWeapons][GANGWEAPON_9MM]--;
				            GivePlayerWeaponEx(playerid, 22);

				            mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET weapon_9mm = weapon_9mm - 1 WHERE id = %i", PlayerInfo[playerid][pGang]);
				            mysql_tquery(connectionID, queryBuffer);

				            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s rut khau 9mm tu locker.", GetPlayerRPName(playerid));
				            Log_Write("log_gang", "%s (uid: %i) rut khau 9mm tu %s (id: %i) locker.", GetPlayerNameEx(playerid), PlayerInfo[playerid][pID], GangInfo[PlayerInfo[playerid][pGang]][gName], PlayerInfo[playerid][pGang]);
						}
                        case GANGWEAPON_SDPISTOL:
				        {
				            if(PlayerInfo[playerid][pGangRank] < GangInfo[PlayerInfo[playerid][pGang]][gWeaponRanks][GANGWEAPON_SDPISTOL])
				            {
				                return SendClientMessage(playerid, COLOR_LIGHTRED, "Rank cua ban khong du cao de rut vu khi nay.");
							}
				            if(GangInfo[PlayerInfo[playerid][pGang]][gWeapons][GANGWEAPON_SDPISTOL] <= 0)
				            {
				                return SendClientMessage(playerid, COLOR_LIGHTRED, "Bang dang khong con vu khi nao.");
				            }
				            if(PlayerHasWeapon(playerid, 23))
				            {
				                return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban da co vu khi nay roi.");
							}

				            GangInfo[PlayerInfo[playerid][pGang]][gWeapons][GANGWEAPON_SDPISTOL]--;
				            GivePlayerWeaponEx(playerid, 23);

				            mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET weapon_sdpistol = weapon_sdpistol - 1 WHERE id = %i", PlayerInfo[playerid][pGang]);
				            mysql_tquery(connectionID, queryBuffer);

				            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s rut SilencedPistol tu locker.", GetPlayerRPName(playerid));
				            Log_Write("log_gang", "%s (uid: %i) rut khau SilencedPistol tu %s (id: %i) locker.", GetPlayerNameEx(playerid), PlayerInfo[playerid][pID], GangInfo[PlayerInfo[playerid][pGang]][gName], PlayerInfo[playerid][pGang]);
						}
						case GANGWEAPON_DEAGLE:
				        {
				            if(PlayerInfo[playerid][pGangRank] < GangInfo[PlayerInfo[playerid][pGang]][gWeaponRanks][GANGWEAPON_DEAGLE])
				            {
				                return SendClientMessage(playerid, COLOR_LIGHTRED, "Rank cua ban khong du cao de rut vu khi nay.");
							}
				            if(GangInfo[PlayerInfo[playerid][pGang]][gWeapons][GANGWEAPON_DEAGLE] <= 0)
				            {
				                return SendClientMessage(playerid, COLOR_LIGHTRED, "Bang dang khong con vu khi nao.");
				            }
				            if(PlayerHasWeapon(playerid, 24))
				            {
				                return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban da co vu khi nay roi.");
							}

				            GangInfo[PlayerInfo[playerid][pGang]][gWeapons][GANGWEAPON_DEAGLE]--;
				            GivePlayerWeaponEx(playerid, 24);

				            mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET weapon_deagle = weapon_deagle - 1 WHERE id = %i", PlayerInfo[playerid][pGang]);
				            mysql_tquery(connectionID, queryBuffer);

				            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s rut khau Deagle tu locker.", GetPlayerRPName(playerid));
				            Log_Write("log_gang", "%s (uid: %i) rut khau Deagle tu %s (id: %i) locker.", GetPlayerNameEx(playerid), PlayerInfo[playerid][pID], GangInfo[PlayerInfo[playerid][pGang]][gName], PlayerInfo[playerid][pGang]);
						}
						case GANGWEAPON_SHOTGUN:
				        {
				            if(PlayerInfo[playerid][pGangRank] < GangInfo[PlayerInfo[playerid][pGang]][gWeaponRanks][GANGWEAPON_SHOTGUN])
				            {
				                return SendClientMessage(playerid, COLOR_LIGHTRED, "Rank cua ban khong du cao de rut vu khi nay.");
							}
				            if(GangInfo[PlayerInfo[playerid][pGang]][gWeapons][GANGWEAPON_SHOTGUN] <= 0)
				            {
				                return SendClientMessage(playerid, COLOR_LIGHTRED, "Bang dang khong con vu khi nao.");
				            }
				            if(PlayerHasWeapon(playerid, 25))
				            {
				                return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban da co vu khi nay roi.");
							}

				            GangInfo[PlayerInfo[playerid][pGang]][gWeapons][GANGWEAPON_SHOTGUN]--;
				            GivePlayerWeaponEx(playerid, 25);

				            mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET weapon_shotgun = weapon_shotgun - 1 WHERE id = %i", PlayerInfo[playerid][pGang]);
				            mysql_tquery(connectionID, queryBuffer);

				            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s rut khau Shotgun tu locker.", GetPlayerRPName(playerid));
				            Log_Write("log_gang", "%s (uid: %i) rut khau shotgun tu %s (id: %i) locker.", GetPlayerNameEx(playerid), PlayerInfo[playerid][pID], GangInfo[PlayerInfo[playerid][pGang]][gName], PlayerInfo[playerid][pGang]);
						}
						case GANGWEAPON_SPAS12:
				        {
				            if(PlayerInfo[playerid][pGangRank] < GangInfo[PlayerInfo[playerid][pGang]][gWeaponRanks][GANGWEAPON_SPAS12])
				            {
				                return SendClientMessage(playerid, COLOR_LIGHTRED, "Rank cua ban khong du cao de rut vu khi nay.");
							}
				            if(GangInfo[PlayerInfo[playerid][pGang]][gWeapons][GANGWEAPON_SPAS12] <= 0)
				            {
				                return SendClientMessage(playerid, COLOR_LIGHTRED, "Bang dang khong con vu khi nao.");
				            }
				            if(PlayerHasWeapon(playerid, 27))
				            {
				                return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban da co vu khi nay roi.");
							}

				            GangInfo[PlayerInfo[playerid][pGang]][gWeapons][GANGWEAPON_SPAS12]--;
				            GivePlayerWeaponEx(playerid, 27);

				            mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET weapon_spas12 = weapon_spas12 - 1 WHERE id = %i", PlayerInfo[playerid][pGang]);
				            mysql_tquery(connectionID, queryBuffer);

				            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s rut khau SPAS-12 tu locker.", GetPlayerRPName(playerid));
				            Log_Write("log_gang", "%s (uid: %i) rut khau SPAS-12 tu %s (id: %i) locker.", GetPlayerNameEx(playerid), PlayerInfo[playerid][pID], GangInfo[PlayerInfo[playerid][pGang]][gName], PlayerInfo[playerid][pGang]);
						}
                        case GANGWEAPON_TEC9:
				        {
				            if(PlayerInfo[playerid][pGangRank] < GangInfo[PlayerInfo[playerid][pGang]][gWeaponRanks][GANGWEAPON_TEC9])
				            {
				                return SendClientMessage(playerid, COLOR_LIGHTRED, "Rank cua ban khong du cao de rut vu khi nay.");
							}
				            if(GangInfo[PlayerInfo[playerid][pGang]][gWeapons][GANGWEAPON_TEC9] <= 0)
				            {
				                return SendClientMessage(playerid, COLOR_LIGHTRED, "Bang dang khong con vu khi nao.");
				            }
				            if(PlayerHasWeapon(playerid, 32))
				            {
				                return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban da co vu khi nay roi.");
							}

				            GangInfo[PlayerInfo[playerid][pGang]][gWeapons][GANGWEAPON_TEC9]--;
				            GivePlayerWeaponEx(playerid, 32);

				            mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET weapon_tec9 = weapon_tec9 - 1 WHERE id = %i", PlayerInfo[playerid][pGang]);
				            mysql_tquery(connectionID, queryBuffer);

				            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s rut khau Tec-9 tu locker.", GetPlayerRPName(playerid));
				            Log_Write("log_gang", "%s (uid: %i) rut khau Tec-9 tu %s (id: %i) locker.", GetPlayerNameEx(playerid), PlayerInfo[playerid][pID], GangInfo[PlayerInfo[playerid][pGang]][gName], PlayerInfo[playerid][pGang]);
						}
						case GANGWEAPON_UZI:
				        {
				            if(PlayerInfo[playerid][pGangRank] < GangInfo[PlayerInfo[playerid][pGang]][gWeaponRanks][GANGWEAPON_UZI])
				            {
				                return SendClientMessage(playerid, COLOR_LIGHTRED, "Rank cua ban khong du cao de rut vu khi nay.");
							}
				            if(GangInfo[PlayerInfo[playerid][pGang]][gWeapons][GANGWEAPON_UZI] <= 0)
				            {
				                return SendClientMessage(playerid, COLOR_LIGHTRED, "Bang dang khong con vu khi nao.");
				            }
				            if(PlayerHasWeapon(playerid, 28))
				            {
				                return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban da co vu khi nay roi.");
							}

				            GangInfo[PlayerInfo[playerid][pGang]][gWeapons][GANGWEAPON_UZI]--;
				            GivePlayerWeaponEx(playerid, 28);

				            mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET weapon_uzi = weapon_uzi - 1 WHERE id = %i", PlayerInfo[playerid][pGang]);
				            mysql_tquery(connectionID, queryBuffer);

				            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s rut khau Micro Uzi tu locker.", GetPlayerRPName(playerid));
				            Log_Write("log_gang", "%s (uid: %i) rut khau Micro Uzi tu %s (id: %i) locker.", GetPlayerNameEx(playerid), PlayerInfo[playerid][pID], GangInfo[PlayerInfo[playerid][pGang]][gName], PlayerInfo[playerid][pGang]);
						}
						case GANGWEAPON_MP5:
				        {
				            if(PlayerInfo[playerid][pGangRank] < GangInfo[PlayerInfo[playerid][pGang]][gWeaponRanks][GANGWEAPON_MP5])
				            {
				                return SendClientMessage(playerid, COLOR_LIGHTRED, "Rank cua ban khong du cao de rut vu khi nay.");
							}
				            if(GangInfo[PlayerInfo[playerid][pGang]][gWeapons][GANGWEAPON_MP5] <= 0)
				            {
				                return SendClientMessage(playerid, COLOR_LIGHTRED, "Bang dang khong con vu khi nao.");
				            }
				            if(PlayerHasWeapon(playerid, 29))
				            {
				                return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban da co vu khi nay roi.");
							}

				            GangInfo[PlayerInfo[playerid][pGang]][gWeapons][GANGWEAPON_MP5]--;
				            GivePlayerWeaponEx(playerid, 29);

				            mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET weapon_mp5 = weapon_mp5 - 1 WHERE id = %i", PlayerInfo[playerid][pGang]);
				            mysql_tquery(connectionID, queryBuffer);

				            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s rut khau MP5 tu locker.", GetPlayerRPName(playerid));
				            Log_Write("log_gang", "%s (uid: %i) rut khau MP5 tu %s (id: %i) locker.", GetPlayerNameEx(playerid), PlayerInfo[playerid][pID], GangInfo[PlayerInfo[playerid][pGang]][gName], PlayerInfo[playerid][pGang]);
						}
						case GANGWEAPON_AK47:
				        {
				            if(PlayerInfo[playerid][pGangRank] < GangInfo[PlayerInfo[playerid][pGang]][gWeaponRanks][GANGWEAPON_AK47])
				            {
				                return SendClientMessage(playerid, COLOR_LIGHTRED, "Rank cua ban khong du cao de rut vu khi nay.");
							}
				            if(GangInfo[PlayerInfo[playerid][pGang]][gWeapons][GANGWEAPON_AK47] <= 0)
				            {
				                return SendClientMessage(playerid, COLOR_LIGHTRED, "Bang dang khong con vu khi nao.");
				            }
				            if(PlayerHasWeapon(playerid, 30))
				            {
				                return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban da co vu khi nay roi.");
							}

				            GangInfo[PlayerInfo[playerid][pGang]][gWeapons][GANGWEAPON_AK47]--;
				            GivePlayerWeaponEx(playerid, 30);

				            mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET weapon_ak47 = weapon_ak47 - 1 WHERE id = %i", PlayerInfo[playerid][pGang]);
				            mysql_tquery(connectionID, queryBuffer);

				            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s rut khau AK-47 tu locker.", GetPlayerRPName(playerid));
				            Log_Write("log_gang", "%s (uid: %i) rut khau AK-47 tu %s (id: %i) locker.", GetPlayerNameEx(playerid), PlayerInfo[playerid][pID], GangInfo[PlayerInfo[playerid][pGang]][gName], PlayerInfo[playerid][pGang]);
						}
						case GANGWEAPON_M4:
				        {
				            if(PlayerInfo[playerid][pGangRank] < GangInfo[PlayerInfo[playerid][pGang]][gWeaponRanks][GANGWEAPON_M4])
				            {
				                return SendClientMessage(playerid, COLOR_LIGHTRED, "Rank cua ban khong du cao de rut vu khi nay.");
							}
				            if(GangInfo[PlayerInfo[playerid][pGang]][gWeapons][GANGWEAPON_M4] <= 0)
				            {
				                return SendClientMessage(playerid, COLOR_LIGHTRED, "Bang dang khong con vu khi nao.");
				            }
				            if(PlayerHasWeapon(playerid, 31))
				            {
				                return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban da co vu khi nay roi.");
							}

				            GangInfo[PlayerInfo[playerid][pGang]][gWeapons][GANGWEAPON_M4]--;
				            GivePlayerWeaponEx(playerid, 31);

				            mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET weapon_m4 = weapon_m4 - 1 WHERE id = %i", PlayerInfo[playerid][pGang]);
				            mysql_tquery(connectionID, queryBuffer);

				            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s rut khau M4 tu locker.", GetPlayerRPName(playerid));
				            Log_Write("log_gang", "%s (uid: %i) rut khau M4 tu %s (id: %i) locker.", GetPlayerNameEx(playerid), PlayerInfo[playerid][pID], GangInfo[PlayerInfo[playerid][pGang]][gName], PlayerInfo[playerid][pGang]);
						}
						case GANGWEAPON_RIFLE:
				        {
				            if(PlayerInfo[playerid][pGangRank] < GangInfo[PlayerInfo[playerid][pGang]][gWeaponRanks][GANGWEAPON_RIFLE])
				            {
				                return SendClientMessage(playerid, COLOR_LIGHTRED, "Rank cua ban khong du cao de rut vu khi nay.");
							}
				            if(GangInfo[PlayerInfo[playerid][pGang]][gWeapons][GANGWEAPON_RIFLE] <= 0)
				            {
				                return SendClientMessage(playerid, COLOR_LIGHTRED, "Bang dang khong con vu khi nao.");
				            }
				            if(PlayerHasWeapon(playerid, 33))
				            {
				                return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban da co vu khi nay roi.");
							}

				            GangInfo[PlayerInfo[playerid][pGang]][gWeapons][GANGWEAPON_RIFLE]--;
				            GivePlayerWeaponEx(playerid, 33);

				            mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET weapon_rifle = weapon_rifle - 1 WHERE id = %i", PlayerInfo[playerid][pGang]);
				            mysql_tquery(connectionID, queryBuffer);

				            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s rut khau rifle tu locker.", GetPlayerRPName(playerid));
				            Log_Write("log_gang", "%s (uid: %i) rut khau rifle tu %s (id: %i) locker.", GetPlayerNameEx(playerid), PlayerInfo[playerid][pID], GangInfo[PlayerInfo[playerid][pGang]][gName], PlayerInfo[playerid][pGang]);
						}
						case GANGWEAPON_SNIPER:
				        {
				            if(PlayerInfo[playerid][pGangRank] < GangInfo[PlayerInfo[playerid][pGang]][gWeaponRanks][GANGWEAPON_SNIPER])
				            {
				                return SendClientMessage(playerid, COLOR_LIGHTRED, "Rank cua ban khong du cao de rut vu khi nay.");
							}
				            if(GangInfo[PlayerInfo[playerid][pGang]][gWeapons][GANGWEAPON_SNIPER] <= 0)
				            {
				                return SendClientMessage(playerid, COLOR_LIGHTRED, "Bang dang khong con vu khi nao.");
				            }
				            if(PlayerHasWeapon(playerid, 34))
				            {
				                return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban da co vu khi nay roi.");
							}

				            GangInfo[PlayerInfo[playerid][pGang]][gWeapons][GANGWEAPON_SNIPER]--;
				            GivePlayerWeaponEx(playerid, 34);

				            mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET weapon_sniper = weapon_sniper - 1 WHERE id = %i", PlayerInfo[playerid][pGang]);
				            mysql_tquery(connectionID, queryBuffer);

				            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da lay Sniper Rifle tu locker.", GetPlayerRPName(playerid));
				            Log_Write("log_gang", "%s (uid: %i) rut khau Sniper Rifle tu %s (id: %i) locker.", GetPlayerNameEx(playerid), PlayerInfo[playerid][pID], GangInfo[PlayerInfo[playerid][pGang]][gName], PlayerInfo[playerid][pGang]);
						}
					}
				}
				else if(listitem == 1)
		        {
		            if(IsLawEnforcement(playerid))
					{
				    	return SendClientMessage(playerid, COLOR_LIGHTRED, "Thuc thi phap luat cam tang tru vu khi.");
					}
		            if(GetPlayerHealthEx(playerid) < 60)
					{
					    return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong the cat giu vu khi vi mau duoi 60.");
					}

                    switch(PlayerInfo[playerid][pSelected])
				    {
				        case GANGWEAPON_9MM:
				        {
				            if(!PlayerHasWeapon(playerid, 22))
				            {
				                return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong co vu khi nay.");
							}

				            GangInfo[PlayerInfo[playerid][pGang]][gWeapons][GANGWEAPON_9MM]++;
				            RemovePlayerWeapon(playerid, 22);

				            mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET weapon_9mm = weapon_9mm + 1 WHERE id = %i", PlayerInfo[playerid][pGang]);
				            mysql_tquery(connectionID, queryBuffer);

				            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s dat khau 9mm vao locker.", GetPlayerRPName(playerid));
				            Log_Write("log_gang", "%s (uid: %i) dat khau 9mm vao %s (id: %i) locker.", GetPlayerNameEx(playerid), PlayerInfo[playerid][pID], GangInfo[PlayerInfo[playerid][pGang]][gName], PlayerInfo[playerid][pGang]);
						}
                        case GANGWEAPON_SDPISTOL:
				        {
				            if(!PlayerHasWeapon(playerid, 23))
				            {
				                return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong co vu khi nay.");
							}

				            GangInfo[PlayerInfo[playerid][pGang]][gWeapons][GANGWEAPON_SDPISTOL]++;
				            RemovePlayerWeapon(playerid, 23);

				            mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET weapon_sdpistol = weapon_sdpistol + 1 WHERE id = %i", PlayerInfo[playerid][pGang]);
				            mysql_tquery(connectionID, queryBuffer);

				            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s dat khau silenced pistol vao locker.", GetPlayerRPName(playerid));
				            Log_Write("log_gang", "%s (uid: %i) dat khau silenced pistol vao %s (id: %i) locker.", GetPlayerNameEx(playerid), PlayerInfo[playerid][pID], GangInfo[PlayerInfo[playerid][pGang]][gName], PlayerInfo[playerid][pGang]);
						}
						case GANGWEAPON_DEAGLE:
				        {
				            if(!PlayerHasWeapon(playerid, 24))
				            {
				                return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong co vu khi nay.");
							}

				            GangInfo[PlayerInfo[playerid][pGang]][gWeapons][GANGWEAPON_DEAGLE]++;
				            RemovePlayerWeapon(playerid, 24);

				            mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET weapon_deagle = weapon_deagle + 1 WHERE id = %i", PlayerInfo[playerid][pGang]);
				            mysql_tquery(connectionID, queryBuffer);

				            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s dat khau Desert Eagle vao locker.", GetPlayerRPName(playerid));
				            Log_Write("log_gang", "%s (uid: %i) dat khau Desert Eagle vao %s (id: %i) locker.", GetPlayerNameEx(playerid), PlayerInfo[playerid][pID], GangInfo[PlayerInfo[playerid][pGang]][gName], PlayerInfo[playerid][pGang]);
						}
						case GANGWEAPON_SHOTGUN:
				        {
				            if(!PlayerHasWeapon(playerid, 25))
				            {
				                return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong co vu khi nay.");
							}

				            GangInfo[PlayerInfo[playerid][pGang]][gWeapons][GANGWEAPON_SHOTGUN]++;
				            RemovePlayerWeapon(playerid, 25);

				            mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET weapon_shotgun = weapon_shotgun + 1 WHERE id = %i", PlayerInfo[playerid][pGang]);
				            mysql_tquery(connectionID, queryBuffer);

				            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s dat khau shotgun vao locker.", GetPlayerRPName(playerid));
				            Log_Write("log_gang", "%s (uid: %i) dat khau shotgun vao %s (id: %i) locker.", GetPlayerNameEx(playerid), PlayerInfo[playerid][pID], GangInfo[PlayerInfo[playerid][pGang]][gName], PlayerInfo[playerid][pGang]);
						}
						case GANGWEAPON_SPAS12:
				        {
				            if(!PlayerHasWeapon(playerid, 27))
				            {
				                return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong co vu khi nay.");
							}

				            GangInfo[PlayerInfo[playerid][pGang]][gWeapons][GANGWEAPON_SPAS12]++;
				            RemovePlayerWeapon(playerid, 27);

				            mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET weapon_spas12 = weapon_spas12 + 1 WHERE id = %i", PlayerInfo[playerid][pGang]);
				            mysql_tquery(connectionID, queryBuffer);

				            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s dat khau SPAS-12 vao locker.", GetPlayerRPName(playerid));
				            Log_Write("log_gang", "%s (uid: %i) dat khau SPAS-12 vao %s (id: %i) locker.", GetPlayerNameEx(playerid), PlayerInfo[playerid][pID], GangInfo[PlayerInfo[playerid][pGang]][gName], PlayerInfo[playerid][pGang]);
						}
                        case GANGWEAPON_TEC9:
				        {
				            if(!PlayerHasWeapon(playerid, 32))
				            {
				                return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong co vu khi nay.");
							}

				            GangInfo[PlayerInfo[playerid][pGang]][gWeapons][GANGWEAPON_TEC9]++;
				            RemovePlayerWeapon(playerid, 32);

				            mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET weapon_tec9 = weapon_tec9 + 1 WHERE id = %i", PlayerInfo[playerid][pGang]);
				            mysql_tquery(connectionID, queryBuffer);

				            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s dat khau Tec-9 vao locker.", GetPlayerRPName(playerid));
				            Log_Write("log_gang", "%s (uid: %i) dat khau Tec-9 vao %s (id: %i) locker.", GetPlayerNameEx(playerid), PlayerInfo[playerid][pID], GangInfo[PlayerInfo[playerid][pGang]][gName], PlayerInfo[playerid][pGang]);
						}
						case GANGWEAPON_UZI:
				        {
				            if(!PlayerHasWeapon(playerid, 28))
				            {
				                return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong co vu khi nay.");
							}

				            GangInfo[PlayerInfo[playerid][pGang]][gWeapons][GANGWEAPON_UZI]++;
				            RemovePlayerWeapon(playerid, 28);

				            mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET weapon_uzi = weapon_uzi + 1 WHERE id = %i", PlayerInfo[playerid][pGang]);
				            mysql_tquery(connectionID, queryBuffer);

				            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s dat khau Micro Uzi vao locker.", GetPlayerRPName(playerid));
				            Log_Write("log_gang", "%s (uid: %i) dat khau Micro Uzi vao %s (id: %i) locker.", GetPlayerNameEx(playerid), PlayerInfo[playerid][pID], GangInfo[PlayerInfo[playerid][pGang]][gName], PlayerInfo[playerid][pGang]);
						}
						case GANGWEAPON_MP5:
				        {
				            if(!PlayerHasWeapon(playerid, 29))
				            {
				                return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong co vu khi nay.");
							}

				            GangInfo[PlayerInfo[playerid][pGang]][gWeapons][GANGWEAPON_MP5]++;
				            RemovePlayerWeapon(playerid, 29);

				            mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET weapon_mp5 = weapon_mp5 + 1 WHERE id = %i", PlayerInfo[playerid][pGang]);
				            mysql_tquery(connectionID, queryBuffer);

				            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s dat khaun MP5 vao locker.", GetPlayerRPName(playerid));
				            Log_Write("log_gang", "%s (uid: %i) dat khaun MP5 vao %s (id: %i) locker.", GetPlayerNameEx(playerid), PlayerInfo[playerid][pID], GangInfo[PlayerInfo[playerid][pGang]][gName], PlayerInfo[playerid][pGang]);
						}
						case GANGWEAPON_AK47:
				        {
				            if(!PlayerHasWeapon(playerid, 30))
				            {
				                return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong co vu khi nay.");
							}

				            GangInfo[PlayerInfo[playerid][pGang]][gWeapons][GANGWEAPON_AK47]++;
				            RemovePlayerWeapon(playerid, 30);

				            mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET weapon_ak47 = weapon_ak47 + 1 WHERE id = %i", PlayerInfo[playerid][pGang]);
				            mysql_tquery(connectionID, queryBuffer);

				            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s dat khaun AK-47 vao locker.", GetPlayerRPName(playerid));
				            Log_Write("log_gang", "%s (uid: %i) dat khaun AK-47 vao %s (id: %i) locker.", GetPlayerNameEx(playerid), PlayerInfo[playerid][pID], GangInfo[PlayerInfo[playerid][pGang]][gName], PlayerInfo[playerid][pGang]);
						}
						case GANGWEAPON_M4:
				        {
				            if(!PlayerHasWeapon(playerid, 31))
				            {
				                return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong co vu khi nay.");
							}

				            GangInfo[PlayerInfo[playerid][pGang]][gWeapons][GANGWEAPON_M4]++;
				            RemovePlayerWeapon(playerid, 31);

				            mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET weapon_m4 = weapon_m4 + 1 WHERE id = %i", PlayerInfo[playerid][pGang]);
				            mysql_tquery(connectionID, queryBuffer);

				            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s dat khaun M4 vao locker.", GetPlayerRPName(playerid));
				            Log_Write("log_gang", "%s (uid: %i) dat khaun M4 vao %s (id: %i) locker.", GetPlayerNameEx(playerid), PlayerInfo[playerid][pID], GangInfo[PlayerInfo[playerid][pGang]][gName], PlayerInfo[playerid][pGang]);
						}
						case GANGWEAPON_RIFLE:
				        {
				            if(!PlayerHasWeapon(playerid, 33))
				            {
				                return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong co vu khi nay.");
							}

				            GangInfo[PlayerInfo[playerid][pGang]][gWeapons][GANGWEAPON_RIFLE]++;
				            RemovePlayerWeapon(playerid, 33);

				            mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET weapon_rifle = weapon_rifle + 1 WHERE id = %i", PlayerInfo[playerid][pGang]);
				            mysql_tquery(connectionID, queryBuffer);

				            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s dat khau rifle vao locker.", GetPlayerRPName(playerid));
				            Log_Write("log_gang", "%s (uid: %i) dat khau rifle vao %s (id: %i) locker.", GetPlayerNameEx(playerid), PlayerInfo[playerid][pID], GangInfo[PlayerInfo[playerid][pGang]][gName], PlayerInfo[playerid][pGang]);
						}
						case GANGWEAPON_SNIPER:
				        {
				            if(!PlayerHasWeapon(playerid, 34))
				            {
				                return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong co vu khi nay.");
							}

				            GangInfo[PlayerInfo[playerid][pGang]][gWeapons][GANGWEAPON_SNIPER]++;
				            RemovePlayerWeapon(playerid, 34);

				            mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET weapon_sniper = weapon_sniper + 1 WHERE id = %i", PlayerInfo[playerid][pGang]);
				            mysql_tquery(connectionID, queryBuffer);

				            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s dat khau sniper rifle vao locker.", GetPlayerRPName(playerid));
				            Log_Write("log_gang", "%s (uid: %i) dat khau sniper rifle vao %s (id: %i) locker.", GetPlayerNameEx(playerid), PlayerInfo[playerid][pID], GangInfo[PlayerInfo[playerid][pGang]][gName], PlayerInfo[playerid][pGang]);
						}
					}
				}
				else if(listitem == 2)
				{
				    if(PlayerInfo[playerid][pGangRank] < 6)
				    {
				        return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban can phai dat Rank 6+ de edit rank de lay vu khi.");
					}

				    ShowPlayerDialog(playerid, DIALOG_GANGSTASHWEAPONRANK, DIALOG_STYLE_LIST, "Chon muc rank de lay vu khi :", "R0+\nR1+\nR2+\nR3+\nR4+\nR5+\nR6", "Chon", "Quay lai");
				}
			}
			else
			{
			    ShowDialogToPlayer(playerid, DIALOG_GANGSTASHWEAPONS1);
			}
		}
		case DIALOG_GANGSTASHWEAPONRANK:
		{
		    if(PlayerInfo[playerid][pGang] == -1)
		    {
		        return 1;
			}

		    if(response)
		    {
		        switch(PlayerInfo[playerid][pSelected])
		        {
		            case GANGWEAPON_9MM:
		            {
		                GangInfo[PlayerInfo[playerid][pGang]][gWeaponRanks][GANGWEAPON_9MM] = listitem;
		                SendClientMessageEx(playerid, COLOR_AQUA, "Ban da dat rank de lay vu khi {FF6347}9mm{33CCFF} den rank %i+.", listitem);

		                mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET rank_9mm = %i WHERE id = %i", listitem, PlayerInfo[playerid][pGang]);
		                mysql_tquery(connectionID, queryBuffer);
		            }
		            case GANGWEAPON_SDPISTOL:
		            {
		                GangInfo[PlayerInfo[playerid][pGang]][gWeaponRanks][GANGWEAPON_SDPISTOL] = listitem;
		                SendClientMessageEx(playerid, COLOR_AQUA, "Ban da dat rank de lay vu khi {FF6347}Silenced pistol{33CCFF} den rank %i+.", listitem);

		                mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET rank_9mm = %i WHERE id = %i", listitem, PlayerInfo[playerid][pGang]);
		                mysql_tquery(connectionID, queryBuffer);
		            }
		            case GANGWEAPON_DEAGLE:
		            {
		                GangInfo[PlayerInfo[playerid][pGang]][gWeaponRanks][GANGWEAPON_DEAGLE] = listitem;
		                SendClientMessageEx(playerid, COLOR_AQUA, "Ban da dat rank de lay vu khi {FF6347}Desert Eagle{33CCFF} den rank %i+.", listitem);

		                mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET rank_deagle = %i WHERE id = %i", listitem, PlayerInfo[playerid][pGang]);
		                mysql_tquery(connectionID, queryBuffer);
		            }
		            case GANGWEAPON_SHOTGUN:
		            {
		                GangInfo[PlayerInfo[playerid][pGang]][gWeaponRanks][GANGWEAPON_SHOTGUN] = listitem;
		                SendClientMessageEx(playerid, COLOR_AQUA, "Ban da dat rank de lay vu khi {FF6347}Shotgun{33CCFF} den rank %i+.", listitem);

		                mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET rank_shotgun = %i WHERE id = %i", listitem, PlayerInfo[playerid][pGang]);
		                mysql_tquery(connectionID, queryBuffer);
		            }
		            case GANGWEAPON_SPAS12:
		            {
		                GangInfo[PlayerInfo[playerid][pGang]][gWeaponRanks][GANGWEAPON_SPAS12] = listitem;
		                SendClientMessageEx(playerid, COLOR_AQUA, "Ban da dat rank de lay vu khi {FF6347}SPAS-12{33CCFF} den rank %i+.", listitem);

		                mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET rank_spas12 = %i WHERE id = %i", listitem, PlayerInfo[playerid][pGang]);
		                mysql_tquery(connectionID, queryBuffer);
		            }
            		case GANGWEAPON_TEC9:
		            {
		                GangInfo[PlayerInfo[playerid][pGang]][gWeaponRanks][GANGWEAPON_TEC9] = listitem;
		                SendClientMessageEx(playerid, COLOR_AQUA, "Ban da dat rank de lay vu khi {FF6347}Tec-9{33CCFF} den rank %i+.", listitem);

		                mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET rank_tec9 = %i WHERE id = %i", listitem, PlayerInfo[playerid][pGang]);
		                mysql_tquery(connectionID, queryBuffer);
		            }
                    case GANGWEAPON_UZI:
		            {
		                GangInfo[PlayerInfo[playerid][pGang]][gWeaponRanks][GANGWEAPON_UZI] = listitem;
		                SendClientMessageEx(playerid, COLOR_AQUA, "Ban da dat rank de lay vu khi {FF6347}Micro Uzi{33CCFF} den rank %i+.", listitem);

		                mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET rank_uzi = %i WHERE id = %i", listitem, PlayerInfo[playerid][pGang]);
		                mysql_tquery(connectionID, queryBuffer);
		            }
		            case GANGWEAPON_MP5:
		            {
		                GangInfo[PlayerInfo[playerid][pGang]][gWeaponRanks][GANGWEAPON_MP5] = listitem;
		                SendClientMessageEx(playerid, COLOR_AQUA, "Ban da dat rank de lay vu khi {FF6347}MP5{33CCFF} den rank %i+.", listitem);

		                mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET rank_mp5 = %i WHERE id = %i", listitem, PlayerInfo[playerid][pGang]);
		                mysql_tquery(connectionID, queryBuffer);
		            }
                    case GANGWEAPON_AK47:
		            {
		                GangInfo[PlayerInfo[playerid][pGang]][gWeaponRanks][GANGWEAPON_AK47] = listitem;
		                SendClientMessageEx(playerid, COLOR_AQUA, "Ban da dat rank de lay vu khi {FF6347}AK-47{33CCFF} den rank %i+.", listitem);

		                mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET rank_ak47 = %i WHERE id = %i", listitem, PlayerInfo[playerid][pGang]);
		                mysql_tquery(connectionID, queryBuffer);
		            }
		            case GANGWEAPON_M4:
		            {
		                GangInfo[PlayerInfo[playerid][pGang]][gWeaponRanks][GANGWEAPON_M4] = listitem;
		                SendClientMessageEx(playerid, COLOR_AQUA, "Ban da dat rank de lay vu khi {FF6347}M4{33CCFF} den rank %i+.", listitem);

		                mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET rank_m4 = %i WHERE id = %i", listitem, PlayerInfo[playerid][pGang]);
		                mysql_tquery(connectionID, queryBuffer);
		            }
		            case GANGWEAPON_RIFLE:
		            {
		                GangInfo[PlayerInfo[playerid][pGang]][gWeaponRanks][GANGWEAPON_RIFLE] = listitem;
		                SendClientMessageEx(playerid, COLOR_AQUA, "Ban da dat rank de lay vu khi {FF6347}Rifle{33CCFF} den rank %i+.", listitem);

		                mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET rank_rifle = %i WHERE id = %i", listitem, PlayerInfo[playerid][pGang]);
		                mysql_tquery(connectionID, queryBuffer);
		            }
		            case GANGWEAPON_SNIPER:
		            {
		                GangInfo[PlayerInfo[playerid][pGang]][gWeaponRanks][GANGWEAPON_SNIPER] = listitem;
		                SendClientMessageEx(playerid, COLOR_AQUA, "Ban da dat rank de lay vu khi {FF6347}Sniper Rifle{33CCFF} den rank %i+.", listitem);

		                mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET rank_sniper = %i WHERE id = %i", listitem, PlayerInfo[playerid][pGang]);
		                mysql_tquery(connectionID, queryBuffer);
		            }
				}

		        ShowDialogToPlayer(playerid, DIALOG_GANGSTASHWEAPONS1);
		    }
		    else
		    {
		        ShowPlayerDialog(playerid, DIALOG_GANGSTASHWEAPONS2, DIALOG_STYLE_LIST, "LOCKER | Vu khi", "Rut\nGui\nThay doi Rank", "Chon", "Quay lai");
			}
		}
		case DIALOG_GANGSTASHDRUGS1:
		{
		    if(PlayerInfo[playerid][pGang] == -1)
		    {
		        return 1;
			}

		    if(response)
		    {
		        switch(listitem)
		        {
		            case 0: PlayerInfo[playerid][pSelected] = ITEM_WEED;
		            case 1: PlayerInfo[playerid][pSelected] = ITEM_COCAINE;
		            case 2: PlayerInfo[playerid][pSelected] = ITEM_METH;
		            case 3: PlayerInfo[playerid][pSelected] = ITEM_PAINKILLERS;
		        }

				ShowDialogToPlayer(playerid, DIALOG_GANGSTASHDRUGS2);
		    }
			else
		    {
		        ShowDialogToPlayer(playerid, DIALOG_GANGSTASH);
			}
		}
		case DIALOG_GANGSTASHDRUGS2:
		{
		    if(PlayerInfo[playerid][pGang] == -1)
		    {
		        return 1;
			}

		    if(response)
		    {
		        if(listitem == 0)
		        {
		            if(PlayerInfo[playerid][pGangRank] < 2)
		            {
		                return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban can phai dat Rank 2+ de rut thuoc phien.");
		            }

		            ShowDialogToPlayer(playerid, DIALOG_GANGWITHDRAW);
		        }
		        else if(listitem == 1)
		        {
		            ShowDialogToPlayer(playerid, DIALOG_GANGDEPOSIT);
		        }
			}
			else
			{
			    ShowDialogToPlayer(playerid, DIALOG_GANGSTASHDRUGS1);
			}
		}
		case DIALOG_GANGWITHDRAW:
		{
		    if(PlayerInfo[playerid][pGang] == -1 || PlayerInfo[playerid][pGangRank] < 3)
		    {
		        return 1;
			}

			if(response)
			{
			    new amount;

			    if(sscanf(inputtext, "i", amount))
			    {
			        return ShowDialogToPlayer(playerid, DIALOG_GANGWITHDRAW);
				}

				switch(PlayerInfo[playerid][pSelected])
				{
				    case ITEM_WEED:
				    {
				        if(amount < 1 || amount > GangInfo[PlayerInfo[playerid][pGang]][gWeed])
				        {
				            SendClientMessage(playerid, COLOR_LIGHTRED, "Khong du tien.");
				            return ShowDialogToPlayer(playerid, DIALOG_GANGWITHDRAW);
						}
						if(PlayerInfo[playerid][pWeed] + amount > GetPlayerCapacity(playerid, CAPACITY_WEED))
						{
						    SendClientMessageEx(playerid, COLOR_LIGHTRED, "Ban rat muon %i/%i weed. Ban khong the mang theo nua cho den khi ban nang cap Inventory.", PlayerInfo[playerid][pWeed], GetPlayerCapacity(playerid, CAPACITY_WEED));
						    return ShowDialogToPlayer(playerid, DIALOG_GANGWITHDRAW);
						}

						GangInfo[PlayerInfo[playerid][pGang]][gWeed] -= amount;
						PlayerInfo[playerid][pWeed] += amount;

						mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET weed = %i WHERE id = %i", GangInfo[PlayerInfo[playerid][pGang]][gWeed], PlayerInfo[playerid][pGang]);
						mysql_tquery(connectionID, queryBuffer);

						mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET weed = %i WHERE uid = %i", PlayerInfo[playerid][pWeed], PlayerInfo[playerid][pID]);
						mysql_tquery(connectionID, queryBuffer);

						SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s lay mot so Weed tu locker Gang.", GetPlayerRPName(playerid));
						SendClientMessageEx(playerid, COLOR_AQUA, "** Ban da lay ra %i mot it Weed tu locker Gang.", amount);
						Log_Write("log_gang", "%s (uid: %i) lay ra %i mot it Weed tu locker Gang.", GetPlayerNameEx(playerid), PlayerInfo[playerid][pID], amount);
					}
					case ITEM_COCAINE:
				    {
				        if(amount < 1 || amount > GangInfo[PlayerInfo[playerid][pGang]][gCocaine])
				        {
				            SendClientMessage(playerid, COLOR_LIGHTRED, "So tien khong du.");
				            return ShowDialogToPlayer(playerid, DIALOG_GANGWITHDRAW);
						}
						if(PlayerInfo[playerid][pCocaine] + amount > GetPlayerCapacity(playerid, CAPACITY_COCAINE))
						{
						    SendClientMessageEx(playerid, COLOR_LIGHTRED, "Ban rat muon %i/%i cocaine. Ban khong the mang theo nua cho den khi ban nang cap Inventory.", PlayerInfo[playerid][pCocaine], GetPlayerCapacity(playerid, CAPACITY_COCAINE));
						    return ShowDialogToPlayer(playerid, DIALOG_GANGWITHDRAW);
						}

						GangInfo[PlayerInfo[playerid][pGang]][gCocaine] -= amount;
						PlayerInfo[playerid][pCocaine] += amount;

						mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET cocaine = %i WHERE id = %i", GangInfo[PlayerInfo[playerid][pGang]][gCocaine], PlayerInfo[playerid][pGang]);
						mysql_tquery(connectionID, queryBuffer);

						mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET cocaine = %i WHERE uid = %i", PlayerInfo[playerid][pCocaine], PlayerInfo[playerid][pID]);
						mysql_tquery(connectionID, queryBuffer);

						SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s lay ra mot it cocaine tu locker gang.", GetPlayerRPName(playerid));
						SendClientMessageEx(playerid, COLOR_AQUA, "** Ban da lay ra %i mot it Cocaine tu locker Gang.", amount);
						Log_Write("log_gang", "%s (uid: %i) lay ra %i mot it cocaine tu locker gang.", GetPlayerNameEx(playerid), PlayerInfo[playerid][pID], amount);
					}
                    case ITEM_METH:
				    {
				        if(amount < 1 || amount > GangInfo[PlayerInfo[playerid][pGang]][gMeth])
				        {
				            SendClientMessage(playerid, COLOR_LIGHTRED, "So tien khong du.");
				            return ShowDialogToPlayer(playerid, DIALOG_GANGWITHDRAW);
						}
						if(PlayerInfo[playerid][pMeth] + amount > GetPlayerCapacity(playerid, CAPACITY_METH))
						{
						    SendClientMessageEx(playerid, COLOR_LIGHTRED, "Ban rat muon %i/%i meth. Ban khong the mang theo nua cho den khi ban nang cap Inventory.", PlayerInfo[playerid][pMeth], GetPlayerCapacity(playerid, CAPACITY_METH));
						    return ShowDialogToPlayer(playerid, DIALOG_GANGWITHDRAW);
						}

						GangInfo[PlayerInfo[playerid][pGang]][gMeth] -= amount;
						PlayerInfo[playerid][pMeth] += amount;

						mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET meth = %i WHERE id = %i", GangInfo[PlayerInfo[playerid][pGang]][gMeth], PlayerInfo[playerid][pGang]);
						mysql_tquery(connectionID, queryBuffer);

						mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET meth = %i WHERE uid = %i", PlayerInfo[playerid][pMeth], PlayerInfo[playerid][pID]);
						mysql_tquery(connectionID, queryBuffer);

						SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s lay ra mot it meth tu locker Gang.", GetPlayerRPName(playerid));
						SendClientMessageEx(playerid, COLOR_AQUA, "** Ban da lay %i mot it Meth tu locker Gang .", amount);
						Log_Write("log_gang", "%s (uid: %i) lay ra %i mot it meth tu locker Gang.", GetPlayerNameEx(playerid), PlayerInfo[playerid][pID], amount);
					}
					case ITEM_PAINKILLERS:
				    {
				        if(amount < 1 || amount > GangInfo[PlayerInfo[playerid][pGang]][gPainkillers])
				        {
				            SendClientMessage(playerid, COLOR_LIGHTRED, "So tien khong du.");
				            return ShowDialogToPlayer(playerid, DIALOG_GANGWITHDRAW);
						}
						if(PlayerInfo[playerid][pPainkillers] + amount > GetPlayerCapacity(playerid, CAPACITY_PAINKILLERS))
						{
						    SendClientMessageEx(playerid, COLOR_LIGHTRED, "Ban rat muon %i/%i painkillers. Ban khong the mang theo nua cho den khi ban nang cap Inventory.", PlayerInfo[playerid][pPainkillers], GetPlayerCapacity(playerid, CAPACITY_PAINKILLERS));
						    return ShowDialogToPlayer(playerid, DIALOG_GANGWITHDRAW);
						}

						GangInfo[PlayerInfo[playerid][pGang]][gPainkillers] -= amount;
						PlayerInfo[playerid][pPainkillers] += amount;

						mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET painkillers = %i WHERE id = %i", GangInfo[PlayerInfo[playerid][pGang]][gPainkillers], PlayerInfo[playerid][pGang]);
						mysql_tquery(connectionID, queryBuffer);

						mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET painkillers = %i WHERE uid = %i", PlayerInfo[playerid][pPainkillers], PlayerInfo[playerid][pID]);
						mysql_tquery(connectionID, queryBuffer);

						SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s lay ra painkillers tu locker Gang.", GetPlayerRPName(playerid));
						SendClientMessageEx(playerid, COLOR_AQUA, "** Ban da lay ra %i painkillers tu locker.", amount);
						Log_Write("log_gang", "%s (uid: %i) rut %i painkillers tu locker.", GetPlayerNameEx(playerid), PlayerInfo[playerid][pID], amount);
					}
					case ITEM_MATERIALS:
				    {
				        if(amount < 1 || amount > GangInfo[PlayerInfo[playerid][pGang]][gMaterials])
				        {
				            SendClientMessage(playerid, COLOR_LIGHTRED, "Khong du tien.");
				            return ShowDialogToPlayer(playerid, DIALOG_GANGWITHDRAW);
						}
						if(PlayerInfo[playerid][pMaterials] + amount > GetPlayerCapacity(playerid, CAPACITY_MATERIALS))
						{
						    SendClientMessageEx(playerid, COLOR_LIGHTRED, "Ban rat muon %i/%i vat lieu. Ban khong the mang theo nua cho den khi ban nang cap Inventory.", PlayerInfo[playerid][pMaterials], GetPlayerCapacity(playerid, CAPACITY_MATERIALS));
						    return ShowDialogToPlayer(playerid, DIALOG_GANGWITHDRAW);
						}

						GangInfo[PlayerInfo[playerid][pGang]][gMaterials] -= amount;
						PlayerInfo[playerid][pMaterials] += amount;

						mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET materials = %i WHERE id = %i", GangInfo[PlayerInfo[playerid][pGang]][gMaterials], PlayerInfo[playerid][pGang]);
						mysql_tquery(connectionID, queryBuffer);

						mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET materials = %i WHERE uid = %i", PlayerInfo[playerid][pMaterials], PlayerInfo[playerid][pID]);
						mysql_tquery(connectionID, queryBuffer);

						SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s lay ra mot it meth tu locker Gang.", GetPlayerRPName(playerid));
						SendClientMessageEx(playerid, COLOR_AQUA, "** Ban da lay ra %i vat lieu tu locker.", amount);
						Log_Write("log_gang", "%s (uid: %i) rut %i vat lieu tu locker.", GetPlayerNameEx(playerid), PlayerInfo[playerid][pID], amount);
					}
					case ITEM_CASH:
				    {
				        if(amount < 1 || amount > GangInfo[PlayerInfo[playerid][pGang]][gCash])
				        {
				            SendClientMessage(playerid, COLOR_LIGHTRED, "Khong du tien.");
				            return ShowDialogToPlayer(playerid, DIALOG_GANGWITHDRAW);
						}

						GangInfo[PlayerInfo[playerid][pGang]][gCash] -= amount;
						GivePlayerCash(playerid, amount);

						mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET cash = %i WHERE id = %i", GangInfo[PlayerInfo[playerid][pGang]][gCash], PlayerInfo[playerid][pGang]);
						mysql_tquery(connectionID, queryBuffer);

						SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s lay ra mot it tien tu locker Gang.", GetPlayerRPName(playerid));
						SendClientMessageEx(playerid, COLOR_AQUA, "** Ban da lay ra %s tu locker.", FormatNumber(amount));
						Log_Write("log_gang", "%s (uid: %i) rut $%i tu locker.", GetPlayerNameEx(playerid), PlayerInfo[playerid][pID], amount);
					}
				}
			}
			else
			{
			    if(PlayerInfo[playerid][pSelected] == ITEM_MATERIALS) {
			        ShowDialogToPlayer(playerid, DIALOG_GANGSTASHMATS);
				} else if(PlayerInfo[playerid][pSelected] == ITEM_CASH) {
					ShowDialogToPlayer(playerid, DIALOG_GANGSTASHCASH);
				} else {
				    ShowDialogToPlayer(playerid, DIALOG_GANGSTASHDRUGS2);
				}
			}
		}
		case DIALOG_GANGDEPOSIT:
		{
		    if(PlayerInfo[playerid][pGang] == -1)
		    {
		        return 1;
			}

			if(response)
			{
			    new amount;

			    if(sscanf(inputtext, "i", amount))
			    {
			        return ShowDialogToPlayer(playerid, DIALOG_GANGDEPOSIT);
				}

				switch(PlayerInfo[playerid][pSelected])
				{
				    case ITEM_WEED:
				    {
				        if(amount < 1 || amount > PlayerInfo[playerid][pWeed])
				        {
				            SendClientMessage(playerid, COLOR_LIGHTRED, "Khong du tien.");
				            return ShowDialogToPlayer(playerid, DIALOG_GANGDEPOSIT);
						}
						if(GangInfo[PlayerInfo[playerid][pGang]][gWeed] + amount > GetGangStashCapacity(PlayerInfo[playerid][pGang], STASH_CAPACITY_WEED))
						{
						    SendClientMessageEx(playerid, COLOR_LIGHTRED, "Locker khong the chua nhieu hon %i grams weed.", GetGangStashCapacity(PlayerInfo[playerid][pGang], STASH_CAPACITY_WEED));
						    return ShowDialogToPlayer(playerid, DIALOG_GANGDEPOSIT);
						}

						GangInfo[PlayerInfo[playerid][pGang]][gWeed] += amount;
						PlayerInfo[playerid][pWeed] -= amount;

						mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET weed = %i WHERE id = %i", GangInfo[PlayerInfo[playerid][pGang]][gWeed], PlayerInfo[playerid][pGang]);
						mysql_tquery(connectionID, queryBuffer);

						mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET weed = %i WHERE uid = %i", PlayerInfo[playerid][pWeed], PlayerInfo[playerid][pID]);
						mysql_tquery(connectionID, queryBuffer);

						SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s gui mot it Weed vao locker.", GetPlayerRPName(playerid));
						SendClientMessageEx(playerid, COLOR_AQUA, "** Ban da gui %i grams weed vao locker.", amount);
						Log_Write("log_gang", "%s (uid: %i) gui %i grams weed vao locker.", GetPlayerNameEx(playerid), PlayerInfo[playerid][pID], amount);
					}
					case ITEM_COCAINE:
				    {
				        if(amount < 1 || amount > PlayerInfo[playerid][pCocaine])
				        {
				            SendClientMessage(playerid, COLOR_LIGHTRED, "Khong du tien.");
				            return ShowDialogToPlayer(playerid, DIALOG_GANGDEPOSIT);
						}
						if(GangInfo[PlayerInfo[playerid][pGang]][gCocaine] + amount > GetGangStashCapacity(PlayerInfo[playerid][pGang], STASH_CAPACITY_COCAINE))
						{
						    SendClientMessageEx(playerid, COLOR_LIGHTRED, "Tu dung do khong duoc chua nhieu hon %i gam cocaine.", GetGangStashCapacity(PlayerInfo[playerid][pGang], STASH_CAPACITY_COCAINE));
						    return ShowDialogToPlayer(playerid, DIALOG_GANGDEPOSIT);
						}

						GangInfo[PlayerInfo[playerid][pGang]][gCocaine] += amount;
						PlayerInfo[playerid][pCocaine] -= amount;

						mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET cocaine = %i WHERE id = %i", GangInfo[PlayerInfo[playerid][pGang]][gCocaine], PlayerInfo[playerid][pGang]);
						mysql_tquery(connectionID, queryBuffer);

						mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET cocaine = %i WHERE uid = %i", PlayerInfo[playerid][pCocaine], PlayerInfo[playerid][pID]);
						mysql_tquery(connectionID, queryBuffer);

						SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s gui mot it cocaine vao locker.", GetPlayerRPName(playerid));
						SendClientMessageEx(playerid, COLOR_AQUA, "** Ban da gui %i grams cocaine vao locker.", amount);
						Log_Write("log_gang", "%s (uid: %i) gui %i grams cocaine vao locker.", GetPlayerNameEx(playerid), PlayerInfo[playerid][pID], amount);
					}
                    case ITEM_METH:
				    {
				        if(amount < 1 || amount > PlayerInfo[playerid][pMeth])
				        {
				            SendClientMessage(playerid, COLOR_LIGHTRED, "Khong du tien.");
				            return ShowDialogToPlayer(playerid, DIALOG_GANGDEPOSIT);
						}
						if(GangInfo[PlayerInfo[playerid][pGang]][gMeth] + amount > GetGangStashCapacity(PlayerInfo[playerid][pGang], STASH_CAPACITY_METH))
						{
						    SendClientMessageEx(playerid, COLOR_LIGHTRED, "Tủ đựng đồ không được chứa nhiều hơn %i gram meth.", GetGangStashCapacity(PlayerInfo[playerid][pGang], STASH_CAPACITY_METH));
						    return ShowDialogToPlayer(playerid, DIALOG_GANGDEPOSIT);
						}

						GangInfo[PlayerInfo[playerid][pGang]][gMeth] += amount;
						PlayerInfo[playerid][pMeth] -= amount;

						mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET meth = %i WHERE id = %i", GangInfo[PlayerInfo[playerid][pGang]][gMeth], PlayerInfo[playerid][pGang]);
						mysql_tquery(connectionID, queryBuffer);

						mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET meth = %i WHERE uid = %i", PlayerInfo[playerid][pMeth], PlayerInfo[playerid][pID]);
						mysql_tquery(connectionID, queryBuffer);

						SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s gui mot it meth vao locker.", GetPlayerRPName(playerid));
						SendClientMessageEx(playerid, COLOR_AQUA, "** Ban da gui %i grams meth vao locker.", amount);
						Log_Write("log_gang", "%s (uid: %i) gui %i grams meth vao locker.", GetPlayerNameEx(playerid), PlayerInfo[playerid][pID], amount);
					}
					case ITEM_PAINKILLERS:
				    {
				        if(amount < 1 || amount > PlayerInfo[playerid][pPainkillers])
				        {
				            SendClientMessage(playerid, COLOR_LIGHTRED, "Khong du tien.");
				            return ShowDialogToPlayer(playerid, DIALOG_GANGDEPOSIT);
						}
						if(GangInfo[PlayerInfo[playerid][pGang]][gPainkillers] + amount > GetGangStashCapacity(PlayerInfo[playerid][pGang], STASH_CAPACITY_PAINKILLERS))
						{
						    SendClientMessageEx(playerid, COLOR_LIGHTRED, "Tu dung do khong the chua nhieu hon %i thuoc giam dau.", GetGangStashCapacity(PlayerInfo[playerid][pGang], STASH_CAPACITY_PAINKILLERS));
						    return ShowDialogToPlayer(playerid, DIALOG_GANGDEPOSIT);
						}

						GangInfo[PlayerInfo[playerid][pGang]][gPainkillers] += amount;
						PlayerInfo[playerid][pPainkillers] -= amount;

						mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET painkillers = %i WHERE id = %i", GangInfo[PlayerInfo[playerid][pGang]][gPainkillers], PlayerInfo[playerid][pGang]);
						mysql_tquery(connectionID, queryBuffer);

						mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET painkillers = %i WHERE uid = %i", PlayerInfo[playerid][pPainkillers], PlayerInfo[playerid][pID]);
						mysql_tquery(connectionID, queryBuffer);

						SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s gui mot it thuoc giam dau vao locker.", GetPlayerRPName(playerid));
						SendClientMessageEx(playerid, COLOR_AQUA, "** Ban da gui %i thuoc giam dau vao locker.", amount);
						Log_Write("log_gang", "%s (uid: %i) gui %i thuoc giam dau vao locker.", GetPlayerNameEx(playerid), PlayerInfo[playerid][pID], amount);
					}
					case ITEM_MATERIALS:
				    {
				        if(amount < 1 || amount > PlayerInfo[playerid][pMaterials])
				        {
				            SendClientMessage(playerid, COLOR_LIGHTRED, "Khong du tien.");
				            return ShowDialogToPlayer(playerid, DIALOG_GANGDEPOSIT);
						}
						if(GangInfo[PlayerInfo[playerid][pGang]][gMaterials] + amount > GetGangStashCapacity(PlayerInfo[playerid][pGang], STASH_CAPACITY_MATERIALS))
						{
						    SendClientMessageEx(playerid, COLOR_LIGHTRED, "Tu dung do khong duoc chua nhieu hon %i vat lieu.", GetGangStashCapacity(PlayerInfo[playerid][pGang], STASH_CAPACITY_MATERIALS));
						    return ShowDialogToPlayer(playerid, DIALOG_GANGDEPOSIT);
						}

						GangInfo[PlayerInfo[playerid][pGang]][gMaterials] += amount;
						PlayerInfo[playerid][pMaterials] -= amount;

						mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET materials = %i WHERE id = %i", GangInfo[PlayerInfo[playerid][pGang]][gMaterials], PlayerInfo[playerid][pGang]);
						mysql_tquery(connectionID, queryBuffer);

						mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET materials = %i WHERE uid = %i", PlayerInfo[playerid][pMaterials], PlayerInfo[playerid][pID]);
						mysql_tquery(connectionID, queryBuffer);

						SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s gui mot it vat lieu vao locker.", GetPlayerRPName(playerid));
						SendClientMessageEx(playerid, COLOR_AQUA, "** Ban da gui %i vat lieu vao locker.", amount);
						Log_Write("log_gang", "%s (uid: %i) gui %i vat lieu vao locker.", GetPlayerNameEx(playerid), PlayerInfo[playerid][pID], amount);
					}
					case ITEM_CASH:
				    {
				        if(amount < 1 || amount > PlayerInfo[playerid][pCash])
				        {
				            SendClientMessage(playerid, COLOR_LIGHTRED, "Khong du tien.");
				            return ShowDialogToPlayer(playerid, DIALOG_GANGDEPOSIT);
						}
						if(GangInfo[PlayerInfo[playerid][pGang]][gCash] + amount > GetGangStashCapacity(PlayerInfo[playerid][pGang], STASH_CAPACITY_CASH))
						{
							SendClientMessageEx(playerid, COLOR_LIGHTRED, "The locker can't contain more than $%i.", GetGangStashCapacity(PlayerInfo[playerid][pGang], STASH_CAPACITY_CASH));
							return ShowDialogToPlayer(playerid, DIALOG_GANGDEPOSIT);
						}

						GangInfo[PlayerInfo[playerid][pGang]][gCash] += amount;
						GivePlayerCash(playerid, -amount);

						mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET cash = %i WHERE id = %i", GangInfo[PlayerInfo[playerid][pGang]][gCash], PlayerInfo[playerid][pGang]);
						mysql_tquery(connectionID, queryBuffer);

						SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s gui mot it tien vao locker.", GetPlayerRPName(playerid));
						SendClientMessageEx(playerid, COLOR_AQUA, "** Ban da gui %s vao locker.", FormatNumber(amount));
						Log_Write("log_gang", "%s (uid: %i) deposited $%i vao locker.", GetPlayerNameEx(playerid), PlayerInfo[playerid][pID], amount);
					}
				}
			}
			else
			{
				if(PlayerInfo[playerid][pSelected] == ITEM_MATERIALS) {
			        ShowDialogToPlayer(playerid, DIALOG_GANGSTASHMATS);
				} else if(PlayerInfo[playerid][pSelected] == ITEM_CASH) {
					ShowDialogToPlayer(playerid, DIALOG_GANGSTASHCASH);
				} else {
				    ShowDialogToPlayer(playerid, DIALOG_GANGSTASHDRUGS2);
				}
			}
		}
		case DIALOG_GANGSTASHMATS:
		{
		    if(response)
		    {
		        if(listitem == 0)
				{
				    if(PlayerInfo[playerid][pGangRank] < 6)
				    {
				        return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban phai xep hang it nhat 6+ de co the rut tai lieu.");
		            }

					ShowDialogToPlayer(playerid, DIALOG_GANGWITHDRAW);
				}
				else if(listitem == 1)
				{
					ShowDialogToPlayer(playerid, DIALOG_GANGDEPOSIT);
				}
			}
		    else
		    {
		        ShowDialogToPlayer(playerid, DIALOG_GANGSTASH);
		    }
		}
		case DIALOG_GANGSTASHCASH:
		{
		    if(response)
		    {
		        if(listitem == 0)
				{
				    if(PlayerInfo[playerid][pGangRank] < 6)
				    {
				        return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban phai xep hang it nhat 6+ de co the rut tien mat.");
		            }

					ShowDialogToPlayer(playerid, DIALOG_GANGWITHDRAW);
				}
				else if(listitem == 1)
				{
					ShowDialogToPlayer(playerid, DIALOG_GANGDEPOSIT);
				}
			}
		    else
		    {
		        ShowDialogToPlayer(playerid, DIALOG_GANGSTASH);
		    }
		}
		case DIALOG_GANGSKINS:
		{
		    if(PlayerInfo[playerid][pGang] >= 0)
		    {
		        if(response)
		        {
					new index = PlayerInfo[playerid][pSkinSelected] + 1;

					if(index >= MAX_GANG_SKINS)
					{
					    // When the player is shown the dialog for the first time, their skin isn't chnaged until they click >> Tiep.
					    SetPlayerSkin(playerid, PlayerInfo[playerid][pSkin]);
					    PlayerInfo[playerid][pSkinSelected] = -1;
					}
					else
					{
					    // Find the Tiep skin in the array.
						for(new i = index; i < MAX_GANG_SKINS; i ++)
						{
						    if(GangInfo[PlayerInfo[playerid][pGang]][gSkins][i] != 0)
						    {
						        SetPlayerSkin(playerid, GangInfo[PlayerInfo[playerid][pGang]][gSkins][i]);
						        PlayerInfo[playerid][pSkinSelected] = i;
						        break;
					        }
		                }

		                if(index == PlayerInfo[playerid][pSkinSelected] + 1)
		                {
		                    // Looks like there was no skin found. So, we'll go Huy to the very first valid skin in the skin array.
		                    for(new i = 0; i < MAX_GANG_SKINS; i ++)
							{
						    	if(GangInfo[PlayerInfo[playerid][pGang]][gSkins][i] != 0)
						    	{
		                            SetPlayerSkin(playerid, GangInfo[PlayerInfo[playerid][pGang]][gSkins][i]);
						        	PlayerInfo[playerid][pSkinSelected] = i;
						        	break;
								}
							}
		                }
		            }

		            ShowPlayerDialog(playerid, DIALOG_GANGSKINS, DIALOG_STYLE_MSGBOX, "Skin selection", "Nhan {00AA00}>> Tiep{A9C4E4} de duyet qua cac giao dien bang nhom co san.", ">> Tiep", "Xac nhan");
		        }
		        else
		        {
		            PlayerInfo[playerid][pSkinSelected] = -1;

					SetScriptSkin(playerid, GetPlayerSkin(playerid));
		            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s thay quan ao cua ho.", GetPlayerRPName(playerid));
				}
		    }
		}
		case DIALOG_GANGFINDCAR:
		{
		    if(response)
		    {
		        new count, garageid;

		        foreach(new i: Vehicle)
			 	{
			 	    if((VehicleInfo[i][vID] > 0 && VehicleInfo[i][vGang] == PlayerInfo[playerid][pGang]) && (count++ == listitem))
			 	    {
                        PlayerInfo[playerid][pCP] = CHECKPOINT_MISC;

			            if((garageid = GetVehicleGarage(i)) >= 0)
			            {
			                SetPlayerCheckpoint(playerid, GarageInfo[garageid][gPosX], GarageInfo[garageid][gPosY], GarageInfo[garageid][gPosZ], 3.0);
			                SendClientMessageEx(playerid, COLOR_YELLOW, "%s nay nam trong ga ra. Tram kiem soat duoc danh dau tai vi tri cua nha de xe.", GetVehicleName(i));
			            }
			            else
			            {
			                new
			                    Float:x,
			                    Float:y,
			                    Float:z;

			                GetVehiclePos(i, x, y, z);
			                SetPlayerCheckpoint(playerid, x, y, z, 3.0);
			                SendClientMessageEx(playerid, COLOR_YELLOW, "%s nay nam trong %s. Tram kiem soat duoc danh dau tai vi tri.", GetVehicleName(i), GetZoneName(x, y, z));
			            }

			            return 1;
		            }
				}
			}
		}
		case DIALOG_GANGPOINTSHOP:
		{
		    if(PlayerInfo[playerid][pGang] == -1 || PlayerInfo[playerid][pGangRank] < 6)
		    {
		        return 1;
		    }

		    if(response)
		    {
		        switch(listitem)
		        {
		            case 0:
		            {
		                if(GangInfo[PlayerInfo[playerid][pGang]][gPoints] < 500)
		                {
		                    return SendClientMessage(playerid, COLOR_LIGHTRED, "Nhom cua ban khong co du diem.");
						}
						if(PlayerInfo[playerid][pCash] < 50000)
						{
						    return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban can co 50.000 do la trong tay de mua ban nang cap nay.");
						}
						if(GangInfo[PlayerInfo[playerid][pGang]][gDrugDealer])
						{
						    return SendClientMessage(playerid, COLOR_LIGHTRED, "Nhom cua ban da co ban nang cap nay.");
						}

						GangInfo[PlayerInfo[playerid][pGang]][gDrugDealer] = 1;
						GangInfo[PlayerInfo[playerid][pGang]][gDrugX] = 0.0;
						GangInfo[PlayerInfo[playerid][pGang]][gDrugY] = 0.0;
						GangInfo[PlayerInfo[playerid][pGang]][gDrugZ] = 0.0;
						GangInfo[PlayerInfo[playerid][pGang]][gDrugWeed] = 0;
						GangInfo[PlayerInfo[playerid][pGang]][gDrugMeth] = 0;
						GangInfo[PlayerInfo[playerid][pGang]][gDrugCocaine] = 0;
						GangInfo[PlayerInfo[playerid][pGang]][gDrugPrices][0] = 500;
						GangInfo[PlayerInfo[playerid][pGang]][gDrugPrices][1] = 1000;
						GangInfo[PlayerInfo[playerid][pGang]][gDrugPrices][2] = 1500;
						GangInfo[PlayerInfo[playerid][pGang]][gPoints] -= 500;

						mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET drugdealer = 1, drug_x = 0.0, drug_y = 0.0, drug_z = 0.0, drugweed = 0, drugcocaine = 0, drugmeth = 0, weed_price = 500, cocaine_price = 1000, meth_price = 1500, points = %i WHERE id = %i", GangInfo[PlayerInfo[playerid][pGang]][gPoints], PlayerInfo[playerid][pGang]);
						mysql_tquery(connectionID, queryBuffer);

						GivePlayerCash(playerid, -50000);
						SendClientMessage(playerid, COLOR_AQUA, "Ban da chi 500 GP & 50.000 USD cho mot {00AA00}NPC buon ban ma tuy{33CCFF}.'/gang npc' de chinh sua ten buon ma tuy cua ban.");
						Log_Write("log_gang", "%s (uid: %i) da chi 500 GP & 50000 do la cho mot dai ly ban thuoc NPC cho %s (id: %i).", GetPlayerNameEx(playerid), PlayerInfo[playerid][pID], GangInfo[PlayerInfo[playerid][pGang]][gName], PlayerInfo[playerid][pGang]);
					}
					case 1:
		            {
		                if(GangInfo[PlayerInfo[playerid][pGang]][gPoints] < 500)
		                {
		                    return SendClientMessage(playerid, COLOR_LIGHTRED, "Nhom cua ban khong co du diem.");
						}
						if(PlayerInfo[playerid][pCash] < 50000)
						{
						    return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban can co 50.000 do la trong tay de mua ban nang cap nay.");
						}
						if(GangInfo[PlayerInfo[playerid][pGang]][gArmsDealer])
						{
						    return SendClientMessage(playerid, COLOR_LIGHTRED, "Nhom cua ban da co ban nang cap nay.");
						}

						GangInfo[PlayerInfo[playerid][pGang]][gArmsDealer] = 1;
						GangInfo[PlayerInfo[playerid][pGang]][gArmsX] = 0.0;
						GangInfo[PlayerInfo[playerid][pGang]][gArmsY] = 0.0;
						GangInfo[PlayerInfo[playerid][pGang]][gArmsZ] = 0.0;
						GangInfo[PlayerInfo[playerid][pGang]][gArmsMaterials] = 0;
						GangInfo[PlayerInfo[playerid][pGang]][gPoints] -= 500;

						mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET armsdealer = 1, arms_x = 0.0, arms_y = 0.0, arms_z = 0.0, armsmaterials = 0, points = %i WHERE id = %i", GangInfo[PlayerInfo[playerid][pGang]][gPoints], PlayerInfo[playerid][pGang]);
						mysql_tquery(connectionID, queryBuffer);

						GivePlayerCash(playerid, -50000);
						SendClientMessage(playerid, COLOR_AQUA, "Ban da chi 500 GP & 50.000 USD cho mot {00AA00}NPC dai ly ban vu khi{33CCFF}. '/gang npc' de chinh sua dai ly ban vu khi cua ban.");
						Log_Write("log_gang", "%s (uid: %i) da chi 500 GP & 50000 do la cho mot dai ly nhanh NPC cho %s (id: %i).", GetPlayerNameEx(playerid), PlayerInfo[playerid][pID], GangInfo[PlayerInfo[playerid][pGang]][gName], PlayerInfo[playerid][pGang]);
					}
					case 2:
					{
					    if(GangInfo[PlayerInfo[playerid][pGang]][gPoints] < 400)
		                {
		                    return SendClientMessage(playerid, COLOR_LIGHTRED, "Nhom cua ban khong co du diem.");
						}
						if(PlayerInfo[playerid][pCash] < 75000)
						{
						    return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban can co 75.000 USD de mua ban nang cap nay.");
						}

						GivePlayerCash(playerid, -75000);
						GiveGangPoints(PlayerInfo[playerid][pGang], -400);

						mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "INSERT INTO flags VALUES(null, %i, 'Gang point redemption', NOW(), 'Duel arena')", PlayerInfo[playerid][pID]);
						mysql_tquery(connectionID, queryBuffer);

						SendClientMessage(playerid, COLOR_AQUA, "Ban da chi 400 GP & 75.000 USD cho {00AA00}Dau truong {33CCFF}./baocao de quan tri vien thiet lap no.");
						SendAdminMessage(COLOR_YELLOW, "AdmWarning: %s[%i] co mot la co dang cho xu ly cho mot dau truong tay doi cho bang nhom cua ho.", GetPlayerRPName(playerid), playerid);
					}
                    case 3:
					{
					    if(GangInfo[PlayerInfo[playerid][pGang]][gPoints] < 4500)
		                {
		                    return SendClientMessage(playerid, COLOR_LIGHTRED, "Nhom cua ban khong co du diem.");
						}
						if(PlayerInfo[playerid][pCash] < 100000)
						{
						    return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban can co 100.000 do la trong tay de mua ban nang cap nay.");
						}

						GivePlayerCash(playerid, -100000);
						GiveGangPoints(PlayerInfo[playerid][pGang], -4500);

						mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "INSERT INTO flags VALUES(null, %i, 'Gang point redemption', NOW(), 'Gang mapping (up to 50 objects)')", PlayerInfo[playerid][pID]);
						mysql_tquery(connectionID, queryBuffer);

						SendClientMessage(playerid, COLOR_AQUA, "Ban da chi 4500 GP & 100.000 do la cho {00AA00}Mapping{33CCFF}./baocao de quan tri vien thiet lap no.");
						SendAdminMessage(COLOR_YELLOW, "AdmWarning: %s[%i] co mot la co dang cho xu ly de lap ban do cho bang nhom cua ho.", GetPlayerRPName(playerid), playerid);
					}
					case 4:
					{
					    if(GangInfo[PlayerInfo[playerid][pGang]][gPoints] < 5000)
		                {
		                    return SendClientMessage(playerid, COLOR_LIGHTRED, "Nhom cua ban khong co du diem.");
						}
						if(PlayerInfo[playerid][pCash] < 100000)
						{
						    return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban can co 100.000 do la trong tay de mua ban nang cap nay.");
						}

						GivePlayerCash(playerid, -100000);
						GiveGangPoints(PlayerInfo[playerid][pGang], -5000);

						mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "INSERT INTO flags VALUES(null, %i, 'Gang point redemption', NOW(), 'Custom gang interior')", PlayerInfo[playerid][pID]);
						mysql_tquery(connectionID, queryBuffer);

						SendClientMessage(playerid, COLOR_AQUA, "Ban da su dung 5000 GP & $100,000 vao {00AA00}Custom gang interior{33CCFF}. /baocao de admin tao no.");
						SendAdminMessage(COLOR_YELLOW, "AdmWarning: %s[%i] has a pending flag for a custom gang interior.", GetPlayerRPName(playerid), playerid);
					}
					case 5:
					{
					    new cashNeeded = 100000 + (50000*GangInfo[PlayerInfo[playerid][pGang]][gMatLevel]);
						new pointsNeeded = 1500 + (500*GangInfo[PlayerInfo[playerid][pGang]][gMatLevel]);
					    if(GangInfo[PlayerInfo[playerid][pGang]][gPoints] < pointsNeeded)
					    {
					        return SendClientMessage(playerid, COLOR_LIGHTRED, "Nhom cua ban khong co du diem.");
					    }
					    if(PlayerInfo[playerid][pCash] < cashNeeded)
						{
		    				return SendClientMessageEx(playerid, COLOR_LIGHTRED, "Ban can $%i trong tay de nang cap", cashNeeded);
						}
						if(GangInfo[PlayerInfo[playerid][pGang]][gMatLevel] + 1 > 3)
						{
                            return SendClientMessage(playerid, COLOR_LIGHTRED, "Your gang's materials upgrade is already maxed out. (3/3)");
						}

						GangInfo[PlayerInfo[playerid][pGang]][gMatLevel]++;
						GangInfo[PlayerInfo[playerid][pGang]][gPoints] -= pointsNeeded;
						GivePlayerCash(playerid, -cashNeeded);
						mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET matlevel = %i, points = %i WHERE id = %i", GangInfo[PlayerInfo[playerid][pGang]][gMatLevel], GangInfo[PlayerInfo[playerid][pGang]][gPoints], PlayerInfo[playerid][pGang]);
						mysql_tquery(connectionID, queryBuffer);

						SendClientMessageEx(playerid, COLOR_GREEN, "Ban da su dung %i GP & $%i cho materials upgrade %i/3", pointsNeeded, cashNeeded, GangInfo[PlayerInfo[playerid][pGang]][gMatLevel]);
						SendClientMessageEx(playerid, COLOR_GREEN, "Bang dang cua ban se nhan duoc %i materials from each material-class turf captured.", (10000+(5000*GangInfo[PlayerInfo[playerid][pGang]][gMatLevel])));

                        Log_Write("log_gang", "%s (uid: %i) spent %i GP & $%i for gang level %i/3 for %s (id: %i).", GetPlayerNameEx(playerid), PlayerInfo[playerid][pID], pointsNeeded, cashNeeded, GangInfo[PlayerInfo[playerid][pGang]][gMatLevel], GangInfo[PlayerInfo[playerid][pGang]][gName], PlayerInfo[playerid][pGang]);
					}
					case 6:
					{
					    new cashNeeded = 40000 + (20000 * GangInfo[PlayerInfo[playerid][pGang]][gGunLevel]);
						new pointsNeeded = 1500 + (250*GangInfo[PlayerInfo[playerid][pGang]][gGunLevel]);
						if(GangInfo[PlayerInfo[playerid][pGang]][gPoints] < pointsNeeded)
					    {
					        return SendClientMessage(playerid, COLOR_LIGHTRED, "Nhom cua ban khong co du diem.");
					    }
					    if(PlayerInfo[playerid][pCash] < cashNeeded)
						{
		    				return SendClientMessageEx(playerid, COLOR_LIGHTRED, "ban can $%i trong tay de nang cap.", cashNeeded);
						}
						if(GangInfo[PlayerInfo[playerid][pGang]][gGunLevel] + 1 > 5)
						{
                            return SendClientMessage(playerid, COLOR_LIGHTRED, "Guns upgrade cua ban da toi gioi han.(5/5");
						}

						GangInfo[PlayerInfo[playerid][pGang]][gGunLevel]++;
						GangInfo[PlayerInfo[playerid][pGang]][gPoints] -= pointsNeeded;
						GivePlayerCash(playerid, -cashNeeded);
						mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET gunlevel = %i, points = %i WHERE id = %i", GangInfo[PlayerInfo[playerid][pGang]][gGunLevel], GangInfo[PlayerInfo[playerid][pGang]][gPoints], PlayerInfo[playerid][pGang]);
						mysql_tquery(connectionID, queryBuffer);

						SendClientMessageEx(playerid, COLOR_GREEN, "Ban da su dung %i GP & $%i cho guns upgrade %i/5", pointsNeeded, cashNeeded, GangInfo[PlayerInfo[playerid][pGang]][gGunLevel]);
						SendClientMessageEx(playerid, COLOR_GREEN, "Bang dang cua ban se duoc nhan %i guns from each weapon-class turf captured.", (10+GangInfo[PlayerInfo[playerid][pGang]][gGunLevel]));


						Log_Write("log_gang", "%s (uid: %i) spent %i GP & $%i for gang level %i/5 for %s (id: %i).", GetPlayerNameEx(playerid), PlayerInfo[playerid][pID], pointsNeeded, cashNeeded, GangInfo[PlayerInfo[playerid][pGang]][gGunLevel], GangInfo[PlayerInfo[playerid][pGang]][gName], PlayerInfo[playerid][pGang]);
					}
					case 7:
					{
					    switch(GangInfo[PlayerInfo[playerid][pGang]][gLevel])
					    {
					        case 1:
					        {
					            if(GangInfo[PlayerInfo[playerid][pGang]][gPoints] < 6000)
				                {
				                    return SendClientMessage(playerid, COLOR_LIGHTRED, "Nhom cua ban khong co du diem.");
								}
								if(PlayerInfo[playerid][pCash] < 75000)
								{
								    return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban can co 75.000 USD de mua ban nang cap nay.");
								}

								GangInfo[PlayerInfo[playerid][pGang]][gLevel] = 2;
								GangInfo[PlayerInfo[playerid][pGang]][gPoints] -= 6000;

								mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET level = 2, points = %i WHERE id = %i", GangInfo[PlayerInfo[playerid][pGang]][gPoints], PlayerInfo[playerid][pGang]);
								mysql_tquery(connectionID, queryBuffer);

								GivePlayerCash(playerid, -75000);
								ReloadGang(PlayerInfo[playerid][pGang]);

								SendClientMessageEx(playerid, COLOR_GREEN, "Ban da su dung 6000 GP & $75,000 cho gang level 2/3. Bang dang cua ban se co %i thanh vien & %i phuong tien giao thong bang dang.", GetGangMemberLimit(PlayerInfo[playerid][pGang]), GetGangVehicleLimit(PlayerInfo[playerid][pGang]));
								SendClientMessage(playerid, COLOR_GREEN, "Khoang trong cua bang dang cua ban trong tu khoa da duoc tang len. Mo khoa tu do cua ban de tim hieu them!");

								Log_Write("log_gang", "%s (uid: %i) da su dung 6000 GP & $75000 cho gang level 2/3 for %s (id: %i).", GetPlayerNameEx(playerid), PlayerInfo[playerid][pID], GangInfo[PlayerInfo[playerid][pGang]][gName], PlayerInfo[playerid][pGang]);
							}
							case 2:
					        {
					            if(GangInfo[PlayerInfo[playerid][pGang]][gPoints] < 12000)
				                {
				                    return SendClientMessage(playerid, COLOR_LIGHTRED, "Nhom cua ban khong co du diem.");
								}
								if(PlayerInfo[playerid][pCash] < 100000)
								{
								    return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban can co 100.000 do la trong tay de mua ban nang cap nay.");
								}

								GangInfo[PlayerInfo[playerid][pGang]][gLevel] = 3;
								GangInfo[PlayerInfo[playerid][pGang]][gPoints] -= 12000;

								mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET level = 3, points = %i WHERE id = %i", GangInfo[PlayerInfo[playerid][pGang]][gPoints], PlayerInfo[playerid][pGang]);
								mysql_tquery(connectionID, queryBuffer);

								GivePlayerCash(playerid, -100000);
								ReloadGang(PlayerInfo[playerid][pGang]);

								SendClientMessageEx(playerid, COLOR_GREEN, "Ban da su dung 12000 GP & $100,000 cho gang level 3/3. Bang dang cua ban se co %i thanh vien & %i phuong tien giao thong cua bang dang.", GetGangMemberLimit(PlayerInfo[playerid][pGang]), GetGangVehicleLimit(PlayerInfo[playerid][pGang]));
								SendClientMessage(playerid, COLOR_GREEN, "Khoang trong cua bang dang cua ban trong tu khoa da duoc tang len. Mo khoa tu do cua ban de tim hieu them");

								Log_Write("log_gang", "%s (uid: %i) spent 12000 GP & $100000 for gang level 3/3 for %s (id: %i).", GetPlayerNameEx(playerid), PlayerInfo[playerid][pID], GangInfo[PlayerInfo[playerid][pGang]][gName], PlayerInfo[playerid][pGang]);
							}
						}
					}
		        }
		    }
		}
		case DIALOG_GANGARMSPRICES:
		{
		    if(PlayerInfo[playerid][pGang] == -1 || PlayerInfo[playerid][pGangRank] < 5)
		    {
		        return 1;
		    }

		    if(response)
		    {
		        PlayerInfo[playerid][pSelected] = listitem;
		        ShowPlayerDialog(playerid, DIALOG_GANGARMSPRICE, DIALOG_STYLE_INPUT, "Arms dealer | Prices", "Nhap gia cho san pham:", "Chap nhan", "Huy");
		    }
		    else
		    {
		        ShowDialogToPlayer(playerid, DIALOG_GANGARMSEDIT);
			}
		}
		case DIALOG_GANGARMSPRICE:
		{
		    if(PlayerInfo[playerid][pGang] == -1 || PlayerInfo[playerid][pGangRank] < 5)
		    {
		        return 1;
		    }

		    if(response)
		    {
		        new amount;

		        if(sscanf(inputtext, "i", amount))
		        {
		            return ShowPlayerDialog(playerid, DIALOG_GANGARMSPRICE, DIALOG_STYLE_INPUT, "Arms dealer | Prices", "Enter the new price for this item", "Chap nhan", "Huy");
				}
				if(amount < 0)
				{
				    SendClientMessage(playerid, COLOR_LIGHTRED, "The amount can't be below $0.");
				    return ShowPlayerDialog(playerid, DIALOG_GANGARMSPRICE, DIALOG_STYLE_INPUT, "Arms dealer | Prices", "Enter the new price for this item", "Chap nhan", "Huy");
				}

				GangInfo[PlayerInfo[playerid][pGang]][gArmsPrices][PlayerInfo[playerid][pSelected]] = amount;

				mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET armsprice_%i = %i WHERE id = %i", PlayerInfo[playerid][pSelected] + 1, amount, PlayerInfo[playerid][pGang]);
				mysql_tquery(connectionID, queryBuffer);

				if(PlayerInfo[playerid][pSelected] == 0) {
				    SendClientMessageEx(playerid, COLOR_AQUA, "Ban da dieu chinh gia cua {00AA00}Micro Uzi{33CCFF} thanh $%i.", amount);
		        } else if(PlayerInfo[playerid][pSelected] == 1) {
				    SendClientMessageEx(playerid, COLOR_AQUA, "Ban da dieu chinh gia cua {00AA00}Tec-9{33CCFF} thanh $%i.", amount);
		        } else if(PlayerInfo[playerid][pSelected] == 2) {
				    SendClientMessageEx(playerid, COLOR_AQUA, "Ban da dieu chinh gia cua {00AA00}MP5{33CCFF} thanh $%i.", amount);
		        } else if(PlayerInfo[playerid][pSelected] == 3) {
				    SendClientMessageEx(playerid, COLOR_AQUA, "Ban da dieu chinh gia cua {00AA00}Desert Eagle{33CCFF} thanh $%i.", amount);
		        } else if(PlayerInfo[playerid][pSelected] == 4) {
				    SendClientMessageEx(playerid, COLOR_AQUA, "Ban da dieu chinh gia cua {00AA00}Molotov{33CCFF} thanh $%i.", amount);
		        } else if(PlayerInfo[playerid][pSelected] == 5) {
				    SendClientMessageEx(playerid, COLOR_AQUA, "Ban da dieu chinh gia cua {00AA00}AK-47{33CCFF} thanh $%i.", amount);
		        } else if(PlayerInfo[playerid][pSelected] == 6) {
				    SendClientMessageEx(playerid, COLOR_AQUA, "Ban da dieu chinh gia cua {00AA00}M4{33CCFF} thanh $%i.", amount);
		        } else if(PlayerInfo[playerid][pSelected] == 7) {
				    SendClientMessageEx(playerid, COLOR_AQUA, "Ban da dieu chinh gia cua {00AA00}Sniper{33CCFF} thanh $%i.", amount);
		        } else if(PlayerInfo[playerid][pSelected] == 8) {
				    SendClientMessageEx(playerid, COLOR_AQUA, "Ban da dieu chinh gia cua {00AA00}Sawnoff Shotgun{33CCFF} thanh $%i.", amount);
		        }
		    }

		    ShowDialogToPlayer(playerid, DIALOG_GANGARMSPRICES);
		}
		case DIALOG_GANGARMSDEALER:
		{
		    if(!IsPlayerInRangeOfPoint(playerid, 3.0, GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsX], GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsY], GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsZ]))
		    {
		        return 1;
			}

			if(response)
			{
			    if(listitem == 0)
			    {
					ShowDialogToPlayer(playerid, DIALOG_GANGARMSWEAPONS);
				}
				else if(listitem == 1)
				{
				    if(PlayerInfo[playerid][pGang] != PlayerInfo[playerid][pDealerGang])
				    {
				        return SendClientMessage(playerid, COLOR_LIGHTRED, "Nguoi buon ban vu khi nay khong thuoc bang dang cua ban.");
				    }
				    if(PlayerInfo[playerid][pGangRank] < 6)
				    {
				        return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban can co rank 6+ de dieu chinh.");
					}

					ShowDialogToPlayer(playerid, DIALOG_GANGARMSEDIT);
				}
			}
		}
		case DIALOG_GANGARMSWEAPONS:
		{
		    if(!IsPlayerInRangeOfPoint(playerid, 3.0, GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsX], GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsY], GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsZ]))
		    {
		        return 1;
			}

			if(response)
			{
			    switch(listitem)
			    {
			        case 0:
			        {
			            if(GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsMaterials] < 500)
			            {
			                return SendClientMessage(playerid, COLOR_LIGHTRED, "Nguoi che tao vu khi nay khong du vat lieu cho vu khi nay.");
						}
						if(PlayerInfo[playerid][pCash] < GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsPrices][listitem])
						{
						    return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong the mua vu khi nay.");
			            }

			            GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsMaterials] -= 500;
			            GangInfo[PlayerInfo[playerid][pDealerGang]][gCash] += GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsPrices][listitem];

			            mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET armsmaterials = %i, cash = %i WHERE id = %i", GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsMaterials], GangInfo[PlayerInfo[playerid][pDealerGang]][gCash], PlayerInfo[playerid][pDealerGang]);
			            mysql_tquery(connectionID, queryBuffer);

			            GivePlayerCash(playerid, -GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsPrices][listitem]);
			            GivePlayerWeaponEx(playerid, 28);

			            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da thanh toan $%i cho nguoi ban vu khi de nhan khau sung UZI.", GetPlayerRPName(playerid), GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsPrices][listitem]);
			            SendClientMessageEx(playerid, COLOR_AQUA, "Ban da mua {00AA00}micro uzi{33CCFF} voi $%i.", GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsPrices][listitem]);
			        }
			        case 1:
			        {
			            if(GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsMaterials] < 500)
			            {
			                return SendClientMessage(playerid, COLOR_LIGHTRED, "Nguoi che tao vu khi nay khong du vat lieu cho vu khi nay.");
						}
						if(PlayerInfo[playerid][pCash] < GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsPrices][listitem])
						{
						    return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong the mua vu khi nay.");
			            }

			            GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsMaterials] -= 500;
			            GangInfo[PlayerInfo[playerid][pDealerGang]][gCash] += GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsPrices][listitem];

			            mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET armsmaterials = %i, cash = %i WHERE id = %i", GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsMaterials], GangInfo[PlayerInfo[playerid][pDealerGang]][gCash], PlayerInfo[playerid][pDealerGang]);
			            mysql_tquery(connectionID, queryBuffer);

			            GivePlayerCash(playerid, -GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsPrices][listitem]);
			            GivePlayerWeaponEx(playerid, 32);

			            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da thanh toan $%i cho nguoi ban vu khi de nhan khau sung Tec-9.", GetPlayerRPName(playerid), GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsPrices][listitem]);
			            SendClientMessageEx(playerid, COLOR_AQUA, "Ban da mua 1  {00AA00}Tec-9{33CCFF} for $%i.", GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsPrices][listitem]);
			        }
			        case 2:
			        {
			            if(GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsMaterials] < 1000)
			            {
			                return SendClientMessage(playerid, COLOR_LIGHTRED, "Nguoi che tao vu khi nay khong du vat lieu cho vu khi nay.");
						}
						if(PlayerInfo[playerid][pCash] < GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsPrices][listitem])
						{
						    return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong the mua vu khi nay.");
			            }

			            GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsMaterials] -= 1000;
			            GangInfo[PlayerInfo[playerid][pDealerGang]][gCash] += GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsPrices][listitem];

			            mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET armsmaterials = %i, cash = %i WHERE id = %i", GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsMaterials], GangInfo[PlayerInfo[playerid][pDealerGang]][gCash], PlayerInfo[playerid][pDealerGang]);
			            mysql_tquery(connectionID, queryBuffer);

			            GivePlayerCash(playerid, -GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsPrices][listitem]);
			            GivePlayerWeaponEx(playerid, 29);

			            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da thanh toan $%i cho nguoi ban vu khi de nhan khau sungn MP5.", GetPlayerRPName(playerid), GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsPrices][listitem]);
			            SendClientMessageEx(playerid, COLOR_AQUA, "Ban da mua 1 {00AA00}MP5{33CCFF} for $%i.", GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsPrices][listitem]);
			        }
			        case 3:
			        {
			            if(GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsMaterials] < 2000)
			            {
			                return SendClientMessage(playerid, COLOR_LIGHTRED, "Nguoi che tao vu khi nay khong du vat lieu cho vu khi nay.");
						}
						if(PlayerInfo[playerid][pCash] < GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsPrices][listitem])
						{
						    return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong the mua vu khi nay.");
			            }

			            GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsMaterials] -= 2000;
			            GangInfo[PlayerInfo[playerid][pDealerGang]][gCash] += GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsPrices][listitem];

			            mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET armsmaterials = %i, cash = %i WHERE id = %i", GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsMaterials], GangInfo[PlayerInfo[playerid][pDealerGang]][gCash], PlayerInfo[playerid][pDealerGang]);
			            mysql_tquery(connectionID, queryBuffer);

			            GivePlayerCash(playerid, -GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsPrices][listitem]);
			            GivePlayerWeaponEx(playerid, 24);

			            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da thanh toan $%i cho nguoi ban vu khi de nhan khau sung Desert Eagle.", GetPlayerRPName(playerid), GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsPrices][listitem]);
			            SendClientMessageEx(playerid, COLOR_AQUA, "Ban da mua 1 {00AA00}Desert Eagle{33CCFF} for $%i.", GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsPrices][listitem]);
			        }
			        case 4:
			        {
			            if(GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsMaterials] < 5000)
			            {
			                return SendClientMessage(playerid, COLOR_LIGHTRED, "Nguoi che tao vu khi nay khong du vat lieu cho vu khi nay.");
						}
						if(PlayerInfo[playerid][pCash] < GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsPrices][listitem])
						{
						    return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong the mua vu khi nay.");
			            }

			            GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsMaterials] -= 5000;
			            GangInfo[PlayerInfo[playerid][pDealerGang]][gCash] += GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsPrices][listitem];

			            mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET armsmaterials = %i, cash = %i WHERE id = %i", GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsMaterials], GangInfo[PlayerInfo[playerid][pDealerGang]][gCash], PlayerInfo[playerid][pDealerGang]);
			            mysql_tquery(connectionID, queryBuffer);

			            GivePlayerCash(playerid, -GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsPrices][listitem]);
			            GivePlayerWeaponEx(playerid, 18);

			            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da thanh toan $%i cho nguoi ban vu khi de nhan khau sung molotov.", GetPlayerRPName(playerid), GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsPrices][listitem]);
			            SendClientMessageEx(playerid, COLOR_AQUA, "Ban da mua 1  {00AA00}molotov{33CCFF} for $%i.", GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsPrices][listitem]);
			        }
			        case 5:
			        {
			            if(GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsMaterials] < 3000)
			            {
			                return SendClientMessage(playerid, COLOR_LIGHTRED, "Nguoi che tao vu khi nay khong du vat lieu cho vu khi nay.");
						}
						if(PlayerInfo[playerid][pCash] < GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsPrices][listitem])
						{
						    return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong the mua vu khi nay.");
			            }

			            GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsMaterials] -= 3000;
			            GangInfo[PlayerInfo[playerid][pDealerGang]][gCash] += GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsPrices][listitem];

			            mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET armsmaterials = %i, cash = %i WHERE id = %i", GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsMaterials], GangInfo[PlayerInfo[playerid][pDealerGang]][gCash], PlayerInfo[playerid][pDealerGang]);
			            mysql_tquery(connectionID, queryBuffer);

			            GivePlayerCash(playerid, -GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsPrices][listitem]);
			            GivePlayerWeaponEx(playerid, 30);

			            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da thanh toan $%i cho nguoi ban vu khi de nhan khau sungn AK-47.", GetPlayerRPName(playerid), GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsPrices][listitem]);
			            SendClientMessageEx(playerid, COLOR_AQUA, "Ban da mua 1 n {00AA00}AK-47{33CCFF} for $%i.", GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsPrices][listitem]);
			        }
			        case 6:
			        {
			            if(GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsMaterials] < 4000)
			            {
			                return SendClientMessage(playerid, COLOR_LIGHTRED, "Nguoi che tao vu khi nay khong du vat lieu cho vu khi nay.");
						}
						if(PlayerInfo[playerid][pCash] < GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsPrices][listitem])
						{
						    return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong the mua vu khi nay.");
			            }

			            GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsMaterials] -= 4000;
			            GangInfo[PlayerInfo[playerid][pDealerGang]][gCash] += GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsPrices][listitem];

			            mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET armsmaterials = %i, cash = %i WHERE id = %i", GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsMaterials], GangInfo[PlayerInfo[playerid][pDealerGang]][gCash], PlayerInfo[playerid][pDealerGang]);
			            mysql_tquery(connectionID, queryBuffer);

			            GivePlayerCash(playerid, -GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsPrices][listitem]);
			            GivePlayerWeaponEx(playerid, 31);

			            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da thanh toan $%i cho nguoi ban vu khi de nhan khau sungn M4.", GetPlayerRPName(playerid), GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsPrices][listitem]);
			            SendClientMessageEx(playerid, COLOR_AQUA, "Ban da mua 1 n {00AA00}M4{33CCFF} for $%i.", GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsPrices][listitem]);
			        }
			        case 7:
			        {
			            if(GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsMaterials] < 6500)
			            {
			                return SendClientMessage(playerid, COLOR_LIGHTRED, "Nguoi che tao vu khi nay khong du vat lieu cho vu khi nay.");
						}
						if(PlayerInfo[playerid][pCash] < GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsPrices][listitem])
						{
						    return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong the mua vu khi nay.");
			            }

			            GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsMaterials] -= 6500;
			            GangInfo[PlayerInfo[playerid][pDealerGang]][gCash] += GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsPrices][listitem];

			            mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET armsmaterials = %i, cash = %i WHERE id = %i", GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsMaterials], GangInfo[PlayerInfo[playerid][pDealerGang]][gCash], PlayerInfo[playerid][pDealerGang]);
			            mysql_tquery(connectionID, queryBuffer);

			            GivePlayerCash(playerid, -GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsPrices][listitem]);
			            GivePlayerWeaponEx(playerid, 34);

			            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da thanh toan $%i cho nguoi ban vu khi de nhan khau sung sniper.", GetPlayerRPName(playerid), GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsPrices][listitem]);
			            SendClientMessageEx(playerid, COLOR_AQUA, "Ban da mua 1 {00AA00}sniper{33CCFF} for $%i.", GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsPrices][listitem]);
			        }
			        case 8:
			        {
			            if(GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsMaterials] < 3000)
			            {
			                return SendClientMessage(playerid, COLOR_LIGHTRED, "Nguoi che tao vu khi nay khong du vat lieu cho vu khi nay.");
						}
						if(PlayerInfo[playerid][pCash] < GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsPrices][listitem])
						{
						    return SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong the mua vu khi nay.");
			            }

			            GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsMaterials] -= 3000;
			            GangInfo[PlayerInfo[playerid][pDealerGang]][gCash] += GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsPrices][listitem];

			            mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET armsmaterials = %i, cash = %i WHERE id = %i", GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsMaterials], GangInfo[PlayerInfo[playerid][pDealerGang]][gCash], PlayerInfo[playerid][pDealerGang]);
			            mysql_tquery(connectionID, queryBuffer);

			            GivePlayerCash(playerid, -GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsPrices][listitem]);
			            GivePlayerWeaponEx(playerid, 26);

			            SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da thanh toan $%i cho nguoi ban vu khi de nhan khau sung sawnoff shotgun.", GetPlayerRPName(playerid), GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsPrices][listitem]);
			            SendClientMessageEx(playerid, COLOR_AQUA, "Ban da mua 1 {00AA00}sawnoff shotgun{33CCFF} for $%i.", GangInfo[PlayerInfo[playerid][pDealerGang]][gArmsPrices][listitem]);
			        }
				}
			}
			else
		    {
		        ShowDialogToPlayer(playerid, DIALOG_GANGARMSDEALER);
			}
		}

		case DIALOG_GANGARMSEDIT:
		{
		    if(PlayerInfo[playerid][pGang] == -1 || PlayerInfo[playerid][pGangRank] < 6)
		    {
		        return 1;
			}

			if(response)
			{
			    switch(listitem)
			    {
			        case 0: ShowDialogToPlayer(playerid, DIALOG_GANGARMSPRICES);
					case 1: ShowDialogToPlayer(playerid, DIALOG_GANGARMSDEPOSITMATS);
					case 2: ShowDialogToPlayer(playerid, DIALOG_GANGARMSWITHDRAWMATS);
			    }
			}
			else
			{
			    ShowDialogToPlayer(playerid, DIALOG_GANGARMSDEALER);
			}
		}
		case DIALOG_GANGARMSDEPOSITMATS:
		{
		    if(PlayerInfo[playerid][pGang] == -1 || PlayerInfo[playerid][pGangRank] < 6)
		    {
		        return 1;
			}

			if(response)
			{
			    new amount;

			    if(sscanf(inputtext, "i", amount))
			    {
			        return ShowDialogToPlayer(playerid, DIALOG_GANGARMSDEPOSITMATS);
				}
				if(amount < 1 || amount > PlayerInfo[playerid][pMaterials])
				{
				    SendClientMessage(playerid, COLOR_LIGHTRED, "Khong du tien.");
			        return ShowDialogToPlayer(playerid, DIALOG_GANGARMSDEPOSITMATS);
			    }

			    GangInfo[PlayerInfo[playerid][pGang]][gArmsMaterials] += amount;
			    PlayerInfo[playerid][pMaterials] -= amount;

			    mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET armsmaterials = %i WHERE id = %i", GangInfo[PlayerInfo[playerid][pGang]][gArmsMaterials], PlayerInfo[playerid][pGang]);
				mysql_tquery(connectionID, queryBuffer);

				mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET materials = %i WHERE uid = %i", PlayerInfo[playerid][pMaterials], PlayerInfo[playerid][pID]);
				mysql_tquery(connectionID, queryBuffer);

				SendClientMessageEx(playerid, COLOR_AQUA, "Ban da gui %i vat lieu vao nguoi che tao vu khi NPC.", amount);
			}

			ShowDialogToPlayer(playerid, DIALOG_GANGARMSEDIT);
		}
		case DIALOG_GANGARMSWITHDRAWMATS:
		{
		    if(PlayerInfo[playerid][pGang] == -1 || PlayerInfo[playerid][pGangRank] < 6)
		    {
		        return 1;
			}

			if(response)
			{
			    new amount;

			    if(sscanf(inputtext, "i", amount))
			    {
			        return ShowDialogToPlayer(playerid, DIALOG_GANGARMSWITHDRAWMATS);
				}
				if(amount < 1 || amount > GangInfo[PlayerInfo[playerid][pGang]][gArmsMaterials])
				{
				    SendClientMessage(playerid, COLOR_LIGHTRED, "Khong du tien.");
			        return ShowDialogToPlayer(playerid, DIALOG_GANGARMSWITHDRAWMATS);
			    }

			    GangInfo[PlayerInfo[playerid][pGang]][gArmsMaterials] -= amount;
			    PlayerInfo[playerid][pMaterials] += amount;

			    mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET armsmaterials = %i WHERE id = %i", GangInfo[PlayerInfo[playerid][pGang]][gArmsMaterials], PlayerInfo[playerid][pGang]);
				mysql_tquery(connectionID, queryBuffer);

				mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET materials = %i WHERE uid = %i", PlayerInfo[playerid][pMaterials], PlayerInfo[playerid][pID]);
				mysql_tquery(connectionID, queryBuffer);

				SendClientMessageEx(playerid, COLOR_AQUA, "Ban da lay ra %i materials from your arms dealer NPC.", amount);
			}

			ShowDialogToPlayer(playerid, DIALOG_GANGARMSEDIT);
		}

		case DIALOG_GANGDRUGDEALER:
		{
		    if(!IsPlayerInRangeOfPoint(playerid, 3.0, GangInfo[PlayerInfo[playerid][pDealerGang]][gDrugX], GangInfo[PlayerInfo[playerid][pDealerGang]][gDrugY], GangInfo[PlayerInfo[playerid][pDealerGang]][gDrugZ]))
		    {
		        return 1;
			}

			if(response)
			{
			    if(listitem == 0)
			    {
					ShowDialogToPlayer(playerid, DIALOG_GANGDRUGSHOP);
				}
				else if(listitem == 1)
				{
				    if(PlayerInfo[playerid][pGang] != PlayerInfo[playerid][pDealerGang])
				    {
				        return SendClientMessage(playerid, COLOR_LIGHTRED, "Nguoi buon ma tuy nay khong thuoc bang dang cua ban.");
				    }
				    if(PlayerInfo[playerid][pGangRank] < 6)
				    {
				        return SendClientMessage(playerid, COLOR_LIGHTRED, "You need to be rank 6+ in order to edit.");
					}

					ShowDialogToPlayer(playerid, DIALOG_GANGDRUGEDIT);
				}
			}
		}
		case DIALOG_GANGDRUGSHOP:
		{
		    if(!IsPlayerInRangeOfPoint(playerid, 3.0, GangInfo[PlayerInfo[playerid][pDealerGang]][gDrugX], GangInfo[PlayerInfo[playerid][pDealerGang]][gDrugY], GangInfo[PlayerInfo[playerid][pDealerGang]][gDrugZ]))
		    {
		        return 1;
			}

			if(response)
			{
			    PlayerInfo[playerid][pSelected] = listitem;
			    ShowDialogToPlayer(playerid, DIALOG_GANGDRUGBUY);
			}
			else
			{
			    ShowDialogToPlayer(playerid, DIALOG_GANGDRUGDEALER);
			}
		}
		case DIALOG_GANGDRUGBUY:
		{
            if(!IsPlayerInRangeOfPoint(playerid, 3.0, GangInfo[PlayerInfo[playerid][pDealerGang]][gDrugX], GangInfo[PlayerInfo[playerid][pDealerGang]][gDrugY], GangInfo[PlayerInfo[playerid][pDealerGang]][gDrugZ]))
		    {
		        return 1;
			}

			if(response)
			{
			    new amount;

			    switch(PlayerInfo[playerid][pSelected])
			    {
			        case 0: // Weed
			        {
			            if(sscanf(inputtext, "i", amount))
			            {
			                return ShowDialogToPlayer(playerid, DIALOG_GANGDRUGBUY);
						}
						if(amount < 1 || amount > GangInfo[PlayerInfo[playerid][pDealerGang]][gDrugWeed])
						{
						    SendClientMessage(playerid, COLOR_LIGHTRED, "Khong du tien.");
						    return ShowDialogToPlayer(playerid, DIALOG_GANGDRUGBUY);
			            }
			            if(PlayerInfo[playerid][pCash] < GangInfo[PlayerInfo[playerid][pDealerGang]][gDrugPrices][0] * amount)
			            {
			                SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong the mua so luong thuoc phien nay.");
			                return ShowDialogToPlayer(playerid, DIALOG_GANGDRUGBUY);
			            }
			            if(PlayerInfo[playerid][pWeed] + amount > GetPlayerCapacity(playerid, CAPACITY_WEED))
			            {
			                SendClientMessageEx(playerid, COLOR_LIGHTRED, "Ban rat muon %i/%i weed. Ban khong the mang theo nua cho den khi ban nang cap Inventory.", PlayerInfo[playerid][pWeed], GetPlayerCapacity(playerid, CAPACITY_WEED));
			                return ShowDialogToPlayer(playerid, DIALOG_GANGDRUGBUY);
						}

						new cost = GangInfo[PlayerInfo[playerid][pDealerGang]][gDrugPrices][0] * amount;

						GangInfo[PlayerInfo[playerid][pDealerGang]][gDrugWeed] -= amount;
						GangInfo[PlayerInfo[playerid][pDealerGang]][gCash] += cost;

						PlayerInfo[playerid][pWeed] += amount;
						GivePlayerCash(playerid, -cost);

						mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET drugweed = %i, cash = %i WHERE id = %i", GangInfo[PlayerInfo[playerid][pDealerGang]][gDrugWeed], GangInfo[PlayerInfo[playerid][pDealerGang]][gCash], PlayerInfo[playerid][pDealerGang]);
						mysql_tquery(connectionID, queryBuffer);

						mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET weed = %i WHERE uid = %i", PlayerInfo[playerid][pWeed], PlayerInfo[playerid][pID]);
						mysql_tquery(connectionID, queryBuffer);

						SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da thanh toan $%i cho nguoi ban thuoc phien va nhan duoc %i gram weed.", GetPlayerRPName(playerid), cost, amount);
						SendClientMessageEx(playerid, COLOR_AQUA, "Ban da mua %i gram {00AA00}weed{33CCFF} for $%i.", amount, cost);
					}
					case 1: // Cocaine
			        {
			            if(sscanf(inputtext, "i", amount))
			            {
			                return ShowDialogToPlayer(playerid, DIALOG_GANGDRUGBUY);
						}
						if(amount < 1 || amount > GangInfo[PlayerInfo[playerid][pDealerGang]][gDrugCocaine])
						{
						    SendClientMessage(playerid, COLOR_LIGHTRED, "Khong du tien.");
						    return ShowDialogToPlayer(playerid, DIALOG_GANGDRUGBUY);
			            }
			            if(PlayerInfo[playerid][pCash] < GangInfo[PlayerInfo[playerid][pDealerGang]][gDrugPrices][1] * amount)
			            {
			                SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong the mua so luong thuoc phien nay.");
			                return ShowDialogToPlayer(playerid, DIALOG_GANGDRUGBUY);
			            }
			            if(PlayerInfo[playerid][pCocaine] + amount > GetPlayerCapacity(playerid, CAPACITY_COCAINE))
			            {
			                SendClientMessageEx(playerid, COLOR_LIGHTRED, "Ban rat muon %i/%i cocaine. Ban khong the mang theo nua cho den khi ban nang cap Inventory.", PlayerInfo[playerid][pCocaine], GetPlayerCapacity(playerid, CAPACITY_COCAINE));
			                return ShowDialogToPlayer(playerid, DIALOG_GANGDRUGBUY);
						}

						new cost = GangInfo[PlayerInfo[playerid][pDealerGang]][gDrugPrices][1] * amount;

						GangInfo[PlayerInfo[playerid][pDealerGang]][gDrugCocaine] -= amount;
						GangInfo[PlayerInfo[playerid][pDealerGang]][gCash] += cost;

						PlayerInfo[playerid][pCocaine] += amount;
						GivePlayerCash(playerid, -cost);

						mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET drugcocaine = %i, cash = %i WHERE id = %i", GangInfo[PlayerInfo[playerid][pDealerGang]][gDrugCocaine], GangInfo[PlayerInfo[playerid][pDealerGang]][gCash], PlayerInfo[playerid][pDealerGang]);
						mysql_tquery(connectionID, queryBuffer);

						mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET cocaine = %i WHERE uid = %i", PlayerInfo[playerid][pCocaine], PlayerInfo[playerid][pID]);
						mysql_tquery(connectionID, queryBuffer);

						SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da thanh toan $%i cho nguoi ban thuoc phien va nhan duoc %i gram cocaine.", GetPlayerRPName(playerid), cost, amount);
						SendClientMessageEx(playerid, COLOR_AQUA, "Ban da mua %i grams of {00AA00}cocaine{33CCFF} for $%i.", amount, cost);
					}
					case 2: // Meth
			        {
			            if(sscanf(inputtext, "i", amount))
			            {
			                return ShowDialogToPlayer(playerid, DIALOG_GANGDRUGBUY);
						}
						if(amount < 1 || amount > GangInfo[PlayerInfo[playerid][pDealerGang]][gDrugMeth])
						{
						    SendClientMessage(playerid, COLOR_LIGHTRED, "Khong du tien.");
						    return ShowDialogToPlayer(playerid, DIALOG_GANGDRUGBUY);
			            }
			            if(PlayerInfo[playerid][pCash] < GangInfo[PlayerInfo[playerid][pDealerGang]][gDrugPrices][2] * amount)
			            {
			                SendClientMessage(playerid, COLOR_LIGHTRED, "Ban khong the mua so luong thuoc phien nay.");
			                return ShowDialogToPlayer(playerid, DIALOG_GANGDRUGBUY);
			            }
			            if(PlayerInfo[playerid][pMeth] + amount > GetPlayerCapacity(playerid, CAPACITY_METH))
			            {
			                SendClientMessageEx(playerid, COLOR_LIGHTRED, "Ban rat muon %i/%i gram meth. Ban khong the mang theo nua cho den khi ban nang cap Inventory.", PlayerInfo[playerid][pMeth], GetPlayerCapacity(playerid, CAPACITY_METH));
			                return ShowDialogToPlayer(playerid, DIALOG_GANGDRUGBUY);
						}

						new cost = GangInfo[PlayerInfo[playerid][pDealerGang]][gDrugPrices][2] * amount;

						GangInfo[PlayerInfo[playerid][pDealerGang]][gDrugMeth] -= amount;
						GangInfo[PlayerInfo[playerid][pDealerGang]][gCash] += cost;

						PlayerInfo[playerid][pMeth] += amount;
						GivePlayerCash(playerid, -cost);

						mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET drugmeth = %i, cash = %i WHERE id = %i", GangInfo[PlayerInfo[playerid][pDealerGang]][gDrugMeth], GangInfo[PlayerInfo[playerid][pDealerGang]][gCash], PlayerInfo[playerid][pDealerGang]);
						mysql_tquery(connectionID, queryBuffer);

						mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET meth = %i WHERE uid = %i", PlayerInfo[playerid][pMeth], PlayerInfo[playerid][pID]);
						mysql_tquery(connectionID, queryBuffer);

						SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da thanh toan $%i cho nguoi ban thuoc phien va nhan duoc %i gram meth.", GetPlayerRPName(playerid), cost, amount);
						SendClientMessageEx(playerid, COLOR_AQUA, "Ban da mua %i gram {00AA00}meth{33CCFF} voi $%i.", amount, cost);
					}
			    }
			}
			else
			{
			    ShowDialogToPlayer(playerid, DIALOG_GANGDRUGSHOP);
			}
		}
        case DIALOG_GANGDRUGEDIT:
		{
		    if(PlayerInfo[playerid][pGang] == -1 || PlayerInfo[playerid][pGangRank] < 6)
		    {
		        return 1;
			}

			if(response)
			{
			    switch(listitem)
			    {
			        case 0: ShowDialogToPlayer(playerid, DIALOG_GANGDRUGPRICES);
					case 1: ShowDialogToPlayer(playerid, DIALOG_GANGDRUGDEPOSITS);
					case 2: ShowDialogToPlayer(playerid, DIALOG_GANGDRUGWITHDRAWS);
			    }
			}
			else
			{
			    ShowDialogToPlayer(playerid, DIALOG_GANGDRUGDEALER);
			}
		}
        case DIALOG_GANGDRUGPRICES:
		{
		    if(PlayerInfo[playerid][pGang] == -1 || PlayerInfo[playerid][pGangRank] < 5)
		    {
		        return 1;
		    }

		    if(response)
		    {
		        PlayerInfo[playerid][pSelected] = listitem;
		        ShowPlayerDialog(playerid, DIALOG_GANGDRUGPRICE, DIALOG_STYLE_INPUT, "Drug dealer | Prices", "Nhap gia moi cho loai thuoc phien nay:", "Chap nhan", "Huy");
		    }
		    else
		    {
		        ShowDialogToPlayer(playerid, DIALOG_GANGDRUGEDIT);
			}
		}
		case DIALOG_GANGDRUGPRICE:
		{
		    if(PlayerInfo[playerid][pGang] == -1 || PlayerInfo[playerid][pGangRank] < 5)
		    {
		        return 1;
		    }

		    if(response)
		    {
		        new amount;

		        if(sscanf(inputtext, "i", amount))
		        {
		            return ShowPlayerDialog(playerid, DIALOG_GANGDRUGPRICE, DIALOG_STYLE_INPUT, "Drug dealer | Prices", "Nhap gia moi cho loai thuoc phien nay:", "Chap nhan", "Huy");
				}
				if(amount < 0)
				{
				    SendClientMessage(playerid, COLOR_LIGHTRED, "The amount can't be below $0.");
				    return ShowPlayerDialog(playerid, DIALOG_GANGDRUGPRICE, DIALOG_STYLE_INPUT, "Drug dealer | Prices", "Nhap gia moi cho loai thuoc phien nay:", "Chap nhan", "Huy");
				}

				GangInfo[PlayerInfo[playerid][pGang]][gDrugPrices][PlayerInfo[playerid][pSelected]] = amount;

				if(PlayerInfo[playerid][pSelected] == 0) {
				    mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET weed_price = %i WHERE id = %i", amount, PlayerInfo[playerid][pGang]);
				    SendClientMessageEx(playerid, COLOR_AQUA, "Ban da dieu chinh gia cua {00AA00}weed{33CCFF} thanh $%i.", amount);
		        } else if(PlayerInfo[playerid][pSelected] == 1) {
		            mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET cocaine_price = %i WHERE id = %i", amount, PlayerInfo[playerid][pGang]);
				    SendClientMessageEx(playerid, COLOR_AQUA, "Ban da dieu chinh gia cua {00AA00}cocaine{33CCFF} thanh $%i.", amount);
		        } else if(PlayerInfo[playerid][pSelected] == 2) {
		            mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET meth_price = %i WHERE id = %i", amount, PlayerInfo[playerid][pGang]);
				    SendClientMessageEx(playerid, COLOR_AQUA, "Ban da dieu chinh gia cua {00AA00}meth{33CCFF} thanh $%i.", amount);
		        }

		        mysql_tquery(connectionID, queryBuffer);
		    }

		    ShowDialogToPlayer(playerid, DIALOG_GANGDRUGPRICES);
		}
		case DIALOG_GANGDRUGDEPOSITS:
		{
		    if(PlayerInfo[playerid][pGang] == -1 || PlayerInfo[playerid][pGangRank] < 5)
		    {
		        return 1;
		    }

		    if(response)
		    {
		        PlayerInfo[playerid][pSelected] = listitem;
		        ShowDialogToPlayer(playerid, DIALOG_GANGDRUGDEPOSIT);
			}
			else
			{
			    ShowDialogToPlayer(playerid, DIALOG_GANGDRUGEDIT);
		    }
		}
		case DIALOG_GANGDRUGWITHDRAWS:
		{
		    if(PlayerInfo[playerid][pGang] == -1 || PlayerInfo[playerid][pGangRank] < 5)
		    {
		        return 1;
		    }

		    if(response)
		    {
		        PlayerInfo[playerid][pSelected] = listitem;
		        ShowDialogToPlayer(playerid, DIALOG_GANGDRUGWITHDRAW);
			}
			else
			{
			    ShowDialogToPlayer(playerid, DIALOG_GANGDRUGEDIT);
		    }
		}
		case DIALOG_GANGDRUGDEPOSIT:
		{
		    if(PlayerInfo[playerid][pGang] == -1 || PlayerInfo[playerid][pGangRank] < 5)
		    {
		        return 1;
		    }

		    if(response)
		    {
		        new amount;

		        switch(PlayerInfo[playerid][pSelected])
		        {
		            case 0: // Weed
		            {
		                if(sscanf(inputtext, "i", amount))
			            {
			                return ShowDialogToPlayer(playerid, DIALOG_GANGDRUGDEPOSIT);
						}
						if(amount < 1 || amount > PlayerInfo[playerid][pWeed])
						{
						    SendClientMessage(playerid, COLOR_LIGHTRED, "Khong du tien.");
						    return ShowDialogToPlayer(playerid, DIALOG_GANGDRUGDEPOSIT);
			            }

						GangInfo[PlayerInfo[playerid][pGang]][gDrugWeed] += amount;
						PlayerInfo[playerid][pWeed] -= amount;

						mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET drugweed = %i WHERE id = %i", GangInfo[PlayerInfo[playerid][pGang]][gDrugWeed], PlayerInfo[playerid][pDealerGang]);
						mysql_tquery(connectionID, queryBuffer);

						mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET weed = %i WHERE uid = %i", PlayerInfo[playerid][pWeed], PlayerInfo[playerid][pID]);
						mysql_tquery(connectionID, queryBuffer);

						SendClientMessageEx(playerid, COLOR_AQUA, "Ban da gui %i gram {00AA00}weed{33CCFF} vao NPC ban thuoc phien.", amount);
					}
					case 1: // Cocaine
		            {
		                if(sscanf(inputtext, "i", amount))
			            {
			                return ShowDialogToPlayer(playerid, DIALOG_GANGDRUGDEPOSIT);
						}
						if(amount < 1 || amount > PlayerInfo[playerid][pCocaine])
						{
						    SendClientMessage(playerid, COLOR_LIGHTRED, "Khong du tien.");
						    return ShowDialogToPlayer(playerid, DIALOG_GANGDRUGDEPOSIT);
			            }

						GangInfo[PlayerInfo[playerid][pGang]][gDrugCocaine] += amount;
						PlayerInfo[playerid][pCocaine] -= amount;

						mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET drugcocaine = %i WHERE id = %i", GangInfo[PlayerInfo[playerid][pGang]][gDrugCocaine], PlayerInfo[playerid][pDealerGang]);
						mysql_tquery(connectionID, queryBuffer);

						mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET cocaine = %i WHERE uid = %i", PlayerInfo[playerid][pCocaine], PlayerInfo[playerid][pID]);
						mysql_tquery(connectionID, queryBuffer);

						SendClientMessageEx(playerid, COLOR_AQUA, "Ban da gui %i grams of {00AA00}cocaine{33CCFF} vao NPC ban thuoc phien.", amount);
					}
					case 2: // Meth
		            {
		                if(sscanf(inputtext, "i", amount))
			            {
			                return ShowDialogToPlayer(playerid, DIALOG_GANGDRUGDEPOSIT);
						}
						if(amount < 1 || amount > PlayerInfo[playerid][pMeth])
						{
						    SendClientMessage(playerid, COLOR_LIGHTRED, "Khong du tien.");
						    return ShowDialogToPlayer(playerid, DIALOG_GANGDRUGDEPOSIT);
			            }

						GangInfo[PlayerInfo[playerid][pGang]][gDrugMeth] += amount;
						PlayerInfo[playerid][pMeth] -= amount;

						mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET drugmeth = %i WHERE id = %i", GangInfo[PlayerInfo[playerid][pGang]][gDrugMeth], PlayerInfo[playerid][pDealerGang]);
						mysql_tquery(connectionID, queryBuffer);

						mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET meth = %i WHERE uid = %i", PlayerInfo[playerid][pMeth], PlayerInfo[playerid][pID]);
						mysql_tquery(connectionID, queryBuffer);

						SendClientMessageEx(playerid, COLOR_AQUA, "Ban da gui %i grams {00AA00}meth{33CCFF} trong NPC ban thuoc phien .", amount);
					}
				}
			}

			ShowDialogToPlayer(playerid, DIALOG_GANGDRUGDEPOSITS);
		}
		case DIALOG_GANGDRUGWITHDRAW:
		{
		    if(PlayerInfo[playerid][pGang] == -1 || PlayerInfo[playerid][pGangRank] < 5)
		    {
		        return 1;
		    }

		    if(response)
		    {
		        new amount;

		        switch(PlayerInfo[playerid][pSelected])
		        {
		            case 0: // Weed
		            {
		                if(sscanf(inputtext, "i", amount))
			            {
			                return ShowDialogToPlayer(playerid, DIALOG_GANGDRUGWITHDRAW);
						}
						if(amount < 1 || amount > GangInfo[PlayerInfo[playerid][pGang]][gDrugWeed])
						{
						    SendClientMessage(playerid, COLOR_LIGHTRED, "Khong du tien.");
						    return ShowDialogToPlayer(playerid, DIALOG_GANGDRUGWITHDRAW);
			            }
			            if(PlayerInfo[playerid][pWeed] + amount > GetPlayerCapacity(playerid, CAPACITY_WEED))
			            {
			                SendClientMessageEx(playerid, COLOR_LIGHTRED, "Ban rat muon %i/%i weed. Ban khong the mang theo nua cho den khi ban nang cap Inventory.", PlayerInfo[playerid][pWeed], GetPlayerCapacity(playerid, CAPACITY_WEED));
			                return ShowDialogToPlayer(playerid, DIALOG_GANGDRUGWITHDRAW);
						}

						GangInfo[PlayerInfo[playerid][pGang]][gDrugWeed] -= amount;
						PlayerInfo[playerid][pWeed] += amount;

						mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET drugweed = %i WHERE id = %i", GangInfo[PlayerInfo[playerid][pGang]][gDrugWeed], PlayerInfo[playerid][pGang]);
						mysql_tquery(connectionID, queryBuffer);

						mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET weed = %i WHERE uid = %i", PlayerInfo[playerid][pWeed], PlayerInfo[playerid][pID]);
						mysql_tquery(connectionID, queryBuffer);

						SendClientMessageEx(playerid, COLOR_AQUA, "Ban da lay ra %i grams of {00AA00}weed{33CCFF} tu NPC ban thuoc phien.", amount);
					}
					case 1: // Cocaine
		            {
		                if(sscanf(inputtext, "i", amount))
			            {
			                return ShowDialogToPlayer(playerid, DIALOG_GANGDRUGWITHDRAW);
						}
						if(amount < 1 || amount > GangInfo[PlayerInfo[playerid][pGang]][gDrugCocaine])
						{
						    SendClientMessage(playerid, COLOR_LIGHTRED, "Khong du tien.");
						    return ShowDialogToPlayer(playerid, DIALOG_GANGDRUGWITHDRAW);
			            }
			            if(PlayerInfo[playerid][pCocaine] + amount > GetPlayerCapacity(playerid, CAPACITY_COCAINE))
			            {
			                SendClientMessageEx(playerid, COLOR_LIGHTRED, "Ban rat muon %i/%i cocaine. Ban khong the mang theo nua cho den khi ban nang cap Inventory.", PlayerInfo[playerid][pCocaine], GetPlayerCapacity(playerid, CAPACITY_COCAINE));
			                return ShowDialogToPlayer(playerid, DIALOG_GANGDRUGWITHDRAW);
						}

						GangInfo[PlayerInfo[playerid][pGang]][gDrugCocaine] -= amount;
						PlayerInfo[playerid][pCocaine] += amount;

						mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET drugcocaine = %i WHERE id = %i", GangInfo[PlayerInfo[playerid][pGang]][gDrugCocaine], PlayerInfo[playerid][pGang]);
						mysql_tquery(connectionID, queryBuffer);

						mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET cocaine = %i WHERE uid = %i", PlayerInfo[playerid][pCocaine], PlayerInfo[playerid][pID]);
						mysql_tquery(connectionID, queryBuffer);

						SendClientMessageEx(playerid, COLOR_AQUA, "Ban da lay ra %i grams of {00AA00}cocaine{33CCFF} tu NPC ban thuoc phien.", amount);
					}
					case 2: // Meth
		            {
		                if(sscanf(inputtext, "i", amount))
			            {
			                return ShowDialogToPlayer(playerid, DIALOG_GANGDRUGWITHDRAW);
						}
						if(amount < 1 || amount > GangInfo[PlayerInfo[playerid][pGang]][gDrugMeth])
						{
						    SendClientMessage(playerid, COLOR_LIGHTRED, "Khong du tien.");
						    return ShowDialogToPlayer(playerid, DIALOG_GANGDRUGWITHDRAW);
			            }
			            if(PlayerInfo[playerid][pMeth] + amount > GetPlayerCapacity(playerid, CAPACITY_METH))
			            {
			                SendClientMessageEx(playerid, COLOR_LIGHTRED, "Ban rat muon %i/%i meth. Ban khong the mang theo nua cho den khi ban nang cap Inventory.", PlayerInfo[playerid][pMeth], GetPlayerCapacity(playerid, CAPACITY_METH));
			                return ShowDialogToPlayer(playerid, DIALOG_GANGDRUGWITHDRAW);
						}

						GangInfo[PlayerInfo[playerid][pGang]][gDrugMeth] -= amount;
						PlayerInfo[playerid][pMeth] += amount;

						mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE gangs SET drugmeth = %i WHERE id = %i", GangInfo[PlayerInfo[playerid][pGang]][gDrugMeth], PlayerInfo[playerid][pGang]);
						mysql_tquery(connectionID, queryBuffer);

						mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET meth = %i WHERE uid = %i", PlayerInfo[playerid][pMeth], PlayerInfo[playerid][pID]);
						mysql_tquery(connectionID, queryBuffer);

						SendClientMessageEx(playerid, COLOR_AQUA, "Ban da lay ra %i grams of {00AA00}meth{33CCFF} tu NPC ban thuoc phien.", amount);
					}
				}
			}

			ShowDialogToPlayer(playerid, DIALOG_GANGDRUGWITHDRAWS);
		}
		case DIALOG_FREENAMECHANGE:
		{
		    if(response)
		    {
		        if(isnull(inputtext))
		        {
		            if(!IsPlayerLoggedIn(playerid))
					{
						SendClientMessage(playerid, COLOR_LIGHTRED, "Please reconnect with a proper roleplay name in the Firstname_Lastname format.");
			        	KickPlayer(playerid);
			        	return 1;
					}
		            return ShowPlayerDialog(playerid, DIALOG_FREENAMECHANGE, DIALOG_STYLE_INPUT, "Non-RP Name", "Mot administrator da canh bao rang ten cua ban bi vi pham Non-RP.\nvi vay, ban se duoc nhan 1 vi doi ten mien phi de thay doi ten cua ban.\n\nNhap ten cua ban theo mau Ho_Ten trong dialog duoi day:", "Chap nhan", "Huy bo");
				}
				if(!(3 <= strlen(inputtext) <= 20))
				{
				    SendClientMessage(playerid, COLOR_LIGHTRED, "Your name must contain 3 to 20 characters.");
				    return ShowPlayerDialog(playerid, DIALOG_FREENAMECHANGE, DIALOG_STYLE_INPUT, "Non-RP Name", "Mot administrator da canh bao rang ten cua ban bi vi pham Non-RP.\nvi vay, ban se duoc nhan 1 vi doi ten mien phi de thay doi ten cua ban.\n\nNhap ten cua ban theo mau Ho_Ten trong dialog duoi day:", "Chap nhan", "Huy bo");
				}
				if(strfind(inputtext, "_") == -1)
				{
				    SendClientMessage(playerid, COLOR_LIGHTRED, "The name needs to contain at least one underscore.");
				    return ShowPlayerDialog(playerid, DIALOG_FREENAMECHANGE, DIALOG_STYLE_INPUT, "Non-RP Name", "Mot administrator da canh bao rang ten cua ban bi vi pham Non-RP.\nvi vay, ban se duoc nhan 1 vi doi ten mien phi de thay doi ten cua ban.\n\nNhap ten cua ban theo mau Ho_Ten trong dialog duoi day:", "Chap nhan", "Huy bo");
				}
                if(!IsValidName(inputtext))
                {
				    SendClientMessage(playerid, COLOR_LIGHTRED, "That name is not supported by SA-MP.");
				    return ShowPlayerDialog(playerid, DIALOG_FREENAMECHANGE, DIALOG_STYLE_INPUT, "Non-RP Name", "Mot administrator da canh bao rang ten cua ban bi vi pham Non-RP.\nvi vay, ban se duoc nhan 1 vi doi ten mien phi de thay doi ten cua ban.\n\nNhap ten cua ban theo mau Ho_Ten trong dialog duoi day:", "Chap nhan", "Huy bo");
				}

		        PlayerInfo[playerid][pFreeNamechange] = 1;

		        mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "SELECT uid FROM users WHERE username = '%e'", inputtext);
		        mysql_tquery(connectionID, queryBuffer, "OnPlayerAttemptNameChange", "is", playerid, inputtext);
		    }
		    else
		    {
		        if(!PlayerInfo[playerid][pLogged])
		        {
		            SendAdminMessage(COLOR_YELLOW, "AdmWarning: %s[%i] has been kicked for failing to change their name.", GetPlayerRPName(playerid), playerid);
		            KickPlayer(playerid);
		        }
		        else
		        {
			    	PlayerInfo[playerid][pJailType] = 2;
				    PlayerInfo[playerid][pJailTime] = 20 * 60;

					ResetPlayerWeaponsEx(playerid);
					ResetPlayer(playerid);

					SetPlayerInJail(playerid);
					GameTextForPlayer(playerid, "~w~Welcome to~n~~r~admin jail", 5000, 3);

					mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET prisonedby = 'Server', prisonreason = 'failing to change their name' WHERE uid = %i", PlayerInfo[playerid][pID]);
					mysql_tquery(connectionID, queryBuffer);

					strins(PlayerInfo[playerid][pPrisonedBy], "Server", 0);
					strins(PlayerInfo[playerid][pPrisonReason], "failing to change their name", 0);

	                SendAdminMessage(COLOR_YELLOW, "AdmWarning: %s[%i] da bi bo tu vi NONRP-NAME.", GetPlayerRPName(playerid), playerid);
					Log_Write("log_punishments", "%s (uid: %i) da bi bo tu 20 phut, vi: NonRP-Name.", GetPlayerNameEx(playerid), PlayerInfo[playerid][pID]);

				}
			}
		}
		case DIALOG_REMOVEFLAG:
		{
		    if(response)
		    {
				new targetid = PlayerInfo[playerid][pRemoveFrom];

				if(targetid == INVALID_PLAYER_ID)
				{
				    return SendClientMessage(playerid, COLOR_LIGHTRED, "Nguoi choi da mat ket noi. Bay gio ban co the xoa Flags cua nguoi choi do.");
				}

				mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "SELECT id, description FROM flags WHERE uid = %i LIMIT %i, 1", PlayerInfo[targetid][pID], listitem);
				mysql_tquery(connectionID, queryBuffer, "OnVerifyRemoveFlag", "ii", playerid, targetid);
		    }
		}
		case DIALOG_NEWBIEUNMUTE:
		{
		    if((response) && PlayerInfo[playerid][pNewbieMuted])
		    {
		        switch(listitem)
		        {
		            case 0:
		            {
		                new fine = percent(PlayerInfo[playerid][pCash] + PlayerInfo[playerid][pBank], 5);

		                GivePlayerCash(playerid, -fine);
		                SendClientMessageEx(playerid, COLOR_AQUA, "Ban da chon nop phat Tien {FF6347}$%i{33CCFF} cho viec unmute /newb.", fine);
		            }
		            case 1:
		            {
		                if(PlayerInfo[playerid][pJailTime] > 600)
		                {
		                    return SendClientMessage(playerid, COLOR_LIGHTRED, "Hinh phat nay khong danh cho ban vi ban da bi bo tu 10 phut.");
		                }

		                PlayerInfo[playerid][pJailType] = 1;
					    PlayerInfo[playerid][pJailTime] += 600;

					    ResetPlayerWeaponsEx(playerid);
						ResetPlayer(playerid);
						SetPlayerInJail(playerid);

					    SendClientMessage(playerid, COLOR_AQUA, "Ban da chon viec bi bo tu 10 phut cho viec unmute /newb.");
		            }
		        }

		        PlayerInfo[playerid][pNewbieMuted] = 0;
		        PlayerInfo[playerid][pNewbieMuteTime] = 0;
		    }
		}
		case DIALOG_REPORTUNMUTE:
		{
		    if((response) && PlayerInfo[playerid][pReportMuted])
		    {
		        switch(listitem)
		        {
		            case 0:
		            {
		                new fine = percent(PlayerInfo[playerid][pCash] + PlayerInfo[playerid][pBank], 5);

		                GivePlayerCash(playerid, -fine);
		                SendClientMessageEx(playerid, COLOR_AQUA, "Ban da chon nop phat Tien {FF6347}$%i{33CCFF} cho viec unmute /baocao.", fine);
		            }
		            case 1:
		            {
		                if(PlayerInfo[playerid][pJailTime] > 600)
		                {
		                    return SendClientMessage(playerid, COLOR_LIGHTRED, "Hinh phat nay khong danh cho ban vi ban da bi bo tu 10 phut.");
		                }

		                PlayerInfo[playerid][pJailType] = 1;
					    PlayerInfo[playerid][pJailTime] = 600;

					    ResetPlayerWeaponsEx(playerid);
						ResetPlayer(playerid);
						SetPlayerInJail(playerid);

					    SendClientMessage(playerid, COLOR_AQUA, "Ban da chon viec bi bo tu 10 phut cho viec unmute /baocao.");
		            }
		        }

		        PlayerInfo[playerid][pReportMuted] = 0;
		        PlayerInfo[playerid][pReportMuteTime] = 0;
		    }
		}
		case DIALOG_GLOBALUNMUTE:
		{
		    if((response) && PlayerInfo[playerid][pGlobalMuted])
		    {
		        switch(listitem)
		        {
		            case 0:
		            {
		                new fine = percent(PlayerInfo[playerid][pCash] + PlayerInfo[playerid][pBank], 5);

		                GivePlayerCash(playerid, -fine);
		                SendClientMessageEx(playerid, COLOR_AQUA, "Ban da nop phat Tien {FF6347}$%i{33CCFF} cho viec unmute Global Chat.", fine);
		            }
		            case 1:
		            {
		                if(PlayerInfo[playerid][pJailTime] > 600)
		                {
		                    return SendClientMessage(playerid, COLOR_LIGHTRED, "Hinh phat nay khong danh cho ban vi ban da bi bo tu 10 phut.");
		                }

		                PlayerInfo[playerid][pJailType] = 1;
					    PlayerInfo[playerid][pJailTime] = 600;

					    ResetPlayerWeaponsEx(playerid);
						ResetPlayer(playerid);
						SetPlayerInJail(playerid);

					    SendClientMessage(playerid, COLOR_AQUA, "Ban da chon viec bi bo tu 10 phut cho viec unmute Global Chat.");
		            }
		        }

		        PlayerInfo[playerid][pGlobalMuted] = 0;
		        PlayerInfo[playerid][pGlobalMuteTime] = 0;
		    }
		}
		case DIALOG_REMOVEPVEH:
		{
      		if(response)
		    {
		        new targetid = PlayerInfo[playerid][pRemoveFrom];

				if(targetid == INVALID_PLAYER_ID)
				{
				    return SendClientMessage(playerid, COLOR_LIGHTRED, "Nguoi choi do da mat ket noi. Bay gio ban co the xoa xe cua nguoi choi do.");
				}

				mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "SELECT id, modelid FROM vehicles WHERE ownerid = %i LIMIT %i, 1", PlayerInfo[targetid][pID], listitem);
				mysql_tquery(connectionID, queryBuffer, "OnVerifyRemoveVehicle", "ii", playerid, targetid);
		    }
		}
		case DIALOG_HOUSEINTERIORS:
		{
		    if(response)
		    {
		        new houseid = GetNearbyHouseEx(playerid);

		        if(houseid >= 0 && IsHouseOwner(playerid, houseid))
		        {
		            SetPlayerPos(playerid, houseInteriors[listitem][intX], houseInteriors[listitem][intY], houseInteriors[listitem][intZ]);
		            SetPlayerFacingAngle(playerid, houseInteriors[listitem][intA]);
		            SetPlayerInterior(playerid, houseInteriors[listitem][intID]);
		            SetCameraBehindPlayer(playerid);

		            PlayerInfo[playerid][pPreviewHouse] = houseid;
		            PlayerInfo[playerid][pPreviewType] = listitem;
		            PlayerInfo[playerid][pPreviewTime] = 60;

		            SendClientMessageEx(playerid, COLOR_AQUA, " {FF6347}%s{33CCFF} interior ton %s. Ban co 60 giay de nhin xung quanh va quyet dinh", houseInteriors[listitem][intClass], FormatNumber(houseInteriors[listitem][intPrice]));
		            SendClientMessageEx(playerid, COLOR_AQUA, "Su dung /confirmupgrade neu ban muon nang cap noi that cua ngoi nha. Su dung /cancelupgrade de thoat preview mode.");
		        }
		    }
		}
		case DIALOG_LSELEVATOR:
    	{
	        if(!response)
	            return 0;

	        if(FloorRequestedBy[listitem] != INVALID_PLAYER_ID || IsFloorInQueue(listitem))
	            GameTextForPlayer(playerid, "~r~San nha dang trong hang doi", 3500, 4);
			else if(DidPlayerRequestElevator(playerid))
			    GameTextForPlayer(playerid, "~r~Ban da yeu cau thang may hoat dong", 3500, 4);
			else
		        CallElevator(playerid, listitem);

			return 1;
    	}
		case DIALOG_NEWBWELCOME:
		{
		    if(response)
		    {
		        new count;
				foreach(new i : Player)
				{
					if(PlayerInfo[i][pHelper] > 0)
					{
					    count++;
					}
				}
				if(count > 0)
				{
		        	new string[30];
		        	format(string, sizeof(string), "Chi toi thanh pho Los Santos, toi la nguoi moi.");
					strcpy(PlayerInfo[playerid][pHelpRequest], string, 128);
					SendHelperMessage(COLOR_AQUA, "** Help Request: New Player %s (ID:%d) is requesting a helper to show them around. **", GetPlayerRPName(playerid), playerid);

					PlayerInfo[playerid][pLastRequest] = gettime();
					SendClientMessage(playerid, COLOR_GREEN, "Yeu cau tro giup cua ban da duoc gui den tat ca BQT. Xin hay cho cau tra loi");
				}
				else
				{
				    ShowPlayerDialog(playerid, DIALOG_NONE, DIALOG_STYLE_MSGBOX, "{6FD497}New City{FFFFFF} | Failed", "{FFFFFF}Rat tiec, hien tai khong co doi ngu {33CCFF}helper{FFFFFF} lam viec :(.\nBan cung co the thu lenh /newb, Day la noi cong dong co the giup ban tra loi nhung cau hoi don gian nhu \"Ngan hang o dau ?\".\nBan cung co the xem qua {6FD497}www.NewCity-RP.Net{FFFFFF} cho huong dan co ban.", "Huy bo", "");
				}
			}

			new month, year;
			getdate(.month = month, .year = year);

			if(year == 2018 && month <= 12)
				ShowDialogToPlayer(playerid, DIALOG_REFUND);
		}
		case DIALOG_USERIMKIT:
		{
		    if(response)
		    {
		        new vehicleid = GetPlayerVehicleID(playerid), componentid;

		        if((vehicleid) && VehicleHasDoors(vehicleid) && PlayerInfo[playerid][pRimkits] > 0)
		        {
	      			if(!IsVehicleOwner(playerid, vehicleid) && PlayerInfo[playerid][pVehicleKeys] != vehicleid && !(VehicleInfo[vehicleid][vGang] >= 0 && PlayerInfo[playerid][pGang] == VehicleInfo[vehicleid][vGang]))
					{
					    return 1;
			        }

			        if(listitem == 0) {
						componentid = 1025;
					} else if(1 <= listitem <= 13) {
					    componentid = (listitem - 1) + 1073;
					} else if(14 <= listitem <= 16) {
					    componentid = (listitem - 14) + 1096;
					}

					VehicleInfo[vehicleid][vMods][CARMODTYPE_WHEELS] = componentid;
					PlayerInfo[playerid][pRimkits]--;

					AddVehicleComponent(vehicleid, componentid);
					SaveVehicleModifications(vehicleid);

					mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "UPDATE users SET rimkits = %i WHERE uid = %i", PlayerInfo[playerid][pRimkits], PlayerInfo[playerid][pID]);
					mysql_tquery(connectionID, queryBuffer);

					PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
					SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da gan %s rimkits vao phuong tien giao thong cua ho.", GetPlayerRPName(playerid), inputtext);
				}
		    }
		}
		case DIALOG_TURFLIST:
		{
		    if(response)
		    {
		        if(strlen(tsstring) < 5)
		        {
 					SendClientMessage(playerid, COLOR_AQUA, "Please use /showturfs to enable turf bounds");
				}
				else
				{
				    ShowPlayerDialog(playerid, DIALOG_TURFLIST2, DIALOG_STYLE_MSGBOX, "Turf list", tsstring, "Huy bo", "");
				}
			}
		}
		case DIALOG_TURFLIST2:
		{
		    if(response)
		    {
				SendClientMessage(playerid, COLOR_AQUA, "Please use /showturfs to enable turf bounds");
			}
		}
		case DIALOG_LOCATE:
		{
  			if(response)
      		{
				switch(listitem)
				{
				    case 0: // JOBS
				    {
				    	ShowPlayerDialog(playerid, DIALOG_LOCATELIST1, DIALOG_STYLE_LIST, "GPS - Tim vi tri", "Giao thuc an\nGiao hang nhanh\nNong dan", "Chon", "Quay lai");
				    }
				    case 1: // STORES
				    {
				    	ShowPlayerDialog(playerid, DIALOG_LOCATELIST2, DIALOG_STYLE_LIST, "GPS - Tim vi tri", "Sieu thi\nCua hang vu khi\nCua hang quao ao\nGym\nNha hang\nTo chuc quang cao\nClub\nCua hang cong cu", "Chon", "Quay lai");
				    }
				    case 2: // GENERAL LOCATIONS
				    {
				    	ShowPlayerDialog(playerid, DIALOG_LOCATELIST3, DIALOG_STYLE_LIST, "GPS - Tim vi tri", "Trung tam thi lai xe\nNgan hang\nCasino\nDai ly xe hoi\nDai ly thuyen", "Chon", "Quay lai");
				    }
					case 3: // Find Turfs
					{
					    new string[34 * MAX_TURFS];
					    for(new x = 0; x < MAX_TURFS; x++)
						{
						    if(TurfInfo[x][tExists]) {
					    		strcat(string, TurfInfo[x][tName]);
								strcat(string, "\n");
							}
						}
						if(strlen(string) > 2) {
							ShowPlayerDialog(playerid, DIALOG_LOCATETURFS, DIALOG_STYLE_LIST, "GPS - Tim vi tri", string, "Chon", "Dong");
						} else {
						    ShowPlayerDialog(playerid, DIALOG_NONE, DIALOG_STYLE_MSGBOX, "GPS - Mat tin hieu", "Khong the dinh vi bat ky vi tri nao", "Huy bo", "");
						}
					}
					case 4: // Find Points
					{
					    new string[34 * MAX_POINTS];
					    for(new x = 0; x < MAX_POINTS; x++)
						{
						    if(PointInfo[x][pExists]) {
					    		strcat(string, PointInfo[x][pName]);
								strcat(string, "\n");
							}
						}
						if(strlen(string) > 2) {
							ShowPlayerDialog(playerid, DIALOG_LOCATEPOINTS, DIALOG_STYLE_LIST, "GPS - Tim vi tri", string, "Chon", "Dong");
						} else {
						    ShowPlayerDialog(playerid, DIALOG_NONE, DIALOG_STYLE_MSGBOX, "GPS - Mat tin hieu", "Khong the dinh vi bat ky vi tri nao", "Huy bo", "");
						}
					}
					case 5: // More locations
					{
					    new string[MAX_LOCATIONS*34];
						for(new x = 0; x < MAX_LOCATIONS; x++)
						{
						    if(LocationInfo[x][locExists]) {
					    		strcat(string, LocationInfo[x][locName]);
								strcat(string, "\n");
							}
						}
						if(strlen(string) > 2) {
							ShowPlayerDialog(playerid, DIALOG_LOCATELISTC, DIALOG_STYLE_LIST, "GPS - Tim vi tri", string, "Chon", "Dong");
						} else {
						    ShowPlayerDialog(playerid, DIALOG_NONE, DIALOG_STYLE_MSGBOX, "GPS - Mat tin hieu", "Khong the dinh vi bat ky vi tri nao", "Huy bo", "");
						}
					}
					case 6:
				    {
				    	CancelActiveCheckpoint(playerid);
						SendClientMessage(playerid, COLOR_LIGHTRED, "[CP]{ffffff} Ban da huy tat ca diem danh dau.");
				    }
				}
      		}
		}
		case DIALOG_LOCATELIST1:
		{
			if(response)
			{
			    switch(listitem)
			    {
				    case 0:
						LocateMethod(playerid,"Pizzaman");
	                case 1:
						LocateMethod(playerid,"Courier");
					case 2:
					    LocateMethod(playerid,"Farmer");
				}
			}
			else
			{
				ShowDialogToPlayer(playerid, DIALOG_LOCATE);
			}
		}
		case DIALOG_LOCATELIST2:
		{
		    if(response)
			{
			    switch(listitem)
			    {
				    case 0:
						LocateMethod(playerid,"Supermarket");
				    case 1:
				        LocateMethod(playerid,"GunShop");
				    case 2:
				        LocateMethod(playerid,"Clothes");
				    case 3:
				        LocateMethod(playerid,"Gym");
				    case 4:
				        LocateMethod(playerid,"Restaurant");
				    case 5:
				        LocateMethod(playerid,"Adagency");
				    case 6:
				        LocateMethod(playerid,"Club");
				    case 7:
				        LocateMethod(playerid,"ToolShop");
				}
			}
			else
			{
				ShowDialogToPlayer(playerid, DIALOG_LOCATE);
			}
		}
		case DIALOG_LOCATELIST3:
		{
		    if(response)
			{
			    switch(listitem)
			    {
                    case 0:
						LocateMethod(playerid,"DMV");
                    case 1:
						LocateMethod(playerid,"Bank");
                	case 2:
						LocateMethod(playerid,"Casino");
                	case 3:
						LocateMethod(playerid,"Dealership");
                    case 7:
						LocateMethod(playerid,"AirDealer");
				}
			}
			else
			{
				ShowDialogToPlayer(playerid, DIALOG_LOCATE);
			}
		}
		case DIALOG_LOCATELISTC:
		{
		    if(response)
		    {
				LocateMethod(playerid, inputtext);
		    }
		}
		case DIALOG_LOCATETURFS:
		{
			if(response)
			{
			    foreach(new i : Turf)
			    {
			        if(strfind(TurfInfo[i][tName], inputtext) != -1)
			        {
				   	 	PlayerInfo[playerid][pCP] = CHECKPOINT_MISC;
				    	SetPlayerCheckpoint(playerid, TurfInfo[i][tMinX], TurfInfo[i][tMinY], TurfInfo[i][tHeight], 3.0);
				    	SendClientMessageEx(playerid, COLOR_WHITE, "** Da danh dau duoc vi tri cua %s.", TurfInfo[i][tName]);
				    	break;
					}
				}
			}
		}
		case DIALOG_LOCATEPOINTS:
		{
		    if(response)
			{
			    if(PointInfo[listitem][pExists])
			    {
	                PlayerInfo[playerid][pCP] = CHECKPOINT_MISC;
				    SetPlayerCheckpoint(playerid, PointInfo[listitem][pPointX], PointInfo[listitem][pPointY], PointInfo[listitem][pPointZ], 3.0);
				    SendClientMessageEx(playerid, COLOR_WHITE, "** Da danh dau duoc vi tri cua %s.", PointInfo[listitem][pName]);
			    }
			}
		}
		case DIALOG_RULES: //luat le nhung deo thich nen doi cai
		{
		    if(response)
		    {
		        switch(listitem)
		        {
					case 0: ShowPlayerDialog(playerid, DIALOG_NONE, DIALOG_STYLE_MSGBOX, "{FFFF00}Chinh sach ve gian lan & loi dung khong cong bang", "Tat ca cac loai gian lan, hack va loi dung khong cong bang deu bi cam tren may chu nay", "Close", "");
					case 1: ShowPlayerDialog(playerid, DIALOG_NONE, DIALOG_STYLE_MSGBOX, "{FFFF00}Chinh sach ve khai thac", " Bat ky va tat ca khai thac, chang han nhu QS, CS, NJ, khai thac theo tap lenh, v.v.\nBI CAM! ", "Close", "");
					case 2: ShowPlayerDialog(playerid, DIALOG_NONE, DIALOG_STYLE_MSGBOX, "{FFFF00}Chinh sach ve quang cao "," Cam quang cao bat ky thu gi khac ngoai vat the / vat pham trong thanh pho"," Dong "," ");
					case 3: ShowPlayerDialog(playerid, DIALOG_NONE, DIALOG_STYLE_MSGBOX, "{FFFF00}Chinh sach ve Deathmatch "," Ket hop tu than la khi ban giet mot nguoi choi khac vi ly do khong hop le (khong phai RP).\nDieu nay bi nghiem cam tren thanh pho nay", "Close", "");
			        case 4: ShowPlayerDialog(playerid, DIALOG_NONE, DIALOG_STYLE_MSGBOX, "{FFFF00}Chinh sach ve spawn-killing", "Spawn-killing tuong tu nhu Deathmatch, voi cac hinh phat nang hon.\nDung giet bat ky ai vua moi hoi sinh!", "Close", "");
			        case 5: ShowPlayerDialog(playerid, DIALOG_NONE, DIALOG_STYLE_MSGBOX, "{FFFF00}Chinh sach ve revenge-killing", "Khong duoc phep giet nguoi choi vi ban da bi ho giet!\nQuy tac nay se duoc tuan theo trong cac luot choi.", "Close", "");
	        	    case 6: ShowPlayerDialog(playerid, DIALOG_NONE, DIALOG_STYLE_MSGBOX, "{FFFF00}Chinh sach ve car raming", "Dung xe de tan cong nguoi choi ma khong co ly do hop le\n Quy tac nay se duoc tuan theo trong cac luot choi.", "Close", "");
				 	case 7: ShowPlayerDialog(playerid, DIALOG_NONE, DIALOG_STYLE_MSGBOX, "{FFFF00}Chinh sach ve heli-blading", "Dung canh cua truc thang de giet nguoi la khong hop le.", "Close", "");
			        case 8: ShowPlayerDialog(playerid, DIALOG_NONE, DIALOG_STYLE_MSGBOX, "{FFFF00}Chinh sach ve meta-gaming", "Khong duoc su dung thong tin nhan vat ngoai doi cho nhan vat trong game.", "Close", "");
			        case 9: ShowPlayerDialog(playerid, DIALOG_NONE, DIALOG_STYLE_MSGBOX, "{FFFF00}Chinh sach ve money-farming", "Money-farming la khi ban tao 1 tai khoan moi de duoc nhan them 1 so tien va chuyen vao tai khoan chinh\nDieu nay se dan den banned vinh vien.", "Close", "");
	                case 10: ShowPlayerDialog(playerid, DIALOG_NONE, DIALOG_STYLE_MSGBOX, "{FFFF00}Chinh sach ve lying to admins", "Noi lao, xao, doi voi Administrator la khong duoc.", "Close", "");
	                case 11: ShowPlayerDialog(playerid, DIALOG_NONE, DIALOG_STYLE_MSGBOX, "{FFFF00}Chinh sach ve robbery", "Ban chi co the cuop tien cua mot nguoi choi 1 lan trong 24 tieng.\nVui long tuan theo quy dinh ve cuop,v.v.(thong tin cu the tren www.NewCity-RP.Net)", "Close", "");
	                case 12: ShowPlayerDialog(playerid, DIALOG_NONE, DIALOG_STYLE_MSGBOX, "{FFFF00}Chinh sach ve scamming", "Donation scams are prohibited\nPlease follow regulations regarding max. scamming, etc (available at newcity-rp.com)", "Close", "");
					case 13: ShowPlayerDialog(playerid, DIALOG_NONE, DIALOG_STYLE_MSGBOX, "Full list of rules", "{FFFFFF}Please visit {6FD497}soon-rp.ml{FFFFFF} for a complete list of rules.", "Close", "");
				}
			}
		}
		case DIALOG_PAYCHECK:
		{
	 		if(!response) return 1;
			new
				szMessage[150];
	   		if(strlen(inputtext) < 1)
			{
	            format(szMessage, sizeof(szMessage), "Ban phai nhap ma code truoc khi nhan Paycheck.\n\nCheck code: %d\n\nNhap ma code de nhan Paycheck:", PayCheckCode[playerid]);
				ShowPlayerDialog(playerid, DIALOG_PAYCHECK, DIALOG_STYLE_INPUT, "Sign check", szMessage, "Sign check","Huy bo");
				return 1;
	        }
			if(!IsNumeric(inputtext))
			{
	 			format(szMessage, sizeof(szMessage), "Sai ma code. Ma code chi chua so thu tu.\n\nCheck code: %d\n\nNhap ma code de nhan Paycheck:", PayCheckCode[playerid]);
				ShowPlayerDialog(playerid, DIALOG_PAYCHECK, DIALOG_STYLE_INPUT, "Sign check", szMessage, "Sign check","Huy bo");
				return 1;
			}
	        if(strlen(inputtext) > 6 || (strlen(inputtext) > 0 && strlen(inputtext) < 6))
			{
	           	format(szMessage, sizeof(szMessage), "Sai ma code. Ma code chi co 6 so.\n\nCheck code: %d\n\nNhap ma code de nhan Paycheck:", PayCheckCode[playerid]);
				ShowPlayerDialog(playerid, DIALOG_PAYCHECK, DIALOG_STYLE_INPUT, "Sign check", szMessage, "Sign check","Huy bo");
				return 1;
	        }
	        new code = strval(inputtext);
        	if(code == PayCheckCode[playerid])
	        {
				SendPaycheck(playerid);
	        	PayCheckCode[playerid] = 0;
			}
			else
			{
	            SendClientMessage(playerid, COLOR_WHITE, "Sai ma code.");
	        }
		}
		case DIALOG_CREATEQUIZ:
		{
			if(CreateQuiz == 0)
			{
			    strcpy(quizQuestion, inputtext);
			    CreateQuiz = 1;
                ShowDialogToPlayer(playerid, DIALOG_CREATEQUIZ);
			}
			else if(CreateQuiz == 1)
			{
			    strcpy(quizAnswer, inputtext);
                CreateQuiz = -1;
                SendAdminMessage(COLOR_LIGHTRED, "AdmCmd: %s da bat dau cau giai do.", GetPlayerRPName(playerid));
                SendClientMessageToAllEx(0x00FF6EFF, "QUIZ: %s (/quiz answer to answer)", quizQuestion);
			}

		}
		case DIALOG_DELETEOBJECT:
		{
		    if(response)
		    {
		        if(IsValidDynamicObject(PlayerInfo[playerid][pSelected]))
		        {
		            new Text3D:textid = Text3D:Streamer_GetExtraInt(PlayerInfo[playerid][pSelected], E_OBJECT_3DTEXT_ID);
			        if(IsValidDynamic3DTextLabel(textid))
			        {
			            DestroyDynamic3DTextLabel(textid);
			        }
		        	DestroyDynamicObject(PlayerInfo[playerid][pSelected]);
		        	/*if(Streamer_GetExtraInt(i, E_OBJECT_TYPE) == E_OBJECT_LAND)
		        	{
		        	    Iter_Remove(PlayerInfo[playerid][pSelected], LandObjects);
		        	}*/
		        	SendClientMessageEx(playerid, COLOR_AQUA, "Ban da xoa object %i.", PlayerInfo[playerid][pSelected]);
					new Float: x, Float: y, Float: z;
					GetPlayerPos(playerid, x, y, z);
					foreach(new i : Player)
					{
					    if(IsPlayerInRangeOfPoint(i, 100.0, x, y ,z))
					    {
							Streamer_UpdateEx(i, x, y, z);
						}
					}
				}
				else
				{
				    SendClientMessage(playerid, COLOR_AQUA, "Khong the pha huy object, ERROR #1: Not a valid streamer object.");
				}
			}
		    else
		    {
		        SendClientMessageEx(playerid, COLOR_AQUA, "You cancelled deleting object id %i.", PlayerInfo[playerid][pSelected]);
		    }
		}
		case DIALOG_PAINTBALL:
		{
		    if(response)
		    {
			    SendProximityMessage(playerid, 20.0, COLOR_PURPLE, "** %s da tham gia Paintball Arena.", GetPlayerRPName(playerid));
				SetPlayerInPaintball(playerid, listitem+1);

				foreach(new i : Player)
				{
				    if(PlayerInfo[playerid][pPaintball] == PlayerInfo[i][pPaintball])
				    {
				        SendClientMessageEx(i, COLOR_LIGHTORANGE, "(( %s da tham gia Paintball Arena. ))", GetPlayerRPName(playerid));
					}
			    }
		    }
		}
		case DIALOG_ADDSTATION:
		{
		    if(response)
		    {
		        new name;
                mysql_format(radioConnectionID, queryBuffer, sizeof(queryBuffer), "INSERT INTO radiostations VALUES ('%e', '%e', '%e', '%e')", name, inputtext, PlayerInfo[playerid][pSubgenre], PlayerInfo[playerid][pGenre]);
				mysql_tquery(radioConnectionID, queryBuffer);
				PlayerInfo[playerid][pStationEdit] = 0;
		    }
		}
		case DIALOG_REFUND:{
			if(!response)
				ShowDialogToPlayer(playerid, DIALOG_REFUND);
			else{
				switch(listitem){
					case 0:{
						PlayerInfo[playerid][pEXP] += 3;
						SendClientMessage(playerid, COLOR_AQUA, "** Ban da duoc den bu 3 EXP Points! **");
					}
					case 1:{
						GivePlayerCash(playerid, 15000);
						SendClientMessage(playerid, COLOR_AQUA, "** Ban da duoc den bu $15,000! Su dung no thoai mai. **");
					}
				}
				ShowDialogToPlayer(playerid, DIALOG_REFUND2);
			}
		}
		case DIALOG_REFUND2:{
			if(!response)
				ShowDialogToPlayer(playerid, DIALOG_REFUND2);
			else{
				switch(listitem){
					case 0:{
						mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "INSERT INTO vehicles (modelid, price, pos_x, pos_y, pos_z, pos_a, gangid, respawndelay, ownerid) VALUES(%i, %i, '%f', '%f', '%f', '%f', %i, 600, '%i')", 461, 1, 839.34399, -2058.59814, 12.45428, 0.0, -1, PlayerInfo[playerid][pID]);
						mysql_tquery(connectionID, queryBuffer);
						SendClientMessage(playerid, COLOR_AQUA, "** Ban da duoc den bu PCJ-600! Dung /carstorage de thay no. **");
					}
					case 1:{
						mysql_format(connectionID, queryBuffer, sizeof(queryBuffer), "INSERT INTO vehicles (modelid, price, pos_x, pos_y, pos_z, pos_a, gangid, respawndelay, ownerid) VALUES(%i, %i, '%f', '%f', '%f', '%f', %i, 600, '%i')", 426, 1, 839.34399, -2058.59814, 12.45428, 0.0, -1, PlayerInfo[playerid][pID]);
						mysql_tquery(connectionID, queryBuffer);
						SendClientMessage(playerid, COLOR_AQUA, "** Ban da duoc den bu Premier! Dung /carstorage de thay no. **");
					}
				}
			}
		}
		case DIALOG_CAR:
		{
			if(response)
			{
				switch(listitem)
			    {
			    	case 0:
			    	{
			    		callcmd::engine(playerid, "\1");
			    	}
			    	case 1:
			    	{
			    		callcmd::sb(playerid, "\1");
			    	}
			    	case 2:
			    	{
			    		callcmd::lights(playerid, "\1");
			    	}
			    	case 3:
			    	{
			    		callcmd::hood(playerid, "\1");
			    	}
			    	case 4:
			    	{
			    		callcmd::trunk(playerid, "\1");
			    	}
			    	case 5:
			    	{
			    		callcmd::carinfo(playerid, "\1");
			    	}
			    }
			}
		}
		case DIALOG_KICKPLAYER:
		{
			if(response)
			{
				new reason = strlen(inputtext),
				    targetid;
				if(isnull(inputtext))
	            {
	                ShowDialogToPlayer(playerid, DIALOG_KICKPLAYER);
	                return 1;
				}
				if(reason >= 1)
				{
					KickPlayer(targetid);
					SendClientMessageToAllEx(COLOR_LIGHTRED, "AdmCmd: %s da bi kick boi %s, ly do: %s", GetPlayerRPName(targetid), GetPlayerRPName(playerid), reason);
					SetPVarInt(playerid, "SpecVar", 0);

					HideTextdrawSpec(playerid);
				}
			}
		}
		case DIALOG_NONE:
		{
		    // does nothing
		}

	}

	return 1;
}