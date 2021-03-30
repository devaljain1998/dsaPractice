"""
This question is to solve some simple kth grammar recursion problem
"""

def generate_grammar(n):
        if (n == 0): return "0"

        grammar_map = {'0': '01', '1': '10'}

        # Induction:
        # get grammar from previous number:
        previous_grammar = generate_grammar(n - 1)

        new_grammar_list = []

        for digit in previous_grammar:
                new_grammar_list.append(grammar_map[digit])

        new_grammar = "".join(new_grammar_list)

        return new_grammar

# Driver
if __name__ == "__main__":
        for i in range(1, 11):
                print(f"{i}: {generate_grammar(i)}")
        print("Complete!")