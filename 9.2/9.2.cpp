#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 

using namespace std;
int(x);
enum Specialty { Інженер, Спеціаліст, Програміст };

string strSpecialty[] = { "Інженер   ", "Спеціаліст", "Програміст"};

struct Pracivnuk
{
	string prizv;
	string name;
	Specialty specialty;
	unsigned tel;
	short unsigned dey;
	short unsigned mans;
	short unsigned yer;
};

void Create(Pracivnuk* s, const int N);
void Print(Pracivnuk* s, const int N);

double  poshyk(Pracivnuk* s, const int N);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N;
	cout << "Кількість Працівників: "; cin >> N;
	Pracivnuk* s = new Pracivnuk[N];
	Create(s, N);
	Print(s, N);
	cout << "| Народився в цей місяць " << fixed << poshyk(s, N) << "|" << endl;

	cout << "================================================================================" << endl;
	delete[] s;
}

void Create(Pracivnuk* s, const int N)
{
	int tel, specialty;
	for (int i = 0; i < N; i++)
	{
		cout << "№ " << i + 1 << ":" << endl;
		cin.get();
		cin.sync();
		cout << "  прізвище: "; getline(cin, s[i].prizv);
		cout << "  ім'я: "; getline(cin, s[i].name);
		cout << "  tel: "; cin >> s[i].tel;
		cout << "  спеціальність (0-Інженер, 1-Спеціаліст,2- Програміст ): "; cin >> specialty;
		s[i].specialty = (Specialty)specialty;
		cout << "  День народження "; cin >> s[i].dey;
		cout << "  Місяць "; cin >> s[i].mans;
		cout << "  Рік "; cin >> s[i].yer;
	}
}

void Print(Pracivnuk* s, const int N)
{
	cout << "================================================================================"
		<< endl;
	cout << "| №  | Прізвище     | Ім'я    |tel        | Спеціальність   |День|Місяць|Рік|"
		<< endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(2) << right << i + 1 << " "
			<< "| " << setw(13) << left << s[i].prizv
			<< "| " << setw(3) << right << s[i].name << "  "
			<< "| " << setw(3) << right << s[i].tel << "  "
			<< "| " << setw(8) << right << strSpecialty[s[i].specialty] << "      "
			<< "| " << setw(1) << right << s[i].dey << "   "
			<< "| " << setw(1) << right << s[i].mans << "      "
			<< "| " << setw(1) << right << s[i].yer << "     |" << endl;
	}
	cout << "================================================================================" << endl;
}



double poshyk(Pracivnuk* s, const int N)

{
	cout << "Введіть місяць народження для пошуку працівника";cin >> x;
	int k = 0;
	for (int i = 0; i < N; i++)
		if (s[i].mans == x)
		{
			k++;
			cout << setw(3) << right << k
				<< " " << s[i].prizv << endl;
		}
		else
			cout << "0";
	return 0;
}



