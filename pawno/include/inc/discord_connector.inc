#include <YSI\y_hooks>

static const 
	adminChatID[] = "539171233292353536",
	reportChatID[] = "539171191278010386";

returnAdminChatID(){
	return adminChatID;
}

returnReportChatID(){
	return reportChatID;	
}

public DCC_OnChannelMessage(DCC_Channel:channel, DCC_User:author, const message[]){

	if(DCC_FindUserById("539171233292353536") == author)
		return 1;

	if(!strcmp(message, "!avoid$!", true))
		return 1;

	new
		cmd[20],
		params[128];

	sscanf(message, "s[20]S()[128]", cmd, params);

	// Commands for chat in /admin-chat/
	if(DCC_FindChannelById(returnAdminChatID()) == channel){		
		if(!strcmp(cmd, "!admins", true))
			return DiscordCMD_admins();
		else if(!strcmp(cmd, "!a", true))
			return DiscordCMD_a(author, params);
		else
			return Discord_AdminChannelHelp();
	}

	// Commands for chat in /report/ 
	if(DCC_FindChannelById(returnReportChatID()) == channel){
		if(!strcmp(cmd, "!w", true))
			return DiscordCMD_W(author, params);
		else if(!strcmp(cmd, "!reports", true))
			return DiscordCMD_reports();
		else if(!strcmp(cmd, "!tr", true))
			return DiscordCMD_tr(author, params);
		else if(!strcmp(cmd, "!onlineplayers", true))
			return DiscordCMD_OnlinePlayers();
		else if(!strcmp(cmd, "!id$", true))
			return DiscordCMD_ID(params);
		else
			return Discord_ReportChannelHelp();
	}
	return 1;
}

Discord_ReportChannelHelp(){
	new msg[1256];

	format(msg, sizeof(msg), 
		"```COMMANDS:\n\
		!w - Used to whisper something to a player InGame.\n\
		!reports - Used to view all active reports.\n\
		!tr - Used to trash an active report\n\
		!onlineplayers - Used to view all players and their IDs\n\
		!id$ - Used to know a specific player's ID.```");

	return DCC_SendChannelMessage(DCC_FindChannelById(returnReportChatID()), msg);
}

Discord_AdminChannelHelp(){

	new msg[256];

	format(msg, sizeof(msg), 
		"```COMMANDS:\n\
		!a - Used to chat with admins InGame.\n\
		!admins - Used to know which admins are InGame.```");

	return DCC_SendChannelMessage(DCC_FindChannelById(returnAdminChatID()), msg);
}

DiscordCMD_ID(params[]){

	new targetID;

	if(sscanf(params, "u", targetID))
		return DCC_SendChannelMessage(DCC_FindChannelById(returnReportChatID()), "```USAGE: !id$ <playerid/partOfName>```");

	if(targetID == INVALID_PLAYER_ID)
		return DCC_SendChannelMessage(DCC_FindChannelById(returnReportChatID()), "```ERROR: Could not find player!```");

	new msg[128];

	format(msg, sizeof(msg), "```(ID: %i) %s - (Level: %i) - (Ping: %i)```", targetID, GetPlayerNameEx(targetID), PlayerInfo[targetID][pLevel], GetPlayerPing(targetID));
	DCC_SendChannelMessage(DCC_FindChannelById(returnReportChatID()), msg);	
	return 1;
}

DiscordCMD_OnlinePlayers(){

	new msg[(MAX_PLAYER_NAME * MAX_PLAYERS) + (MAX_PLAYERS * 2)];

	foreach(new i: Player)
		format(msg, sizeof(msg), "%s%d. %s\n", msg, i, GetPlayerNameEx(i));

	if(!strlen(msg))
		DCC_SendChannelMessage(DCC_FindChannelById(returnReportChatID()), "```There are no players online right now```");
	else{
		format(msg, sizeof(msg), "```%s```", msg);
		DCC_SendChannelMessage(DCC_FindChannelById(returnReportChatID()), msg);
	}

	return 1;
}

DiscordCMD_reports(){

	DCC_SendChannelMessage(DCC_FindChannelById(returnReportChatID()), "**__________ Pending Reports __________**");

	for(new i = 0, report[128]; i < MAX_REPORTS; i ++)
	{
	    if(ReportInfo[i][rExists] && !ReportInfo[i][rAccepted])
	    {
	    	format(report, sizeof(report), "(RID: %i) %s[%i] reports: %s", i, GetPlayerRPName(ReportInfo[i][rReporter]), ReportInfo[i][rReporter], ReportInfo[i][rText]);
	        DCC_SendChannelMessage(DCC_FindChannelById(returnReportChatID()), report);
		}
	}

	DCC_SendChannelMessage(DCC_FindChannelById(returnReportChatID()), "**Use !w or !tr [rid] to handle these reports.");

	return 1;
}

DiscordCMD_tr(DCC_User:author, params[]){

	new reportid, reason[128];

	if(sscanf(params, "iS(N/A)[128]", reportid, reason))
	    return DCC_SendChannelMessage(DCC_FindChannelById(returnReportChatID()), "```USAGE: !tr [reportid] [reason (optional)]```");

	if(!(0 <= reportid < MAX_REPORTS) || !ReportInfo[reportid][rExists])
	    return DCC_SendChannelMessage(DCC_FindChannelById(returnReportChatID()), "```Invalid report ID.```");

    if(ReportInfo[reportid][rAccepted])
	    return DCC_SendChannelMessage(DCC_FindChannelById(returnReportChatID()), "```The report specified is being handled by an admin.```");

	new 
		Name[64],
		Discriminator[10],
		message[128];

	DCC_GetUserName(author, Name, sizeof(Name));
	DCC_GetUserDiscriminator(author, Discriminator, sizeof(Discriminator));

	SendAdminMessage(COLOR_LIGHTRED, "AdmCmd: %s#%s has trashed report %i from %s, reason: %s", Name, Discriminator, reportid, GetPlayerRPName(ReportInfo[reportid][rReporter]), reason);
	SendClientMessageEx(ReportInfo[reportid][rReporter], COLOR_LIGHTRED, "** %s#%s has trashed your report, reason: %s", Name, Discriminator, reason);

	format(message, sizeof(message), "``` AdmCmd: You trashed report %i from %s, reason: %s```", reportid, GetPlayerRPName(ReportInfo[reportid][rReporter]), reason);

	DCC_SendChannelMessage(DCC_FindChannelById(returnReportChatID()), message);

	ReportInfo[reportid][rExists] = 0;

	return 1;
}

DiscordCMD_W(DCC_User:author, params[]){
	new
		targetid,
		_params[128];

	if(sscanf(params, "us[128]", targetid, _params))
		return DCC_SendChannelMessage(DCC_FindChannelById(returnReportChatID()), "```USAGE: !w <targetid> <text>```");

	if(targetid == INVALID_PLAYER_ID)
		return DCC_SendChannelMessage(DCC_FindChannelById(returnReportChatID()), "```ERROR: Could not find player.```");

	if(!strlen(_params))
		return DCC_SendChannelMessage(DCC_FindChannelById(returnReportChatID()), "```HINT: You're supposed to write a text as well. SMH.```");

	new 
		Name[64],
		Discriminator[10],
		message[128];

	DCC_GetUserName(author, Name, sizeof(Name));
	DCC_GetUserDiscriminator(author, Discriminator, sizeof(Discriminator));

	format(message, sizeof(message), "** [%s#%s]: %s **", Name, Discriminator, _params);
	SendClientMessage(targetid, COLOR_YELLOWGREEN, message);
	PlayerPlaySound(targetid, 1052, 0.0, 0.0, 0.0);
	return 1;
}

DiscordCMD_admins(){
	new 
		count = 0,
		msg[MAX_PLAYER_NAME+1];
	foreach(new i: Player){
		if(PlayerInfo[i][pAdmin]>0){
			count++;
			format(msg, sizeof(msg), "%s", GetPlayerNameEx(i));
			DCC_SendChannelMessage(DCC_FindChannelById(returnAdminChatID()), msg);
		}
	}
	if(!count)
		DCC_SendChannelMessage(DCC_FindChannelById(returnAdminChatID()), "There are no admins online");
	return 1;
}

DiscordCMD_a(DCC_User:author, msg[]){

	if(!strlen(msg))
		return DCC_SendChannelMessage(DCC_FindChannelById(returnAdminChatID()), "USAGE: !a <text>");

	new 
		Name[64],
		Discriminator[10],
		message[128];

	DCC_GetUserName(author, Name, sizeof(Name));
	DCC_GetUserDiscriminator(author, Discriminator, sizeof(Discriminator));

	format(message, sizeof(message), "** {FFFF00}[%s#%s]: %s **", Name, Discriminator, msg);

	foreach(new i : Player)
	{
	    if((PlayerInfo[i][pAdmin] > 0 || PlayerInfo[i][pDeveloper]) && !PlayerInfo[i][pToggleAdmin])
	    	SendClientMessage(i, COLOR_YELLOW, message);
	}

	return 1;
}