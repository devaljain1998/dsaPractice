import re

#To be completed --> More research is needed
def vowel_and_consonant_count(string):
    vowel_pattern = '[aeiouAEIOU]'
    consonant_pattern = 'a-zA-Z'

def keyword_and_identifier_counter(string):
    #All the keywords of the python (obtained through {import keyword})
    keyword_pattern = 'and|as|assert|break|class|continue|def|del|elif|else|except|exec|finally|for|from|global|if|import|in|is|lambda|not|or|pass|print|raise|return|try|while|with|yield'
    identifier_pattern = '[_a-zA-Z]+([0-9][_a-zA-Z])*'

def words_starts_and_with(character, string):
    pattern = f'{character}|^{character}.*{character}$'

def letter_symbol_space_digit_tabs_line_count(string):
    letter_pattern = '[a-zA-Z]'
    number_pattern = '[0-9]' #or \d also
    space_pattern = ' '
    tab_pattern = '\t'
    line_pattern = '\n'
    symbol_pattern = '' ##This is to be figured out -> Have to find a way to negate all the other patterns from the other characters

def is_valid_mobile_number(number): #->bool
    number_pattern = '[9|8|7|6][0-9]{9}' 
    # Not working for some reason
    # for testcase: '68290678912111', giving the correct result


def word_count(string):
    word_pattern = '[A-Z][a-z]*|[a-z]+'
    #This is again matching for the test case: 'hello10'

#Good Exercise
def eliminate_single_and_multiline_comment(text):
    comment_pattern = '#'
    doctype_pattern = '""".*"""'

def capital_small_special_symbol_count(word):
    capital_letter_pattern = '[A-Z]'
    small_letter_pattern = '[a-z]'
    number_pattern = '[0-9]'
    #special_symbol_pattern = ''

def prepend_line_number_to_each_line(text):
    line_no = 1
    new_line_pattern = '\n'
    curr_pos = int

def is_valid_email(email):
    email_pattern = '[a-zA-Z].*@[a-z]+\.[com|co|in|co\.in]'

def is_valid_url(url):
    url_pattern = 'http(s)?:\/\/(www\.)?[a-zA-Z][a-zA-Z0-9]*\.[co|in|co\.in|com][\/[a-zA-Z0-9\?=&,]*]'