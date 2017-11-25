Readme.txt
Shaya Wolf

 - I allow a var and a method to have the same name but methods can't
   be overloaded unless they have different parameters
 - The var names print backwards because it wasn't worth making a 
   backwards iterator
 - I don't allow you to add "null", so x = 5+null is bogus.
 - matching parameters in a method call to the correct entry in a symboltable
   sometimes doesn't work right
 - mathcing the reutrn type of a function with the type in return statement
   does not always work.
 - most lval rval stuff works, but sometimes you can add two variables of 
   different types together without it throwing an error
   
 will try to fix tonight, but I needed to turn in something