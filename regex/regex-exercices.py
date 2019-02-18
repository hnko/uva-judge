import re

"""
1. Write a Python program to check that a string contains only a certain set of characters (in this case a-z, A-Z and 0-9).
"""

def is_allowed_specific_char(string):
    charRe = re.compile(r'\W+') #other way [^a-zA-Z0-9]
    string = charRe.search(string)
    return bool(string)

print('1...')
print(is_allowed_specific_char("ABCDEFabcdef123450")) 
print(is_allowed_specific_char("*&%@#!}{"))

"""
2. Write a Python program that matches a string that has an a or more a followed by zero or more b's. 
"""
def is_a_b(string):
	pattern = re.compile(r'^a+b*$')
	return bool(pattern.match(string))

print('2...')
print(is_a_b('aaaaabb'))
print(is_a_b('ac'))

"""
3. Write a Python program that matches a string that has an a followed by one or more b's
"""
def is_a_bb(string):
	pattern = re.compile(r'^ab+$')
	return bool(pattern.match(string))

print('3...')
print(is_a_bb('abbbbbb'))
print(is_a_bb('a'))

"""
4. Write a Python program that matches a string that has an a followed by zero or one 'b'
"""
def is_a_b0(string):
	pattern = re.compile(r'^ab*$')
	return bool(pattern.match(string))

print('4...')
print(is_a_b0('abbbbbb'))
print(is_a_b0('ac'))

"""
5. Write a Python program that matches a string that has an a followed by three 'b'. 
"""
def is_a_3b(string):
	pattern = re.compile(r'^a(b{3})?$')
	return bool(pattern.match(string))

print('5...')
print(is_a_3b('abbbbbb'))
print(is_a_3b('abbb'))
print(is_a_3b('a'))

"""
6. Write a Python program that matches a string that has an a followed by two to three 'b'
"""
def is_a_23b(string):
	pattern = re.compile(r'^a(b{2,3})?$')
	return bool(pattern.match(string))

print('6...')
print(is_a_23b('abbbbbb'))
print(is_a_23b('abbb'))
print(is_a_23b('abb'))
print(is_a_23b('ab'))

"""
7. Write a Python program to find sequences of lowercase letters joined with a underscore. 
"""
def lower_(string):
	pattern = re.compile(r'^[a-z]+_[a-z]+$')
	return bool(pattern.match(string))

print('7...')
print(lower_('a_b'))
print(lower_('_b'))
print(lower_('a_'))
print(lower_('aaaaa_bbbbb'))
print(lower_('aaaaa__bbbbb'))

"""
9. Write a Python program that matches a string that has an 'a' followed by anything, ending in 'b'. Go to the editor
"""
def nine(string):
	pattern  = re.compile(r'^a.*b$')
	return bool(pattern.match(string))

print('8...')
print(nine('a_b'))
print(nine('_b'))
print(nine('a_  3?.   b'))


"""
10. Write a Python program that matches a word at the beginning of a string. Go to the editor
"""
def ten(string):
	pattern  = re.compile(r'^\w+')
	return bool(pattern.match(string))

print('10...')
print(ten('a_b'))
print(ten('aa sdsd_!'))

"""
11. Write a Python program that matches a word at end of string, with optional punctuation. Go to the editor
"""

def eleven(string):
	pattern  = re.compile(r'\w+\S*$')
	return bool(pattern.match(string))
print('11...')
print(eleven('a_b!'))
print(eleven('aa sdsd_! '))

"""
12. Write a Python program that matches a word containing 'z'. Go to the editor
"""
def twelve(string):
	pattern = re.compile(r'\w*z{1,}\w*')
	return re.findall(pattern, string)

print('12...')
print(twelve('hola z aozaa, zzzzzassa'))

"""
13. Write a Python program that matches a word containing 'z', not start or end of the word. 
"""
def thirteen(string):
	pattern = re.compile(r'[a-y]+z{1,}[a-y]+')
	return re.findall(pattern, string)

print('13...')
print(thirteen('hola z aozaa zzzzzassa'))

"""
14. Write a Python program to match a string that contains only upper and lowercase letters, numbers, and underscores. 
"""
def fourteen(string):
	pattern = re.compile(r'(?i)[a-z_]*$')
	return bool(pattern.match(string))

print('14...')
print(fourteen('nin nini'))
print(fourteen('ninc_nini'))
print(fourteen('MinW_nini'))

"""
15. Write a Python program where a string will start with a specific number. Go to the editor
"""
def fifteen(string):
	pattern = re.compile(r'^\d+\w*')
	return bool(pattern.match(string))

print('15...')
print(fifteen('12 nini'))
print(fifteen('ninc_nini 12'))
print(fifteen('1231231'))	

"""
16. Write a Python program to remove leading zeros from an IP address. Go to the editor
"""
def sixteen(string):
	return re.sub(r'\.[0]*', '.', string)

print('16...')
print(sixteen('21.001.02.009'))

"""
17. Write a Python program to check for a number at the end of a string. Go to the editor
"""
def seventeen(string):
	pattern = re.compile(r'.*\d+$')
	return bool(pattern.match(string))

print('\n17...')
print(seventeen(' asdasd ! 12'))
print(seventeen(' asdasd ! 122s'))
print(seventeen('12'))

"""
18. Write a Python program to search the numbers (0-9) of length between 1 to 3 in a given string. Go to the editor
"""
def eighteen(string):
	pattern = re.compile(r'^[0-9]{1,3}$')
	return bool(pattern.match(string))

print('\n18...')
print(eighteen(' asdasd ! 12'))
print(eighteen('12344'))
print(eighteen('123'))
print(eighteen('12'))	

"""
19. Write a Python program to search some literals strings in a string. Go to the editor
Sample text : 'The quick brown fox jumps over the lazy dog.'
Searched words : 'fox', 'dog', 'horse'
"""
def nineteen(string):
	patterns = ['fox', 'dog', 'horse']
	for pattern in patterns:
		print(bool(re.search(pattern, string)), pattern)

print('\n19...')
nineteen('The quick brown fox jumps over the lazy dog.')

"""
20. Write a Python program to search a literals string in a string and also find the location within the original string where the pattern occurs. Go to the editor

Sample text : 'The quick brown fox jumps over the lazy dog.'
Searched words : 'fox'

21. Write a Python program to find the substrings within a string. Go to the editor

Sample text :

'Python exercises, PHP exercises, C# exercises'

Pattern :

'exercises'

Note: There are two instances of exercises in the input string.


22. Write a Python program to find the occurrence and position of the substrings within a string. Go to the editor


"""
def twenty(string):
	pattern = re.compile(r'dog')
	for match in pattern.finditer(string):
		print(match.start(), match.end())
print('\n20...')
twenty('The quick brown fox dog jumps over the lazy dog.')


"""
25. Write a Python program to convert a date of yyyy-mm-dd format to dd-mm-yyyy format. Go to the editor
"""
def twentyfive(string):
	pattern = re.compile(r'(\d{4})-(\d{2})-(\d{2})')
	return re.sub(pattern, r'\3-\2-\1', string)

print('\n25...')
print(twentyfive('2015-31-01'))

"""
26. Write a Python program to match if two words from a list of words starting with letter 'P'. Go to the editor
"""
def twentysix(string):
	for word in string:
		print(bool(re.match(r'^P', word)))
print('\n26...')
twentysix(['Pato', 'pato'])

"""
27. Write a Python program to separate and print the numbers of a given string. Go to the editor
"""
def twentyseven(string):
	return re.findall(r'\d+', string)
print('\n27...')
print(twentyseven('1n22n33n45m667n888mk5555 5n566n777'))

"""
28. Write a Python program to find all words starting with 'a' or 'e' in a given string. Go to the editor
"""
def twentyeight(string):
	return re.findall(r'\b[ae]\w+', string)
print(twentyeight('alamo elamo alimo olamo'))

"""
29. Write a Python program to separate and print the numbers and their position of a given string. Go to the editor
"""
def twentynine(string):
	for i in re.finditer(r'\d+', string):
		print(i.group(), i.start(), i.end())

twentynine('1n2n3n4n1111nnnnn123n11110!')

"""
30. Write a Python program to abbreviate 'Road' as 'Rd.' in a given string. Go to the editor
"""
def thirty(string):
	return re.sub(r'Road\b', 'Rd.', string)

print(thirty('Roadlll is the Road my Road'))
"""
31. Write a Python program to replace all occurrences of space, comma, or dot with a colon. Go to the editor
"""
def thiryone(string):
	return re.sub(r'[ ,.]', ':', string)

print(thiryone('hola como, estas.'))

"""
32. Write a Python program to replace maximum 2 occurrences of space, comma, or dot with a colon. Go to the editor

33. Write a Python program to find all five characters long word in a string. Go to the editor

34. Write a Python program to find all three, four, five characters long words in a string. Go to the editor

35. Write a Python program to find all words which are at least 4 characters long in a string. Go to the editor

36. Write a python program to convert camel case string to snake case string. Go to the editor

37. Write a python program to convert snake case string to camel case string. Go to the editor

38. Write a Python program to extract values between quotation marks of a string. Go to the editor

39. Write a Python program to remove multiple spaces in a string. Go to the editor

40. Write a Python program to remove all whitespaces from a string. Go to the editor

41. Write a Python program to remove everything except alphanumeric characters from a string. Go to the editor

42. Write a Python program to find urls in a string. Go to the editor

43. Write a Python program to split a string at uppercase letters. Go to the editor

44. Write a Python program to do a case-insensitive string replacement. Go to the editor

45. Write a Python program to remove the ANSI escape sequences from a string. Go to the editor

46. Write a Python program to find all adverbs and their positions in a given sentence. Go to the editor

Sample text : "Clearly, he has no excuse for such behavior."

Click me to see the solution

47. Write a Python program to split a string with multiple delimiters. Go to the editor

Note : A delimiter is a sequence of one or more characters used to specify the boundary between separate, independent regions in plain text or other data streams. An example of a delimiter is the comma character, which acts as a field delimiter in a sequence of comma-separated values.

Click me to see the solution

48. Write a Python program to check a decimal with a precision of 2. Go to the editor

Click me to see the solution

49. Write a Python program to remove words from a string of length between 1 and a given number. Go to the editor

Click me to see the solution

50. Write a Python program to remove the parenthesis area in a string. Go to the editor
Sample data : ["example (.com)", "w3resource", "github (.com)", "stackoverflow (.com)"]
Expected Output: 
example
w3resource
github
stackoverflow
Click me to see the solution

51. Write a Python program to insert spaces between words starting with capital letters. Go to the editor
Click me to see the solution

Python Code Editor:

More to Come !

Do not submit any solution of the above exercises at here, if you want to contribute go to the appropriate exercise page.

New Exercises:R Programming


 


 
"""










