#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Flight abstract 
{
private:
	bool Flight;
public:
	void SetFlight(bool f)
	{
		Flight = f;
	}
	bool GetFlight() const
	{
		return Flight;
	}
};

class SuperStrength abstract
{
private:
	bool Strength;
public:
	void SetStrength(bool s)
	{
		Strength = s;
	}
	bool GetStrength() const
	{
		return Strength;
	}
};

class SuperSpeed abstract 
{
private:
	bool Speed;
public:
	void SetSpeed(bool S)
	{
		Speed = S;
	}
	bool GetSpeed() const
	{
		return Speed;
	}
};

class Regeneration abstract 
{
private:
	bool regeneration;
public:
	void SetRegeneration(bool r)
	{
		regeneration = r;
	}
	bool GetRegeneration() const
	{
		return regeneration;
	}
};

class SpecialAbilities abstract
{
private:
	vector<string> abilities;
public:
	void SetSpePowers(string s)
	{
		abilities.push_back(s);
	}
	void GetSpePowers() const
	{
		if (abilities.size() != 0)
		{
			for (int i = 0; i < abilities.size(); i++)
			{
				cout << abilities[i] << ", ";
			}
		}
		else
		{
			cout << "������ ������������ ���\n";
		}
	}
};

class Race abstract
{
private:
	string race;
public:
	void SetRace(string r)
	{
		race = r;
	}
	string GetRace() const
	{
		return race;
	}
};

class CivilPosition abstract
{
private:
	string Position;
public:
	void SetPosition(string p)
	{
		Position = p;
	}
	string GetPosition() const
	{
		return Position;
	}
};

class �haracteristicsPerson : public Flight, public SuperStrength, public SuperSpeed, public Regeneration, public SpecialAbilities, public Race, public CivilPosition
{
private:
	string Name;
	string Alias;
	int Age;
public:
	�haracteristicsPerson()
	{
		Name = "���";
		Alias = "��� �����";
		Age = 1500;
		SetFlight(true);
		SetStrength(true);
		SetRegeneration(true);
		SetSpeed(false);
		SetSpePowers("��������� ��������");
		SetSpePowers("��������� ��������������");
		SetSpePowers("������������ ������������");
		SetRace("���");
		SetPosition("�����");
	}
	�haracteristicsPerson(string name, string alias, int age, bool f, bool S, bool R, bool spe, string SpePow, string race, string posi)
	{
		SetName(name);
		SetAlias(alias);
		SetAge(age);
		SetFlight(f);
		SetStrength(S);
		SetRegeneration(R);
		SetSpeed(spe);
		SetSpePowers(SpePow);
		SetRace(race);
		SetPosition(posi);
	}
	
	void Print() const
	{
		cout <<"��� - " << GetName() << "\n";
		cout <<"��������� - " << GetAlias() << "\n";
		cout <<"�������� - " << GetAge() << "\n";
		cout <<"���� - " << GetRace() << "\n";
		cout <<"�������������� - " << GetPosition() << "\n";
		if (GetFlight() || GetStrength() || GetRegeneration() || GetSpeed())
		{
			cout << "���������������� - ";
			if (GetFlight())
			{
				cout << "����� ������, ";
			}
			if (GetStrength())
			{
				cout << "c��������, ";
			}
			if (GetRegeneration())
			{
				cout << "�����������, ";
			}
			if (GetSpeed())
			{
				cout << "�������������, ";
			}
			cout << "\n";
		}
		else
		{
			cout << "����������������� ���\n";
		}
		cout << "������ ����������� - ";
		GetSpePowers();
		cout << "\n\n";
	}

	void SetName(string N)
	{
		Name = N;
	}
	string GetName() const
	{
		return Name;
	}
	void SetAlias(string A)
	{
		Alias = A;
	}
	string GetAlias() const
	{
		return Alias;
	}
	void SetAge(int a)
	{
		Age = a;
	}
	int GetAge() const
	{
		return Age;
	}
};

void Flighting(vector<�haracteristicsPerson>& pers)
{
	cout << "����� ������ - ";
	for (int i = 0; i < pers.size(); i++)
	{
		if (pers[i].GetFlight())
		{
			cout << pers[i].GetAlias() << " ";
		}
	}
	cout << "\n\n";

}

void Flyers(vector<�haracteristicsPerson>& flyers, vector<�haracteristicsPerson>& pers)
{
	for (int i = 0; i < pers.size(); i++)
	{
		if (pers[i].GetFlight())
		{
			flyers.push_back(pers[i]);
		}
	}
}

int main()
{
	vector<�haracteristicsPerson> Persons;
	setlocale(0, "ru");
	�haracteristicsPerson Tor;
	�haracteristicsPerson Halk("����", "����", 47, false, true, true, false, "������� ���������, � ����� ����� - ������� ������, ������������ � ����� ���������, ������������ � ����������� �����.", "�������", "�����");
	�haracteristicsPerson IronMan("������", "�������� �������", 53, true, false, false, false, "������� ���������, ����������, �������� ������ ������� ��������� ������, ����������� ���������� ��������, � ����������� ���� � ��������� ���", "�������", "�����");
	�haracteristicsPerson Thanos("�����", "�������� �����", 25000, false, true, true, false, "�������� ��������� ���� ������ ��������������", "������������", "������");
	Thanos.SetSpePowers("� ������� ����� ������� - ����������� ��������, ����������� � ������� � ����������� ������ �������.");
	Thanos.SetSpePowers("� ������� ����� ���������� - ����������� ����������, �������� ������, �������������, �������.");
	Thanos.SetSpePowers("� ������� ����� ������������ - ����������� �������������, ����������� ����������� �� �������� ���������� � ���� � ������ ���������.");
	Thanos.SetSpePowers("� ������� ����� ���� - �������� ����, ���������� �������� ����������� ������������ �������.");
	Thanos.SetSpePowers("� ������� ����� ������ - ������� ������������� ������, ��������, ��������� � ���������. �������� ������ � ������ � ������ ������ �������.");
	Thanos.SetSpePowers("� ������� ����� ���� - ��� ����������� ��������� ���������� � ��� ������ �����, � ����� ���������� ��������� ����");
	�haracteristicsPerson Ultron("�������", "�������", 0, true, true, true, true, "������� ���������,����������� ������������ �� �������� ���������, ����������� ������ �� ������ ������� ��� ������������� ����������, ������ �� ���� ���������� ��������� � ���������, ����� ����������� ����", "�����", "������");

	Persons.push_back(Tor);
	Persons.push_back(Halk);
	Persons.push_back(IronMan);
	Persons.push_back(Thanos);
	Persons.push_back(Ultron);
	for (int i = 0; i < Persons.size(); i++)
	{
		Persons[i].Print();
	}

	vector<�haracteristicsPerson> flyers;
	Flighting(Persons);

	Flyers(flyers, Persons);

	for (int i = 0; i < flyers.size(); i++)
	{
		flyers[i].Print();
	}

}