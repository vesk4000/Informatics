#include <iostream>
#include <string>

using namespace std;

struct cmds
{
	string command;
	int nArgs;
	string func;
}

void Loop();
void InitCommand();


int main()
{
	Loop();
	return 0;
}

void Loop()
{
	while(true)
	{
		initCommand();
	}
}

void InitCommand()
{
	cout << ">";
	string command;
	getline(cin, command);
	int nSpaces = count(command.begin(), command.end(), ' ');
	int nArgs = ++nSpaces;


}
