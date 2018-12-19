#include <fstream>
#include <iostream>
#include <cstdio>
#include "user.h"
#include "common.h"

int main()
{

	//创建容器,存储数据
	std::map<std::string, user> user_database;
	std::map<std::string, ques_info> ques_database;
	ReadInfoFroDatabase(user_database, ques_database);

	//操作码缓存，behavior
	int beh = 0;

	//程序主循环
	while (true)
	{
		system("cls");
		std::cout << "欢迎来到bbs,请选择操作（1-登录，2-注册,其他数字-退出）：";
		std::cin >> beh;


		if (beh == 1)
		{
			std::string userid;
			std::string userpassword;
			std::cout << "请输入id及密码（用空格隔开）：";
			std::cin >> userid >> userpassword;

			auto iter = user_database.find(userid);
			if (iter == user_database.end())
			{
				std::cout << "用户名或密码错误";
				system("pause");
			}
			else
			{
				if (!(iter->second.LogIn(userpassword)) )
				{
					std::cout << "用户名或密码错误";
					system("pause");
				}
				else
				{
					//正式登录成功，第二层循环
					while (true)
					{
						//当前用户 cur_user
						user &cur_user = iter->second;//引用当前用户
						int beh2;
						system("cls");
						std::cout << "您有以下操作可供选择：" << std::endl;
						std::cout << "1-查看问题，2-提问,3-查看关注用户列表，4-搜索，其他数字-注销：" << std::endl;
						std::cin >> beh2;
						if (beh2 == 2)
						{
							std::string title;
							std::string content;
							std::cout << "请输入问题标题：";
							std::cin >> title;
							std::cout << "请输入问题内容：";
							std::cin >> content;
							cur_user.AskQues(title, content, ques_database);
							std::cout << "提问成功";
							system("pause");
						}
						else {


							if ( beh2 != 1)
							{
								if (beh2 == 3)
								{
									int ff = 0;
									cur_user.PrintFoUsList();
									std::cout << "您有以下操作可供选择：1-查看某一用户的提问和回答，其他数字-返回上一层：";
									std::cin >> ff;
									if (ff == 1)
									{
										std::string strid;
										std::cout << "请输入您想要查看用户的id：";
										std::cin >> strid;
										std::vector<ques_info> souresult_que;
										std::vector<answ_info> souresult_ans;
										cur_user.SearchUserDetail(strid, souresult_que, souresult_ans, ques_database);
										std::cout << "以下为该用户提出的问题" << std::endl;
										for (auto &val : souresult_que)
										{
											val.PrintProperty();
										}
										std::cout << "以下为该用户有关的回答" << std::endl;
										for (auto &val : souresult_ans)
										{
											val.PrintProperty();
										}

									}//查看关注的用户的提问和回答
									system("pause");
								}//查看关注列表和后续操作
								else
								{

									if ( beh2 == 4)
									{
										int sousuof = 0;
										//搜索操作哈
										std::cout << "请选择搜索的类型，1-按标题搜索， 2-按时间搜索,其他数字-退出搜索：";
										std::cin >> sousuof;
										if (sousuof == 1)
										{
											
											std::string soutitle;
											std::vector<ques_info> souresult;
											std::cout << "请输入标题：";
											std::cin >> soutitle;
											cur_user.Search(soutitle, ques_database, souresult);
											std::cout << "以下为搜索结果：" << std::endl;
											for (auto &val: souresult)
											{
												//val.PrintProperty();
												std::cout << val;
											}
										}
										else
										{
											if (sousuof == 2)
											{
												time_t time1;
												time_t time2;

												struct tm * times = new struct tm;
												struct tm * timee = new struct tm;



												int ye = 0;
												int mo = 0;
												int da = 0;

												//按时间搜索
												std::cout << "请输入起始时间（格式：年（空格）月（空格）日（空格）：";
												std::cin >> ye >> mo >> da;

												times->tm_year = ye - 1900;
												times->tm_mon = mo-1;
												times->tm_mday = da;
												times->tm_hour = 0;
												times->tm_min = 0;
												times->tm_sec = 0;
												time1= mktime(times);

												std::cout << "请输入终止时间（格式：年（空格）月（空格）日（空格）：";
												std::cin >> ye >> mo >> da;


												timee->tm_year = ye - 1900;
												timee->tm_mon = mo - 1;
												timee->tm_mday = da;
												timee->tm_hour = 23;
												timee->tm_min = 59;
												timee->tm_sec = 59;
												time2 = mktime(timee);

												std::vector<ques_info> souresult;
												cur_user.Search(time1, time2, ques_database, souresult);
												for (auto &val : souresult)
												{
													val.PrintProperty();
												}


												delete times;
												delete timee;

											}//按时间搜索
										}
										system("pause");
									}//搜索操作
									else
									{
										break;
									}//注销操作
								}//搜索操作和注销操作
							}//搜索、注销、查看关注列表操作
							else
							{
								//首先打印第一页的问题
								//i1始终代表当前页数最后一个问题的下一个问题的序号
								//iter1跟随i1
								system("cls");
								int i1 = 1;
								auto iter1 = ques_database.begin();
								std::cout << "问题显示格式为：问题id-提问时间-提问者昵称-标题" << std::endl << std::endl;
								for (  i1=1; (i1 <= 20)&&(iter1 != ques_database.end()) ; i1++,iter1++)
								{
									iter1->second.PrintProperty();
								}

								
								while (true)
								{
									int beh3 = 0;
									std::cout << "您有以下操作可供选择——" << std::endl;
									std::cout << std::endl << "1-查看某一问题，2-上一页，3-下一页,其他数字-返回上一层：" << std::endl;
									std::cin >> beh3;
									if (beh3 == 2)
									{
										if (i1 <= 20)
										{
											std::cout << "此为第一页，无法再翻至上一页";
											exit;
										}
										else
										{
											system("cls");
											i1 = i1 - 40;
											if(i1>0)
											{
												for (int interger = 1; interger <= 20; interger++) { iter1--; }
												std::cout << "问题显示格式为：问题id-提问时间-提问者昵称-标题" << std::endl << std::endl;
												for (int interger = 1; interger <= 20 && (iter1 != ques_database.end()); i1++, iter1++, interger++)
												{
													iter1->second.PrintProperty();
												}
											}
											else
											{
												i1 = 1;
												iter1 = ques_database.begin();
												std::cout << "问题显示格式为：问题id-提问时间-提问者昵称-标题" << std::endl;
												for (int interger = 1; interger <= 20 && (iter1 != ques_database.end()); i1++, iter1++, interger++)
												{
													iter1->second.PrintProperty();
												}
											}
											
										}
									}//上一页操作
									else {
										if (beh3 == 3)
										{
											if (iter1 == ques_database.end())
											{
												std::cout << "已经是最后一页";
											}
											else
											{
												system("cls");
												std::cout << "问题显示格式为：问题id-提问时间-提问者昵称-标题" << std::endl << std::endl;
												for (int interger = 1; interger <= 20 && (iter1 != ques_database.end()); i1++, iter1++, interger++)
												{
													iter1->second.PrintProperty();
												}
											}
											
										}//下一页操作
										else {
											if (beh3 != 1)
											{
												break;
											}//退出当前循环操作
											else
											{
												
												std::string qid;
												//查看某一问题------操作：点赞，回答问题，到
												std::cout << "请输入要查看问题的id:";
												std::cin >> qid;
												system("cls");
												auto iter3 = ques_database.find(qid);
												std::cout << "问题信息："<< std::endl;
												std::cout << "问题显示格式为：问题id-提问时间-提问者昵称-标题-换行-内容" << std::endl << std::endl;
												iter3->second.PrintProperty();
												std::cout << iter3->second.GetContent() << std::endl;
												std::cout << std::endl << "答案显示格式为：答案id-回答时间-回答者昵称-被赞次数-内容" << std::endl << std::endl;
												std::cout << "答案信息：" << std::endl;
												iter3->second.PrintAnswers();

												while (true)
												{
													int beh4 = 0;
													std::cout << std::endl << "您现在有以下操作以供选择：" << std::endl;
													std::cout << "1-回答，2-赞同某答案，3-添加某用户到关注列表，其他数字-回到上层：";
													std::cin >> beh4;
													if (beh4 == 1)
													{
														std::string curans;
														std::cout << "请输入您的回答：";
														std::cin >> curans;
														answ_info cans(userid, curans, cur_user.GetUserName(), iter3->second.GetId());
														iter3->second.AddAnswer(cans);
														system("cls");
														std::cout << "问题信息："<< std::endl;
														std::cout << "问题显示格式为：问题id-提问时间-提问者昵称-标题-内容" << std::endl << std::endl;
														iter3->second.PrintProperty();
														std::cout << std::endl << "答案信息：" << std::endl;
														std::cout << "答案显示格式为：答案id-回答时间-回答者昵称-被赞次数-内容" << std::endl << std::endl;
														iter3->second.PrintAnswers();
													}//回答问题操作
													else {
														if (beh4 == 2)
														{
															std::string ansid;
															std::wcout << "请输入要赞同的答案的id：";
															std::cin >> ansid;
															iter3->second.PraiseAnswer(ansid);
															system("cls");
															std::cout << "问题信息：" << std::endl;
															std::cout << "问题显示格式为：问题id-提问时间-提问者昵称-标题-内容" << std::endl << std::endl;
															iter3->second.PrintProperty();
															std::cout << std::endl << "答案显示格式为：答案id-回答时间-回答者昵称-被赞次数-内容" << std::endl << std::endl;
															std::cout << "答案信息：" << std::endl;
															iter3->second.PrintAnswers();
														}//赞同答案操作
														else
														{	
															if (beh4 == 3)
															{
																std::string foid;
																std::cout << "请输入用户id：";
																std::cin >> foid;
																cur_user.AddFoUs(foid);
																break;

															}
															else
															{
																break;

															}
														}//非赞同操作：退出当前循环
													}//非回答操作
												}//对某一具体问题的操作循环
												system("cls");
												i1 = 1;
												iter1 = ques_database.begin();
												std::cout << "问题显示格式为：问题id-提问时间-提问者昵称-标题" << std::endl << std::endl;
												for (int interger = 1; interger <= 20 && (iter1 != ques_database.end()); i1++, iter1++, interger++)
												{
													iter1->second.PrintProperty();
												}
												
													

											}//进入查看某一问题操作
										}//非下一页操作
									}//非上一页操作
								}//对问题列表的操作循环
							}//查看问题及后续操作
						}//非提问操作
					}//当前用户操作根循环
				}//登录相关
			}//登录相关
		}//登录进入bbs并进行后续操作
		else
		{
			if (beh == 2)
			{
				//用户注册操作：需要提供id，name，password
				std::string *pid(new std::string), *pname(new std::string), *ppassword1(new std::string), *ppassword2(new std::string);
				std::cout << "请输入id(不要包含空格）:";
				std::cin >> (*pid);
				auto iter = user_database.find(*pid);
				while (iter != user_database.end())
				{
					std::cout << "用户id已存在，请尝试其他id：";
					std::cin >> (*pid);
					iter = user_database.find(*pid);
				}
				std::cout << "请输入昵称：";
				std::cin >> (*pname);
				
				
				std::cout << "请输入密码：";
				std::cin >> (*ppassword1);
				std::cout << "请再次输入密码以确认：";
				std::cin >> (*ppassword2);
				while ((*ppassword1) != (*ppassword2))
				{
					std::cout << "两次输入密码不一致";
					std::cout << "请输入密码：";
					std::cin >> (*ppassword1);
					std::cout << "请再次输入密码以确认：";
					std::cin >> (*ppassword2);
				}
				user user_((*pid), (*pname), (*ppassword1));
				user_database.insert(std::pair<std::string, user>((*pid), user_));
				std::cout << "注册成功";
				delete pid, pname, ppassword1, ppassword2;

			}//注册操作
			else
			{
				break;
			}//退出bbs操作
		}//退出和注册操作
	}//程序主循环
	
	//数据写入
	WriteInfoToDatabase(user_database, ques_database);
	
	//程序退出
	return 0;
}

