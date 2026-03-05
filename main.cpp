#include "lexer.h"
#include "automate.h"

int main(void) {
   string chaine("(20+1)*2");
   Lexer l(chaine);
   
   Automate automate(&l); 
   
   automate.start();
   
   return 0;
}
