#pragma once

#include <vector>
#include <string>
#include <map>
#include <boost/serialization/vector.hpp>
#include "quesinfo.h"

class user {

/*构造函数和虚构函数*/
public:
	user() = default;
	user(const std::string &id_, const std::string &name_, const std::string &password_):id(id_), name(name_), password(password_){}
	user(const std::string &id_, const std::string &name_, const std::string &password_, const std::vector<std::string> &focusinfolist_, const std::vector<std::string> &focususerlist_
		, const std::vector<std::string> &asklist_, const std::vector<std::string> &anslist_, const std::vector<std::string> &pralist_) : id(id_), name(name_), password(password_)
		, focusinfolist(focusinfolist_), focususerlist(focususerlist_), asklist(asklist_), anslist(anslist_){}

/*类的外部接口*/
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



/*类的私有成员变量*/
private:
	std::string id,name,password;
	std::vector<std::string> focusinfolist, focususerlist, asklist, anslist, pralist;

/*序列化相关函数*/
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


