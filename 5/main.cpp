#include <iostream>
#include <fstream>
#include "TheMatrix.h"

using namespace std;

int main(int argc, char *argv[])
{
	TheMatrix A, B, AddAB, SubAB, DivAB, MultAB;

	ifstream fin1, fin2;
	string fName1, fName2;
	cout << "Enter the filename for the first matrix: ";
	cin >> fName1;
	cout << "Enter the filename for the second matrix: ";
	cin >> fName2;

	fin1.open(fName1.c_str(), ios::in);
	fin2.open(fName2.c_str(), ios::in);
/*
;:cldk0KXXXXK0OkkOO00KKKKKK0x,,,;;kOOOOOkkxxxxxxxxxdoddddddxxxxxxkkkOO0KKXXNNNWW
:;codOKKXXXKK0kxxkOO000KKK0Oc',;;;;xOOkkkxxxxxxxddddoooooooooooddddddxxkOO0KXXNN
lcldk0KXXXXKK0kxdxkkOOOOOkxd;;::;,,;xkkkxxxxxxxdddddooollllllllllolooooddxxk00KX
oloxOKXXXXXKK0kxdxkkkOOOOkko:::::;,;:dkkxxxxxxxxdddooolllllllllllllllllloodxkO0K
doox0KXXXXXK0OxddxkkkOOOOkko:;,,;;;;;:dxxxxxxxxdddoooolllccclllllllllllloolldkOO
xooxOKKKKKK0OkxddxkkOOOOOOOc,,;;::::;,;oooxddxxxdddooolllccccllllllllll:,':dxxkk
xddxO0KKK00OkxdddxkOOOOOOOOc;;:cclc:;,.:c,;:colc:lodddooooollooollc:,..,cxkkxxxk
xddxkO00OOOkxddddxkO000000x:;,;;:;:cc:,,:,,;.::.,;,,llllooool:;,....':oxO000Okkk
xoodxkkkkkxxddoodxkO00000xc''',;::;,,,..':;..;c',''col::c:;'... .';ldxk0KXK00OOO
xdoddxxxxxxdollodxkOO00Ox;'..,;;;,...';'''.':;,,,,,cl,ldl;,,.',;;:lxkOKKKK000000
ddooddddddoollllodxkOOOx:....'''',;;;,,'..;::xc,,cdld;dlc;,:::;;codk0XXXXKKKKK00
dooooodoooollccllodxkkxc'.....'''''';l'..;kOkOc'c0Odo,odoc,',cdxdxxkKXXXXXKKKKK0
ddooooooolllcccllodxxxd,...''''''''.';. ,d0XN0cl0XNNk',loooo::ldxddkXXXXXKKKKKK0
ddooooolllcccccllodddd:..... .....   ..';lkKNXOKNNWWO',ddlclll:cdo:lOXXXKKKKK000
dooooolllccccccclloodo;.. ....., ..... .:ox0NNNNWWNXOoxdc:llclc:c;;lOKKKKK00000O
doolllllccccccccclodoc'...... ......... :oxOXNWWWWXd;'''.'cdddool;:x0K000000OOOO
ooolllcccc:::cccccldo;.......   ..      cdxOXNWMWNc;:':oc.colcdkOdoO000000OOOkkk
oolllccc:::::cccclloo:;''....  ..',:c;,;xkk0NWMMWx,;:;::':0OdollkkkOOOOOOOOkkkkk
ollcccc::::clol:::lodol:'......,:oxxxkkxxOKXWMMMWK00d:;;clcclxkoxOOOOOkkkkkkkkkx
llcc:::::clodxo:clooddllc;;;;:cldxxxxxxddOKXWMMMMMMMWWKOdoodkO0kxOOkkkkkkkkkkkxx
llcc::::;,,;oxdddddoodolc:::cclddxddddocldk0NWMMMMMMMMWN0xxxk0KOOOOOOOOkkkkkkkkk
llcc:;,..',:ldddddooolccccccccldxdoooddc,:coxKNWMMMMMMMWNKK0kOK000OOOOOkkkkkkkkk
lc:'......,:loooooollcccclc::::ldxdoooddoc:oOXNNWWWWMMMWNNXXXXXK00OOOOOkkkkkkkkk
...     ..';cllooollccc:;::ccccclodxdooooccdk0KKXNWWMWWNNWWWMWX00000OOOOkkkkkkkO
          .';cllllllccc::;;;:cccccloddddddxxkk0KXNNWWWWWWWMMWNK000000OOOOOOOOOOO
          ..;cclllllllcccc:::::cllolodxkkkO0KKXXXXNNNNWWWMMWNKKKK0000000000OOOOO
         ...,:ccccllllllcccllcccccloddxxkkOOO000KKXNNNWWWWNXKK00KK00000K00000000
         ...;ccccclllllllloooooolllcccokkkOOO000KKXNNWWNNXKK0KK00KKKKKKKKKKKK000
*/

	if ((!fin1) || (!fin2))
	{
		cout << "Both or either of the following files: \"" << fName1 << "\", \"" << fName2 << "\", do not exist." << endl;
		return 1;
	}


	// Read
	fin1 >> A;
	fin2 >> B;

	fin1.close();
	fin2.close();

	AddAB =  A + B;
	SubAB =  A - B;
	DivAB =  A / B;
	MultAB = A * B;

	cout << "Matrix A" << endl;
	cout << A;

	cout << "Matrix B" << endl;
	cout << B;
	
	cout << "A + B" << endl;
	cout << AddAB;

	cout << "A - B" << endl;
	cout << SubAB;

	cout << "A * B" << endl;
	cout << MultAB;
	
	cout << "A / B" << endl;
	cout << DivAB;

	return 0;
}
