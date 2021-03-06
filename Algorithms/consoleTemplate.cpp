#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct cmds
{
	string command;
	int nArgs;
	string func;
};

bool shouldContinue = true;

vector <cmds> commands;

void Setup();
void Loop();
void InitCommand();
vector <string> Split(string stringToBeSplitted, string delimeter);
void ExecuteCommand(vector <string> args);


int main()
{
	Setup();
	Loop();
	return 0;
}

void Setup()
{
	cmds cmd;
	cmd.command = "quit";
	cmd.nArgs = 0;
	commands.push_back(cmd);
}

void Loop()
{
	while(true)
	{
		InitCommand();
		if(!shouldContinue)
			return;
	}
}

void InitCommand()
{
	cout << ">";
	string command;
	getline(cin, command);
	vector <string> args = Split(command, " ");
	int nArgs = args.size();
	bool flag = false;
	for(int i = 0;i < commands.size(); ++i)
	{
		if(commands[i].command == args[0])
		{
			flag = true;
			if(nArgs - 1 != commands[i].nArgs)
			{
				cout << args[0] << " requires " << commands[i].nArgs << endl;
				break;
			}
			ExecuteCommand(args);
			break;
		}
	}
	if(!flag)
		cout << "No such command exists" << endl;
}

void ExecuteCommand(vector <string> args)
{
	if(args[0] == quit)
	{
		shouldContinue = false;
	}
}

vector <string> Split(string stringToBeSplitted, string delimeter)
{
     vector<string> splittedString;
     int startIndex = 0;
     int  endIndex = 0;
     while( (endIndex = stringToBeSplitted.find(delimeter, startIndex)) < stringToBeSplitted.size() )
    {
       string val = stringToBeSplitted.substr(startIndex, endIndex - startIndex);
       splittedString.push_back(val);
       startIndex = endIndex + delimeter.size();
     }
     if(startIndex < stringToBeSplitted.size())
     {
       string val = stringToBeSplitted.substr(startIndex);
       splittedString.push_back(val);
     }
     return splittedString;
}
