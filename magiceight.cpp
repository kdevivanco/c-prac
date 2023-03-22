#include <iostream>
#include <cstdlib>
#include <string>

int main(){
  //Your future is here
  srand(time(NULL));

  std::cout << "MAGIC 8-BALL:\n\n";

  int answer = std::rand() % 10 ;

  std::cout << answer << "\n";

  std::string answers[] = {
    "It is certain.",
    "It is decidedly so.",
    "Without a doubt.",
    "Yes - definitely.",
    "You may rely on it.",
    "As I see it, yes.",
    "Most likely.",
    "Outlook good.",
    "Yes.",
    "Signs point to yes."
  };

  int index = answer - 1;

  std::cout << answers[index];

}