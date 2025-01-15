#include <iostream>
#include <vector>

using namespace std;

struct CoursDesires{
	string nomCours{};
	pair<int, int> possede_Veux{};
	CoursDesires(string nom, pair<int, int> pv) { nomCours = nom;possede_Veux = pv; }
};

struct Etudiant {
	string nom{};
	vector<CoursDesires> cours{};
	Etudiant(string nomm) { nom = nomm; }
};

void afficherCours(CoursDesires& cours) {
	cout << cours.nomCours << " : {" << cours.possede_Veux.first << ", " << cours.possede_Veux.second << "}\n";
}
void afficherEtudiant(Etudiant& etudiant) {
	cout << etudiant.nom << endl;
	for (auto& cour : etudiant.cours) {
		afficherCours(cour);
	}
	cout << endl;
}

int main() {
	Etudiant LuneEve{ "LuneEve" };
	LuneEve.cours.push_back(CoursDesires("mth2304", { 2, 1 }));
	
	Etudiant PhiLuan{ "PhiLuan" };
	PhiLuan.cours.push_back(CoursDesires("inf3405", { 3, 1 }));
	PhiLuan.cours.push_back(CoursDesires("mth2304", { 3, 1 }));
	// Mo
	Etudiant Mo{ "Mo" };
	Mo.cours.push_back(CoursDesires("mth2304", { 3, 1 }));
	Mo.cours.push_back(CoursDesires("inf2610", { 2, 1 }));
	Mo.cours.push_back(CoursDesires("log2990", { 3, 2 }));
	Mo.cours.push_back(CoursDesires("ssh3501", { 6, 4 }));

	// LimSa
	Etudiant LimSa{ "LimSa" };
	LimSa.cours.push_back(CoursDesires("log2990", { 3, 2 }));

	// Rubamun
	Etudiant Rubamun{ "Rubamun" };
	Rubamun.cours.push_back(CoursDesires("inf2610", { 3, 4 }));
	Rubamun.cours.push_back(CoursDesires("ssh3501D", { 1, 4 })); // Assumption made for "01 -> SSH3501 04"

	// Adam Lecavalier
	Etudiant AdamLecavalier{ "AdamLecavalier" };
	AdamLecavalier.cours.push_back(CoursDesires("log2990", { 3, 2 }));

	// Hassib Kevin Ezzedine
	Etudiant HassibKevinEzzedine{ "HassibKevinEzzedine" };
	HassibKevinEzzedine.cours.push_back(CoursDesires("mth2304", { 3, 1 }));
	HassibKevinEzzedine.cours.push_back(CoursDesires("inf3405", { 1, 3 }));
	HassibKevinEzzedine.cours.push_back(CoursDesires("ssh3501", { 6, 4 }));
	HassibKevinEzzedine.cours.push_back(CoursDesires("inf2610", { 5, 3 }));

	// Yanni Si-Hocine
	Etudiant YanniSiHocine{ "YanniSiHocine" };
	YanniSiHocine.cours.push_back(CoursDesires("phs1101", { 3, 2 }));

	vector<Etudiant> etudiants{ LuneEve, PhiLuan, Mo, LimSa, Rubamun, AdamLecavalier, HassibKevinEzzedine, YanniSiHocine };

	for (auto& etudiant : etudiants) {
		afficherEtudiant(etudiant);
	}
	cout << "======================================\n";

	for (size_t i = 0; i < etudiants.size() - 1; ++i) {
		for (size_t j = i + 1; j < etudiants.size(); ++j) {
			for (auto& coursDesire : etudiants[i].cours) {
				for (auto& coursDesireAutre : etudiants[j].cours) {
					if (coursDesire.nomCours == coursDesireAutre.nomCours) {
						if (coursDesire.possede_Veux.first == coursDesireAutre.possede_Veux.second ||
							coursDesireAutre.possede_Veux.first == coursDesire.possede_Veux.second) {
							cout << etudiants[i].nom << endl;
							afficherCours(coursDesire);
							cout << etudiants[j].nom << endl;
							afficherCours(coursDesireAutre);
							cout << endl;
						}
						break;
					}
				}
			}
		}
	}


}