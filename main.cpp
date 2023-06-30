#include <filesystem>
#include "User.h"
#include "Message.h"
namespace fs = std::filesystem;
bool is_empty(std::fstream pFile)
{
	return pFile.peek() == std::fstream::traits_type::eof();
}

int main() 
{
	setlocale(LC_ALL, "rus");
	Users_data users;
	Message_data messages;

	fstream user_file = fstream("users.txt", ios::in | ios::out);
	if (!user_file)
		// Для создания файла используем параметр ios::trunc
		user_file = fstream("users.txt", ios::in | ios::out | ios::trunc);
	fs::permissions("users.txt",
		fs::perms::group_write | fs::perms::group_read| fs::perms::others_all,
		fs::perm_options::remove);

	if (user_file) 
	{
		User temp("123", "12", "1");
		int i = 0;
		user_file.seekg(0, ios::end);
		if (user_file.tellg() == 0)
		{
		}
		else
		{
			user_file.seekg(0, ios::beg);
			while (!user_file.eof())
			{
				user_file >> temp;
				users.add_User(temp);
				cout << i++ << " user is " << temp << endl;
			}
		}
		string tmp1, tmp2, tmp3;
		//cout << endl;
		cout << "Create name" << endl;
		cin >> tmp1;
		cout << "Create login" << endl;
		cin >> tmp2;
		cout << "Create pass" << endl;
		cin >> tmp3;
		User new_User(tmp1, tmp2, tmp3);
		users.add_User(new_User);

		ofstream a_file("users.txt", ios::app);
		a_file << endl;
		a_file << new_User;
		for (int j = 0; j < users.count_User(); j++)
		{
			cout << "User " << j << " data:" << endl << endl;
			cout << users[j].get_name() << endl << endl;
			cout << users[j].get_login() << endl << endl;
			cout << users[j].get_password() << endl << endl;
		}
	}
	else
	{
		cout << "Could not open file users.txt !" << '\n';
		return 0;

	}

	fstream message_file = fstream("messages.txt", ios::in | ios::out);
	if (!message_file)
		// Для создания файла используем параметр ios::trunc
		message_file = fstream("messages.txt", ios::in | ios::out | ios::trunc);
	fs::permissions("messages.txt",
		fs::perms::group_write | fs::perms::group_read | fs::perms::others_all,
		fs::perm_options::remove);

	if (message_file)
	{
		Message temp("Hello", "name1", "name2");
		int i = 0;
		message_file.seekg(0, ios::end);
		if (user_file.tellg() == 0)
		{
		}
		else
		{
			message_file.seekg(0, ios::beg);
			while (!message_file.eof())
			{
				message_file >> temp;
				messages.add_Message(temp);
				cout << i++ << " Message is " << temp << endl;
			}
		}
		string tmp1, tmp2, tmp3;
		cout << endl;
		cout << "Write text of mess" << endl;
		cin >> tmp1;
		cout << "sender" << endl;
		cin >> tmp2;
		cout << "receiver" << endl;
		cin >> tmp3;
		Message new_Message(tmp1, tmp2, tmp3);
		messages.add_Message(new_Message);

		ofstream b_file("messages.txt", ios::app);
		b_file << endl;
		b_file << new_Message;
		for (int j = 0; j < messages.count_Message(); j++)
		{
			cout << "Message " << j << " data:" << endl << endl;
			cout << messages[j].get_text() << endl << endl;
			cout << messages[j].get_sender() << endl << endl;
			cout << messages[j].get_receiver() << endl << endl;
		}
	}
	else
	{
		cout << "Could not open file messages.txt !" << '\n';
		return 0;

	}
}