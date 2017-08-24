from helpers import alphabet_position, rotate_character

def encrypt(text, rot):
    cipher_len = len(rot)
    cipher_count = 0
    encrypted_message = ''

    for x in range(len(text)):
        if cipher_count != cipher_len and text[x] != ' ':
            encrypted_message += rotate_character(text[x], alphabet_position(rot[cipher_count]))
            cipher_count +=1
            if cipher_count == cipher_len:
                cipher_count = 0
        elif text[x] == ' ':
            encrypted_message += text[x]
    print(encrypted_message)
    return encrypted_message

#testing output
encrypt('a', 'a')
encrypt('The crow flies at midnight!', 'boom')
