#include <bits/stdc++.h>
using namespace std;

string generateKey(string text, string key)
{
	int n = key.size();

	for(int i=n;i<text.size();i++)
	{
		key.push_back(key[i%n]);
	}
	return key;
}

void encrypt()
{
	string key,text;
	cout<<"Enter Key: ";
	cin>>key;

	cout<<"Enter the Plaintext(without spaces): \n";
	cin>>text;

	key = generateKey(text,key);
	//cout<<key<<endl;

	transform(text.begin(),text.end(),text.begin(),::toupper);
	transform(key.begin(),key.end(),key.begin(),::toupper);

	string cipher;

	for(int i=0;i<text.size();i++)
	{
		cipher += (text[i]+key[i])%26 + 65;
	}

	cout<<"The encrypted cipher text is: ";
	cout<<cipher<<endl;
}

void decrypt()
{
	string key,cipher;
	cout<<"Enter Key: ";
	cin>>key;

	cout<<"Enter the cipher text(without spaces): \n";
	cin>>cipher;
key=generateKey(cipher,key);
string text;
for(int i=0;i<cipher.size();i++)
    text+=(cipher[i]-key[i]+26)%26+65;
cout<<text;
}
int main()
{
	while(1)
	{
		cout<<endl<<"\tVIGNERE CIPHER"<<endl;
		cout<<"Choose Option\n1-Encrypt\n2-Decrypt\n3-Exit\n";
		int c;
		cin>>c;

		switch(c)
		{
			case 1: encrypt();
					break;
			case 2: decrypt();
					break;
			case 3: return 0;

			default: cout<<"Choose correct option"<<endl;
		}
	}
	return 0;
}
