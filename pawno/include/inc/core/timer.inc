/*
*
*
*                 TIMER NEW CITY
*
*
*/

task LoadStatus[300000]() 
{	
	foreach(new i: Player)
	{
		if(PlayerInfo[i][pLogged])
		{
			if(PlayerInfo[i][pInjured] != 1)
			{
				PlayerInfo[i][pHunger] -= 2;
				PlayerInfo[i][pThirsty] -= 4;
				if(PlayerInfo[i][pHunger] == 10)
				{
					SendClientMessage(i, COLOR_LIGHTRED, "[!] Ban dang rat doi bung, hay cung cap thuc an cho minh.");
				}
				if(PlayerInfo[i][pThirsty] == 10)
				{
					SendClientMessage(i, COLOR_LIGHTRED, "[!] Ban dang rat khat nuoc, hay cung cap nuoc uong cho minh.");
				}
				if(PlayerInfo[i][pHunger] < 1)
				{
					SendClientMessageEx(i, COLOR_LIGHTRED, "[!] Ban da ngat xiu vi qua doi bung.");
					PlayerInfo[i][pHealth] = 0;
					SetPlayerHealth(i, 0);
				}
				if(PlayerInfo[i][pThirsty] < 1)
				{
					SendClientMessageEx(i, COLOR_LIGHTRED, "[!] Ban da ngat xiu vi qua khat nuoc.");
					PlayerInfo[i][pHealth] = 0;
					SetPlayerHealth(i, 0);
				}
			}

		}
	}
}