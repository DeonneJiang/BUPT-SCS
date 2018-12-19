#pragma once

#include <vector>
#include <string>
#include <map>
#include <boost/serialization/vector.hpp>
#include "quesinfo.h"

class user {

/*���캯�����鹹����*/
public:
	user() = default;
	user(const std::string &id_, const std::string &name_, const std::string &password_):id(id_), name(name_), password(password_){}
	user(const std::string &id_, const std::string &name_, const std::string &password_, const std::vector<std::string> &focusinfolist_, const std::vector<std::string> &focususerlist_
		, const std::vector<std::string> &asklist_, const std::vector<std::string> &anslist_, const std::vector<std::string> &pralist_) : id(id_), name(name_), password(password_)
		, focusinfolist(focusinfolist_), focususerlist(focususerlist_), asklist(asklist_), anslist(anslist_){}

/*����ⲿ�ӿ�*/
public:
	bool ViewAllQues() const;
	bool AskQues(const std::string &title, const std::string &content, std::map<std::string, ques_info> &info_database);
	bool Answer(const std::string &content, ques_info ques);
	bool Praise(ques_info &ques, const std::string &asnid);
	bool LogIn(const std::string &pass);
	bool LogOut() const;
	bool AddFoUs(const std::string &fid);
	std::string GetUserName() const;
	void PrintFoUsList();
	void Search(const std::string &questitle, const std::map<std::string, ques_info> &info_database, std::vector<ques_info> &queslist);
	void Search(time_t starttime, time_t endtime, const std::map<std::string, ques_info> &info_database, std::vector<ques_info> &queslist);
	void SearchUserDetail(const std::string &suid, std::vector<ques_info> &queslist, std::vector<answ_info> &answlist, const std::map<std::string, ques_info> &info_database);



/*���˽�г�Ա����*/
private:
	std::string id,name,password;
	std::vector<std::string> focusinfolist, focususerlist, asklist, anslist, pralist;

/*���л���غ���*/
private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version)
	{
		ar & id;
		ar & name;
		ar & password;
		ar & focusinfolist;
		ar & focususerlist;
		ar & asklist;
		ar & anslist;
		ar & pralist;
	}

};


