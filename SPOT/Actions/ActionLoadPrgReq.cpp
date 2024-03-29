#include "ActionLoadPrgReq.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "../Registrar.h"
using namespace std;

ActionLoadPrgReq::ActionLoadPrgReq(Registrar*p) :Action(p)
{
	
}

bool ActionLoadPrgReq::Execute()
{
	
	ifstream file("D:\CIE-Requirements.txt");
	ProgReq* pr = pReg->getProgReq();

	int totalCrd=pr->getTotalCredit();
	int unicomplCR=pr->getUniComplsoryCredit(), unielecCR=pr->getUniElectiveCredit();
	int trachcomplCR=pr->getTrackComplsoryCredit();
	int majrcomplCR=pr->getMajorCommonComplsoryCredit(), majrelecCR=pr->getMajorCommonElectiveCredit();
	int concen=pr->getNumOfConecntrations();
	int majrConcenComplCR=pr->getMajorConcentration1ComplsoryCredit();
	int majrConcenElecCR=pr->getMajorConcentration1ElectiveCredit();

	vector<string> unicompl=pr->getUniComplsoryCrs();
	vector<string> unielect=pr->getUniElectiveCrs();
	vector<string> trackcompl=pr->getTrackCrs();
	vector<string> majrCommonCompl=pr->getMajorCommonComplsoryCrs();
	vector<string>  majorCommonElect=pr->getMajorCommonElectiveCrs();

	char* pch;
	char* context = nullptr;
	const int size = 300;
	char line[size];

	// reading first line 
	file.getline(line, size);
	pch = strtok_s(line, ",", &context);
	totalCrd = stoi(pch);


	// reading 2 line 
	file.getline(line, size);
	pch = strtok_s(line, ",", &context);
	unicomplCR = stoi(pch);

	pch = strtok_s(NULL, ",", &context);
	int cre = stoi(pch);


	// reading 3 line 
	file.getline(line, size);
	pch = strtok_s(line, ",", &context);
	trachcomplCR = stoi(pch);

	// reading 4 line 
	file.getline(line, size);
	pch = strtok_s(line, ",", &context);
	majrcomplCR = stoi(pch);

	pch = strtok_s(NULL, ",", &context);
	majrelecCR = stoi(pch);



	// reading 5 line 
	file.getline(line, size);
	pch = strtok_s(line, ",", &context);
	concen = stoi(pch);


	// reading 6 line 
	file.getline(line, size);
	pch = strtok_s(line, ",", &context);
	majrConcenComplCR = stoi(pch);

	// Reading 7 line 
	file.getline(line, size);
	stringstream l(line);
	while (l.good()) {
		string substr;
		getline(l, substr, ',');
		unicompl.push_back(substr);
	}

	// Reading 8 line 
	file.getline(line, size);
	stringstream d(line);
	while (d.good()) {
		string substr;
		getline(d, substr, ',');
		unielect.push_back(substr);
	}

	// Reading 9 line 
	file.getline(line, size);
	stringstream v(line);
	while (v.good()) {
		string substr;
		getline(v, substr, ',');
		trackcompl.push_back(substr);
	}

	// Reading 10 line 
	file.getline(line, size);
	stringstream u(line);
	while (u.good()) {
		string substr;
		getline(u, substr, ',');
		majrCommonCompl.push_back(substr);
	}


	// Reading 11 line 
	file.getline(line, size);
	stringstream p(line);
	while (p.good()) {
		string substr;
		getline(p, substr, ',');
		majorCommonElect.push_back(substr);
	}


	return true;
}

ActionLoadPrgReq::~ActionLoadPrgReq()
{
}
