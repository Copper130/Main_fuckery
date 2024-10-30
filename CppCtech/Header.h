#pragma once
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>

//Match first character
//cls
//Firstnames
//Lastnames
//is same
//enter_code
//average
//tenth power
//is palindrome
//get smallest

inline
bool First_letter(std::string text, std::string text2) {
	std::string reversed_text = "";


	reversed_text += text[0];


	if (reversed_text == text2) {
		return true;
	}

	return false;
}

std::vector<std::string> Firstnames = { "Bertha","Jaxsyn","Harriet","Murray","Emma","Miah","Nieve","Eric","Mason","Francis","Sian","John","Conner","Franklin","Xander","Lucy","David","Rebbeca","Josh","James","Corrine","Jeremy","Carlton","Kaylyn","Brendan","Danny","Miguel","Shantel","Raven","Raina","Stuart","Darion","Tristin","Ezra","Laisha","Addie","Vicente","Mikael","Jasper","Antonio","Emmalee","Sawyer","Norma","Jeniffer","Alysa","Jason","Regan","Madisen","Emerson","Elyssa","Ali","Zavier","Roland","Jazmyne","Felix","Shamar","Jennah","Jesse","Rochelle","Rayne","Stewart","Jonathon","Kentrell","Ernest","Tyrone","Lee","Konner","Taryn","Kristin","Cameron","Claudia","Eileen","Aleah","Kenan","Liza","Joe","Yosef","Joy","Dan","Alivia","River","Dillan","Raphael","Jocelyne","Zack","Donte","Arden","Kenton","Lola","Starr","Riana","Carter","Manuel","Martin","Zackery","Garett","Jayme","Jane","Ty","Sommer","Zain","Genevieve","Tamera","Mackenzi","Yvonne","Nathanael","Blake","Jensen","Taylor","Jamar","Aditya","Yamileth","Hazel","Rowan","Presley","Ariel","Elijah","Brenna","Quinten","Alesha","Roxanne","Emalee","Peyton","Raelynn","Elexis","Katrina","Justin","Duncan","Tania","Sheldon","Joan","Randall","Colby","Keagan","Jacoby","Breonna","Obed","Jillian","Aryana","Johnna","Hassan","Alea","Kori","Jordy","Reanna","Justine","Maribel","Royce","Ishmael","Natasha","Devonte","Damian","Clint","Adia","Dashawn","Darnell","Andre","Celine","Leo","Taniya","Judah","Emily","Connor","Melanie","Leonel","Kristian","Gwyneth","Ethen","Timothy","Marjorie","Triniti","Mandy","Dimitri","Kavon","Steven","Jerome","Jaclyn","Brianne","Cedrick","Cordell","Lisbeth","Esteban","Delia","Tyreese","Jalisa","Brionna","Tara","Arturo","Mikaela","Deante","Stormy","Cara","Chynna","Ivanna","Gwendolyn","Liberty","Morris","Yvette","Amos","Moises","Brendon","Kara","Jenny","Kelsi","Irvin","Betsy","Sofia","Mohammed","Raquel","Sage","Roger","Fernando","Ian","Kaitlin","Amaiya","Alayna","Catalina","Abraham","Alannah", "Landon", "Jay", "Vera", "Malik", "Rebecca", "Amberly", "Nicklaus", "Ezequiel", "Kayden", "Fredrick", "Nash", "Fatima", "Aisha", "Jake", "Ayden", "Alisha", "Alec", "Tessa", "Lloyd", "Myles", "Lexie", "Jaqueline", "Sahara", "Erin", "Kaylah", "Aidan", "Heidy", "Neal", "Natalya", "Mercedes", "Coleman", "Kent", "Oriana", "Luciano", "Saul", "Kaylen", "Aubrey", "Orlando", "Justina", "Gordon", "Cheryl", "Marisa", "Brennen", "Donavan", "Priscilla", "Breanne", "Mary", "Haley", "Desire", "Kolby", "Santos", "Destiny", "Kameron", "Laken", "Robin", "Deondre", "Olivia", "Madelyne", "Warren", "Annabelle", "Mallorie", "Kassandra", "Jami", "Lane", "Christian", "Elvin", "Josie", "Tionna", "Joel", "Dajuan", "Ally", "Caitlyn", "Ramon", "Gregorio", "Yousef", "Cristal", "Menachem", "Amina", "Nicholas", "Estefany", "Khadijah", "Graciela", "Dakotah", "Clara", "Devin", "Jamia", "Jaila", "Franco", "Cheyanne", "Vaughn", "Tatyanna", "Susan", "Tyquan", "Tucker", "Baylor" , "Marco                      4   ", "Gojo"

};
std::vector<std::string> Lastnames = { " Bell", "Robles", " Gibbons", " Dennis", " Henry", " Haas", " Branch", " Goodman", " Vincent", " Eaton", " Franklin", " Foley"," Farmer"," Hiatt"," Conti"," Mosher"," Fowler"," Guzman"," Ivey"," Salerno"," Gould"," Hammer"," Hamel"," Irizarry"," Zapata"," Wellman"," Hendrix"," Pena"," Royal"," Irvin"," Terrell"," Cota"," Cohn","  Presley"," Pollock"," Nagel"," Garcia"," Morris"," Kidwell"," Lanier"," Corbin"," Doss"," Menendez"," Byrnes"," Mojica"," Galvan"," Hurt"," Hinojosa"," Humphrey"," Garvey"," Wilson"," Faber"," McLean"," Porras"," Knowles"," Long"," Covington"," Rayburn"," Autry"," Noe"," Currie"," Ortiz"," Schneider"," Holman"," McCain"," McConnell"," Munoz"," Bonner"," Szymanski"," Lai"," Keeler"," Riddle"," Potts"," Noble"," Trahan"," Harder"," Dyson"," Xiong"," Arellano"," Alvarado"," Saldivar"," Elmore"," Carrier"," Havens"," Collins"," Munguia"," Needham"," Alonso"," Seifert"," Luciano"," Flannery"," Stanford"," Cardoza"," Giron"," Burke"," Whittaker"," Gaffney"," Dorman"," Padilla"," Couch"," Leggett"," Coble"," Cabral"," Cooke"," Kish"," Fields"," Mcallister"," Chong"," Ferrer"," Houghton"," Murphy"," Muhammad"," Joe"," Beers"," Power"," Sapp"," Fitzpatrick"," Mondragon"," Mancuso"," Kwon"," Valle"," Baca"," Lombardi"," Steffen"," Rosen"," Pierre"," Bradford"," Elrod"," Youngblood"," Cadena"," Wharton"," Campos"," Winn"," Eason"," Baumann"," Livingston"," Villasenor"," Acevedo"," Seidel"," Snodgrass"," Doll"," Koenig"," Taft"," Hahn"," Rodriguez"," Gerber"," Carpenter"," Banuelos"," Hoffman"," Short"," Fry"," Coleman"," Lundy"," Love"," Bobo"," Pinkerton"," Sorenson"," Varner"," Seitz"," Persaud"," Self"," Young"," Vines"," Witt"," Ritchie"," Turk"," Aldrich"," Pollard"," Byler"," White"," Cochrane"," Montano"," Dawkins"," Tafoya"," Heard"," Burger"," Coyle"," Gordon"," Lawler"," Huff"," Gipson"," Mayo"," Seaman"," Slocum"," Motley"," Ramos"," Whitfield"," Wilkerson"," Latimer"," Salazar"," Cornejo"," Gray"," Sherrill"," Barraza"," Shoemaker"," Robison"," Cho"," Macias"," Sumner"," Wu"," McCarthy"," Reinhart"," Levin"," Keefe"," Goldman"," Wahl"," Morrell", " Hunter" };

inline
bool is_same(std::string test, std::string test2) {

	return test == test2;
}

inline
void enter_code(int passcode) {

	if (passcode == 0310) {
		std::string secret_knowledge = "46191236987450461912";
		std::cout << secret_knowledge << "\n";

	}
	else {

		std::cout << "Sorry, incorrect!\n";

	}
}

template <typename T>
T average(T num1, T num2) {
	return (num1 + num2) / 2;
}

template <typename T>
T power(T num, T num2) {
	return pow(num, num2);
}

inline
bool is_palindrome(std::string text) {
	std::string reversed_text = "";

	for (int i = text.size() - 1; i >= 0; i--) {
		reversed_text += text[i];
	}

	if (reversed_text == text) {
		return true;
	}

	return false;
}

template <typename T>
T get_smallest(T num1, T num2) {

	return num2 < num1 ? num2 : num1;

}


