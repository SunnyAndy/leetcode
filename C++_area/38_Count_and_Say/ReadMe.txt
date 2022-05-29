


recursive methond 

if n==1 
return "1"

else 

return   string_processing(countandsay(n-1))



string_processiing is really did the count and say behavior 



for further optimizer 
create a table if the n is calculated just return else calculate ;

versiong 2: 


recursive methond

if n==1
return "1"

else if (n is in table ) {
	return the table;

}esle {

  update the table with the string_processing  (countandsay(n-1))
  and return string_processing(countandsay(n-1))
  



