#include "Table.h"

Table::Table()
{
}

vector <vector<int>> Table::GetTable()
{
	return table;
}

void Table::ReadText(const std::string &name)
{
	ifstream file(name);
	string line;
	

	while (getline(file, line))
	{
		vector<int> row;
		for (int i=0; i < line.size(); ++i) 
		{
			if(line[i]=='0' || line[i] == '1')
			{
				row.push_back(line[i] - '0');
			}
		}
		table.push_back(row);
	}
	/*for (int i = 0; i < table.size(); i++) {
		cout << table[i];
	}*/
	file.close();
}
