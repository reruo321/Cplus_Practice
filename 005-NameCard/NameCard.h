#pragma once

namespace COMP_POS {

	enum { CLERK, SENIOR, ASSIST, MANAGER };

}

class NameCard
{
	char* name;
	char* company_name;
	char* phone_number;
	int comp_pos;
	void ShowCompPos() const;

public:
	NameCard(const char* Name, const char* Company_Name, const char* Phone_Number, const int Comp_Pos);
	NameCard(const NameCard& copy);
	void ShowNameCardInfo() const;
	~NameCard();
};

