<h1><b>Search engine<b></h1>
  
  
This is a code that can act as a library to search a keyword in an array or in a vector

<h4>Functions in it:</h4>
<ul>
  <li>searchS()- the function gets the key word the array and the array's length and returns a string with all of the words with the key word</li>
  <li>searchA()- the function gets the key word the array and the array's length and changes everything in the array that does not have the key word</li>
  <li>searchV()- the function gets the key word and the vector to look in and returns the vector only with the strings that has the key word in</li>
</ul>

  
Examples:
  
key word = "he"
array/vector = {"hello","ello","he","hihe","test"}
  
what it returns:
searchV()=> {hello, he, hihe}
searchS()=> "hello,he,hihe,"
searchA()=> array will be=> {"hello","","he","hihe",""}
