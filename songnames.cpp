#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <vector>

enum SONG_NAME_FORMAT {AdjectiveNoun, PluralPronounAreAdjective, 
                       PossessivePronounAdjectiveNoun, 
                       TheAdjectiveNoun, NounOfTheNoun,
                       NounVerb, NounVerbAdverb};


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


std::string getRandomSongName() {
   int numberOfFormats = 7;
   std::string songname;

   std::string pluralpronoun = getRandomLineFromFile("pluralpronouns.txt");
   std::string possessivepronoun = 
      getRandomLineFromFile("possessivepronouns.txt");
   std::string noun = getRandomLineFromFile("nouns.txt");
   std::string noun2 = getRandomLineFromFile("nouns.txt");
   std::string adjective = getRandomLineFromFile("adjectives.txt");
   std::string verb = getRandomLineFromFile("verbs.txt");
   std::string adverb = getRandomLineFromFile("adverbs.txt");
   noun[0] = toupper(noun[0]);  
   noun2[0] = toupper(noun2[0]);
   adjective[0] = toupper(adjective[0]);
   verb[0] = toupper(verb[0]);
   adverb[0] = toupper(adverb[0]);

   // pick from a list of name formats
   // assume rand is already seeded
   // need to cast the type produced by rand to ensure type safety
   SONG_NAME_FORMAT format = SONG_NAME_FORMAT(rand()%(numberOfFormats-1));

   switch(format) {
   case AdjectiveNoun:
      {
         songname = adjective + " " + noun;
      }
      break;
   case PluralPronounAreAdjective:
      {
         songname = pluralpronoun + " are " + adjective;
      }
      break;
   case PossessivePronounAdjectiveNoun:
      {
         songname = possessivepronoun + " " + adjective + " " + noun;
      }
      break;
   case TheAdjectiveNoun:
      {
         songname = "The " + adjective + " " + noun;
      }
      break;
   case NounOfTheNoun:
      {
         songname = noun + " Of The " + noun2;
      }
      break;
   case NounVerb:
      {
         songname = noun + " " + verb;
      }
      break;
   case NounVerbAdverb:
      {
         songname = noun + " " + verb + " " + adverb;
      }
      break;


   }


   return songname;
}



int main() {
   srand(time(NULL));
   for(int i=0; i<10; i++) {
      std::cout<<getRandomSongName()<<std::endl;
   }
   return 0;
}
