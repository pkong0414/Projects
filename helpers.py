def alphabet_position(char):
    lower_letter = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
                    'u', 'v', 'w', 'x', 'y', 'z']
    upper_letter = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
                    'U', 'V', 'W', 'X', 'Y', 'Z']
    count = 0
    if char.isupper() is True:
        for index in range(len(upper_letter)):
            if char == upper_letter[index]:
                return index
    elif char.islower() is True:
        for index in range(len(lower_letter)):
            if char == lower_letter[index]:
                return index


def rotate_character(char, rot):
    lower_letter = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
                    'u', 'v', 'w', 'x', 'y', 'z']
    upper_letter = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
                    'U', 'V', 'W', 'X', 'Y', 'Z']
    letter_idx = alphabet_position(char)
    if char.isupper() is True:
        if (letter_idx + rot) >= 26:
            # print(letter_idx, '+', rot, '%', 26, '=', (letter_idx + rot) % 26)
            letter_idx = (letter_idx + rot) % 26
            return upper_letter[letter_idx]
        # we need to loop around if the letter hits the end.

        letter_idx += rot
        return upper_letter[letter_idx]
    if char.islower() is True:
        if (letter_idx + rot) >= 26:
            # print(letter_idx, '+', rot, '%', 26, '=',(letter_idx + rot) % 26)
            letter_idx = (letter_idx + rot) % 26
            return lower_letter[letter_idx]

        letter_idx += rot
        return lower_letter[letter_idx]
        # we need to loop around if the letter hits the end.
    return char