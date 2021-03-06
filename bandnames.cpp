#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <vector>

enum BAND_NAME_FORMAT {NameAndTheNoun, TheNoun, TheAdjectiveNoun, 
                       AdjectiveNoun, Name};


std::string getRandomLineFromFile(const char* filename) {
   // open the file 
   std::ifstream file(filename);
   
   // read file line by line into vector
   std::string line;
   std::vector<std::string> lines;
   while (std::getline(file, line)) {
      lines.push_back(line);
   }

   // pick and return a random line
   int randomIndex = rand() % lines.size();
   return lines[randomIndex]; 
}


std::string getRandomBandName() {
   int numberOfFormats = 5;
   std::string bandname;

   std::string firstname = getRandomLineFromFile("firstnames.txt");
   std::string lastname = getRandomLineFromFile("lastnames.txt");
   std::string noun = getRandomLineFromFile("nouns.txt");
   std::string adjective = getRandomLineFromFile("adjectives.txt");

   noun[0] = toupper(noun[0]);  
   adjective[0] = toupper(adjective[0]);

   // pick from a list of name formats
   // assume rand is already seeded
   // need to cast the type produced by rand to ensure type safety
   BAND_NAME_FORMAT format = BAND_NAME_FORMAT(rand() % (numberOfFormats-1));

   switch(format) {
   case NameAndTheNoun:
      {
         bandname = firstname + " and the " + noun;
      }
      break;

   case TheNoun:
      {
         bandname = noun;
      }
      break;

   case TheAdjectiveNoun:
      {
         bandname = "The " + adjective + " " + noun;
      }
      break;
   
   case AdjectiveNoun:
      {
         bandname = adjective + " " + noun;
      }
      break;
   
   case Name:
      {
         bandname = firstname + " " + lastname;
      }
      break;
   }

   return bandname;
}



int main() {
   srand(time(NULL));
   for(int i=0; i<10; i++) {
      std::cout<<getRandomBandName()<<std::endl;
   }
   return 0;
}
