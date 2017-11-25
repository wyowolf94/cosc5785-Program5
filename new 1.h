class ClassA
{
  int myint1;
  int myint2;
  //int myint2; //error var declared twice
  int[] myintarr1;
  int [][] myintarr2;
  ClassA myClassA1;
   //ClassA myClassA1; //error var declared twice
  ClassB myClassB1;
  
  ClassA(){}
  
  void method1()
  {
    
     if((myClassA1 == null) && (myint1 == null)){}//error expressions not of same tyupe

     method2(myint1, myint2, myClassB1);//error no matching function call
     while(myClassA1){}//error expression does not evaluate to boolean
     //if(myClassA1){}//error expression does not evaluate to boolean
     //myint1 = myint2 + myClassA1;//errro expressions different types

  }
  
  int method2(int x, ClassA y, ClassB c)
  {
     return; //error does not match func return type
  }
}

class ClassB
{
}

class ClassC
{}
