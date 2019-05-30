//This program is a vigenere cipher. It will encrypt and //decrypt a message using a key word as the source of the //code. 
#include <iostream>

using namespace std;

string vigenere;
string cipher;

void messagedKey()
{
  string message;
  cout << "Enter message: ";
  getline(cin, message);
  cin.ignore();
  // For loop to get the length of the message
  for(int x = 0; x < message.length(); x++)
  {
    // All letters of message being changed to uppercase
    message[x] = toupper(message[x]);
  }
  string word;
  cout << "Enter key word: ";
  getline(cin, word);
  cin.ignore();

  // For loop to get the length of the key word
  for(int x = 0; x < word.length(); x++)
  {
    // All letters of the key word being changed to upppercase
    word[x] = toupper(word[x]);
  }
  // String word and key word
  string keyWord = "";
  for (int x = 0, y = 0; x < message.length(); x++)
  {
    if(message[x] == 32) // Checking for space in key word
    {
      keyWord += 32; // Including space in key word
    } 
      else
      {
        if(y < word.length())
        {
          keyWord += word[y];
          y++;
        } 
          else 
          {
            y = 0;
            keyWord += word[y];
            y++;
          }
      }
  }

  vigenere = message;
  cipher = keyWord;
}

int alphaTable[26][26];
void arrayTable()
{
  for (int x = 0; x < 26; x++)// Rows for alphabet table
  {
    for(int y = 0; y < 26; y++)// Columns for alphabet table
    {
      int table;
        if ((x + 65) + y > 90)//65 is A and 90 is Z
        {
          table = ((x + 65) + y) - 26;
          // Alphabet letter in table alphabet position
          alphaTable[x][y] = table;
        } 
          else 
          {
            table = (x + 65) + y;
            // Alphabet letter in table alphabet position
            alphaTable[x][y] = table; 
          }
    }
  } 
}

void cipherEncrypted(string message, string cipher)
{
  arrayTable();
  string encryptedText = "";
  // For loop to get message length
  for(int v = 0; v < message.length(); v++)
  {
    if(message[v] == 32 && cipher[v] == 32)
    {
      encryptedText += " ";
    } 
        else 
        {
          int x = (int)message[v]-65;
          int y = (int)cipher[v]-65;
          encryptedText += (char)alphaTable[x][y];
        }
  }
  cout << "Encrypted Text: " << encryptedText;
}

int starCount(int key, int msg)
{
  int counter = 0;
  string result = "";

  //Starting from ASCII letter of Key and ending at letter of message
  //to get full 26 letters of alphabet
  for(int x = 0; x < 26; x++)
  {
    if(key + x > 90)
    {
        result += (char)(key + (x - 26));
    } 
      else 
      {
        result += (char)(key + x);
      }
  }
  for(int x = 0; x < result.length(); x++)
  {
    if(result[x] == msg)
    {
      break;
    } 
      else 
      {
        counter++;
      }
  }
  return counter;
}
void cipherDecrypted(string message, string cipher)
{
  string decryptedText = "";
  // For loop to get message length
  for(int x = 0; x < message.length(); x++)
  {
    if(message[x] == 32 && cipher[x] == 32)
    {
      decryptedText += " ";
    } 
      else 
      {
        int temp = starCount((int)cipher[x], (int)message[x]);
        decryptedText += (char)(65 + temp);
      }
  }
  cout << "Decrypted Text: " << decryptedText;
}

int main()
{
  cout << "A program designed as a vigenere cipher using words. Please do not use symbols or special signs.\n\n";
  int choice;
  cout << "Input your choice as a 1 or 2.\n1. Encryption\n2. Decryption\nChoose 1 or 2.\n ";
  cin >> choice;
  cin.ignore();
  if (choice == 1)
  {
    cout << "Encryption is your choice.\n";
    messagedKey(); //Call function messagedKey
    cipherEncrypted(vigenere, cipher); //Call function cipherEncrypted
  } 
    else if (choice == 2) 
    {
      cout << "Decryption is your choice.\n";
      messagedKey(); // Call function messagedKey
      cipherDecrypted(vigenere, cipher); //Call function cipherDecrypted
    } 
      else 
      {
        cout << "Wrong Choice\n";
      }
return 0;
}
