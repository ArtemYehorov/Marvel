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
			cout << "Особых способностей нет\n";
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

class СharacteristicsPerson : public Flight, public SuperStrength, public SuperSpeed, public Regeneration, public SpecialAbilities, public Race, public CivilPosition
{
private:
	string Name;
	string Alias;
	int Age;
public:
	СharacteristicsPerson()
	{
		Name = "Тор";
		Alias = "Бог Грома";
		Age = 1500;
		SetFlight(true);
		SetStrength(true);
		SetRegeneration(true);
		SetSpeed(false);
		SetSpePowers("Управляет молниями");
		SetSpePowers("Управляет Штормбрейкером");
		SetSpePowers("Божественная выносливость");
		SetRace("Бог");
		SetPosition("Герой");
	}
	СharacteristicsPerson(string name, string alias, int age, bool f, bool S, bool R, bool spe, string SpePow, string race, string posi)
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
		cout <<"Имя - " << GetName() << "\n";
		cout <<"Псевдоним - " << GetAlias() << "\n";
		cout <<"Возвраст - " << GetAge() << "\n";
		cout <<"Раса - " << GetRace() << "\n";
		cout <<"Принадлежность - " << GetPosition() << "\n";
		if (GetFlight() || GetStrength() || GetRegeneration() || GetSpeed())
		{
			cout << "Суперспособности - ";
			if (GetFlight())
			{
				cout << "умеет летать, ";
			}
			if (GetStrength())
			{
				cout << "cуперсила, ";
			}
			if (GetRegeneration())
			{
				cout << "регенерация, ";
			}
			if (GetSpeed())
			{
				cout << "суперскорость, ";
			}
			cout << "\n";
		}
		else
		{
			cout << "Суперспособностей нет\n";
		}
		cout << "Особые способности - ";
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

void Flighting(vector<СharacteristicsPerson>& pers)
{
	cout << "Умеют летать - ";
	for (int i = 0; i < pers.size(); i++)
	{
		if (pers[i].GetFlight())
		{
			cout << pers[i].GetAlias() << " ";
		}
	}
	cout << "\n\n";

}

void Flyers(vector<СharacteristicsPerson>& flyers, vector<СharacteristicsPerson>& pers)
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
	vector<СharacteristicsPerson> Persons;
	setlocale(0, "ru");
	СharacteristicsPerson Tor;
	СharacteristicsPerson Halk("Брюс", "Халк", 47, false, true, true, false, "Высокий интеллект, в форме Халка - Высокий прыжок, неуязвимость к гамма излучению, неуязвимость к большинству урона.", "Человек", "Герой");
	СharacteristicsPerson IronMan("Энтони", "Железный Человек", 53, true, false, false, false, "Высокий интеллект, миллиардер, Железный костюм который позволяет летать, выдерживать гигантские нагрузки, и увеличивает силу в несколько раз", "Человек", "Герой");
	СharacteristicsPerson Thanos("Танос", "Безумный Титан", 25000, false, true, true, false, "Способен выдержать силу камней бессконечности", "СверхЧеловек", "Злодей");
	Thanos.SetSpePowers("С помощью Камня времени - манипуляция временем, возвращение в прошлое и способность видеть будущее.");
	Thanos.SetSpePowers("С помощью Камня реальности - манипуляция ряльностью, создание клонов, терраформация, иллюзии.");
	Thanos.SetSpePowers("С помощью Камня пространства - манипуляция пространством, возможность перемещения на огромные расстояния и даже в другие вселенные.");
	Thanos.SetSpePowers("С помощью Камня силы - огромная сила, управление огромным количеством кинетической энергии.");
	Thanos.SetSpePowers("С помощью Камня разума - владеет псионическими силами, например, телепатия и телекинез. Получает доступ к мыслям и мечтам других существ.");
	Thanos.SetSpePowers("С помощью Камня души - даёт способность считывать информацию с душ других людей, а также определять подлинную душу");
	СharacteristicsPerson Ultron("Альтрон", "Альтрон", 0, true, true, true, true, "Высокий интеллект,способность перемещаться на огромных скоростях, возможность летать на другие планеты бех использования транспорта, доступ ко всей информации доступной в интернете, может клонировать себя", "Робот", "Злодей");

	Persons.push_back(Tor);
	Persons.push_back(Halk);
	Persons.push_back(IronMan);
	Persons.push_back(Thanos);
	Persons.push_back(Ultron);
	for (int i = 0; i < Persons.size(); i++)
	{
		Persons[i].Print();
	}

	vector<СharacteristicsPerson> flyers;
	Flighting(Persons);

	Flyers(flyers, Persons);

	for (int i = 0; i < flyers.size(); i++)
	{
		flyers[i].Print();
	}

}