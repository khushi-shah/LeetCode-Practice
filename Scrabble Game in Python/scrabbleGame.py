import pandas as pd
import random


def split(word):
    return [char for char in word]


def score(word):
    letters = split(word)
    score1 = 0
    one = ['E', 'A', 'O', 'I', 'N', 'R', 'T', 'L', 'S', 'U']
    two = ['D', 'G']
    three = ['B', 'C', 'M', 'P']
    four = ['F', 'H', 'V', 'W', 'Y']
    five = ['K']
    eight = ['J', 'X']
    ten = ['Q', 'Z']
    for i in range(len(letters)):
        letter = letters[i]
        for j in range(len(one)):
            if letter == one[j]:
                score1 += 1
        for j in range(len(two)):
            if letter == two[j]:
                score1 += 2
        for j in range(len(three)):
            if letter == three[j]:
                score1 += 3
        for j in range(len(four)):
            if letter == four[j]:
                score1 += 4
        for j in range(len(five)):
            if letter == five[j]:
                score1 += 5
        for j in range(len(eight)):
            if letter == eight[j]:
                score1 += 8
        for j in range(len(ten)):
            if letter == ten[j]:
                score1 += 10
    return score1


def valid(word, draw_one):
    # Tells me if a word is composed only of the letters in the draw or not.
    word_letters = split(word)
    draw = split(draw_one)
    counter = len(word_letters)
    for i in range(len(word_letters)):
        letter = word_letters[i]
        for j in range(len(draw)):
            if letter == draw[j]:
                counter -= 1
                draw.remove(letter)
                break
    if counter > 0:
        return False
    return True


def user_valid(word, n, df, draw):
    if valid(word, draw):
        for i in range(n):
            if word == str(df.iloc[i, 0]):
                return True
    return False


def main():
    df = pd.read_table('dictionary.txt')
    n = df.size  # 235885
    for i in range(n):
        df.set_value(i, 'A', str(df.iloc[i, 0]).upper())

    letters = ['A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'B', 'B', 'C', 'C', 'D', 'D', 'D', 'D', 'E', 'E', 'E', 'E',
               'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E', 'F', 'F', 'G', 'G', 'G', 'H', 'H', 'I', 'I', 'I', 'I', 'I', 'I',
               'I', 'I', 'I', 'J', 'K', 'L', 'L', 'L', 'L', 'M', 'M', 'N', 'N', 'N', 'N', 'N', 'N', 'O', 'O', 'O', 'O',
               'O', 'O', 'O', 'O', 'P', 'P', 'Q', 'R', 'R', 'R', 'R', 'R', 'R', 'S', 'S', 'S', 'S', 'T', 'T', 'T', 'T',
               'T', 'T', 'U', 'U', 'U', 'U', 'V', 'V', 'W', 'W', 'X', 'Y', 'Y', 'Z']

    main_user_score = 0
    comp_score = 0
    while True:
        draw = []
        for i in range(7):
            draw.append(letters[random.randint(0, 97)])
        print(draw)
        user_word = 'abc'
        print('Enter all words in uppercase.')
        while not (user_valid(user_word, n, df, draw)):
            user_word = input('Enter a Scrabble word made with these letters: ')
        user_score = score(user_word)
        print('Your Score is: ' + str(user_score))

        # figure out the best word
        eligible_words = []
        draw_one = ""
        for x in draw:
            draw_one += x
        for i in range(n):
            if valid(str(df.iloc[i, 0]), draw_one):
                eligible_words.append(df.iloc[i, 0])
        # print(eligible_words)

        eligible_scores = []
        for i in range(len(eligible_words)):
            eligible_scores.append(score(str(eligible_words[i])))
        # print(eligible_scores)

        max_score = score(eligible_words[eligible_scores.index(max(eligible_scores))])
        print('Highest score possible: ' + str(max_score))
        print('These words give the highest score: ')
        for i in range(len(eligible_words)):
            if score(eligible_words[i]) == max_score:
                print(eligible_words[i])

        main_user_score += user_score
        comp_score += max_score
        print()
        print('Your total score: ' + str(main_user_score))
        print('Computer\'s total score: ' + str(comp_score))
        print()


if __name__ == '__main__':
    main()
