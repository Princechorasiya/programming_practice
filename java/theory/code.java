//createing jar file from the class file 
jar --create --file main.jar main.class
java -cp main.jar main //executing the jar file 



java.lang.reflect.Field 
java.lang.reflect.Method 

Class c1 =obj.getClass(); 
c1.getName() ;
Method m[] =c1.getDeclaredMethods();
Field f[] =c1.getDeclaredFields(); 


// for every .class file only 1 object is created 

jvm uses three types of loaders 
bootstrap loaders 
extension loaders
application loaders 



// # swap java 
Collections.swap(vector,0,4)  // swap indexes 