#include <fstream>
#include <iostream>
#include <cstdio>
#include "user.h"
#include "common.h"

int main()
{

	//��������,�洢����
	std::map<std::string, user> user_database;
	std::map<std::string, ques_info> ques_database;
	ReadInfoFroDatabase(user_database, ques_database);

	//�����뻺�棬behavior
	int beh = 0;

	//������ѭ��
	while (true)
	{
		system("cls");
		std::cout << "��ӭ����bbs,��ѡ�������1-��¼��2-ע��,��������-�˳�����";
		std::cin >> beh;


		if (beh == 1)
		{
			std::string userid;
			std::string userpassword;
			std::cout << "������id�����루�ÿո��������";
			std::cin >> userid >> userpassword;

			auto iter = user_database.find(userid);
			if (iter == user_database.end())
			{
				std::cout << "�û������������";
				system("pause");
			}
			else
			{
				if (!(iter->second.LogIn(userpassword)) )
				{
					std::cout << "�û������������";
					system("pause");
				}
				else
				{
					//��ʽ��¼�ɹ����ڶ���ѭ��
					while (true)
					{
						//��ǰ�û� cur_user
						user &cur_user = iter->second;//���õ�ǰ�û�
						int beh2;
						system("cls");
						std::cout << "�������²����ɹ�ѡ��" << std::endl;
						std::cout << "1-�鿴���⣬2-����,3-�鿴��ע�û��б�4-��������������-ע����" << std::endl;
						std::cin >> beh2;
						if (beh2 == 2)
						{
							std::string title;
							std::string content;
							std::cout << "������������⣺";
							std::cin >> title;
							std::cout << "�������������ݣ�";
							std::cin >> content;
							cur_user.AskQues(title, content, ques_database);
							std::cout << "���ʳɹ�";
							system("pause");
						}
						else {


							if ( beh2 != 1)
							{
								if (beh2 == 3)
								{
									int ff = 0;
									cur_user.PrintFoUsList();
									std::cout << "�������²����ɹ�ѡ��1-�鿴ĳһ�û������ʺͻش���������-������һ�㣺";
									std::cin >> ff;
									if (ff == 1)
									{
										std::string strid;
										std::cout << "����������Ҫ�鿴�û���id��";
										std::cin >> strid;
										std::vector<ques_info> souresult_que;
										std::vector<answ_info> souresult_ans;
										cur_user.SearchUserDetail(strid, souresult_que, souresult_ans, ques_database);
										std::cout << "����Ϊ���û����������" << std::endl;
										for (auto &val : souresult_que)
										{
											val.PrintProperty();
										}
										std::cout << "����Ϊ���û��йصĻش�" << std::endl;
										for (auto &val : souresult_ans)
										{
											val.PrintProperty();
										}

									}//�鿴��ע���û������ʺͻش�
									system("pause");
								}//�鿴��ע�б�ͺ�������
								else
								{

									if ( beh2 == 4)
									{
										int sousuof = 0;
										//����������
										std::cout << "��ѡ�����������ͣ�1-������������ 2-��ʱ������,��������-�˳�������";
										std::cin >> sousuof;
										if (sousuof == 1)
										{
											
											std::string soutitle;
											std::vector<ques_info> souresult;
											std::cout << "��������⣺";
											std::cin >> soutitle;
											cur_user.Search(soutitle, ques_database, souresult);
											std::cout << "����Ϊ���������" << std::endl;
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

												//��ʱ������
												std::cout << "��������ʼʱ�䣨��ʽ���꣨�ո��£��ո��գ��ո񣩣�";
												std::cin >> ye >> mo >> da;

												times->tm_year = ye - 1900;
												times->tm_mon = mo-1;
												times->tm_mday = da;
												times->tm_hour = 0;
												times->tm_min = 0;
												times->tm_sec = 0;
												time1= mktime(times);

												std::cout << "��������ֹʱ�䣨��ʽ���꣨�ո��£��ո��գ��ո񣩣�";
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

											}//��ʱ������
										}
										system("pause");
									}//��������
									else
									{
										break;
									}//ע������
								}//����������ע������
							}//������ע�����鿴��ע�б����
							else
							{
								//���ȴ�ӡ��һҳ������
								//i1ʼ�մ���ǰҳ�����һ���������һ����������
								//iter1����i1
								system("cls");
								int i1 = 1;
								auto iter1 = ques_database.begin();
								std::cout << "������ʾ��ʽΪ������id-����ʱ��-�������ǳ�-����" << std::endl << std::endl;
								for (  i1=1; (i1 <= 20)&&(iter1 != ques_database.end()) ; i1++,iter1++)
								{
									iter1->second.PrintProperty();
								}

								
								while (true)
								{
									int beh3 = 0;
									std::cout << "�������²����ɹ�ѡ�񡪡�" << std::endl;
									std::cout << std::endl << "1-�鿴ĳһ���⣬2-��һҳ��3-��һҳ,��������-������һ�㣺" << std::endl;
									std::cin >> beh3;
									if (beh3 == 2)
									{
										if (i1 <= 20)
										{
											std::cout << "��Ϊ��һҳ���޷��ٷ�����һҳ";
											exit;
										}
										else
										{
											system("cls");
											i1 = i1 - 40;
											if(i1>0)
											{
												for (int interger = 1; interger <= 20; interger++) { iter1--; }
												std::cout << "������ʾ��ʽΪ������id-����ʱ��-�������ǳ�-����" << std::endl << std::endl;
												for (int interger = 1; interger <= 20 && (iter1 != ques_database.end()); i1++, iter1++, interger++)
												{
													iter1->second.PrintProperty();
												}
											}
											else
											{
												i1 = 1;
												iter1 = ques_database.begin();
												std::cout << "������ʾ��ʽΪ������id-����ʱ��-�������ǳ�-����" << std::endl;
												for (int interger = 1; interger <= 20 && (iter1 != ques_database.end()); i1++, iter1++, interger++)
												{
													iter1->second.PrintProperty();
												}
											}
											
										}
									}//��һҳ����
									else {
										if (beh3 == 3)
										{
											if (iter1 == ques_database.end())
											{
												std::cout << "�Ѿ������һҳ";
											}
											else
											{
												system("cls");
												std::cout << "������ʾ��ʽΪ������id-����ʱ��-�������ǳ�-����" << std::endl << std::endl;
												for (int interger = 1; interger <= 20 && (iter1 != ques_database.end()); i1++, iter1++, interger++)
												{
													iter1->second.PrintProperty();
												}
											}
											
										}//��һҳ����
										else {
											if (beh3 != 1)
											{
												break;
											}//�˳���ǰѭ������
											else
											{
												
												std::string qid;
												//�鿴ĳһ����------���������ޣ��ش����⣬��
												std::cout << "������Ҫ�鿴�����id:";
												std::cin >> qid;
												system("cls");
												auto iter3 = ques_database.find(qid);
												std::cout << "������Ϣ��"<< std::endl;
												std::cout << "������ʾ��ʽΪ������id-����ʱ��-�������ǳ�-����-����-����" << std::endl << std::endl;
												iter3->second.PrintProperty();
												std::cout << iter3->second.GetContent() << std::endl;
												std::cout << std::endl << "����ʾ��ʽΪ����id-�ش�ʱ��-�ش����ǳ�-���޴���-����" << std::endl << std::endl;
												std::cout << "����Ϣ��" << std::endl;
												iter3->second.PrintAnswers();

												while (true)
												{
													int beh4 = 0;
													std::cout << std::endl << "�����������²����Թ�ѡ��" << std::endl;
													std::cout << "1-�ش�2-��ͬĳ�𰸣�3-���ĳ�û�����ע�б���������-�ص��ϲ㣺";
													std::cin >> beh4;
													if (beh4 == 1)
													{
														std::string curans;
														std::cout << "���������Ļش�";
														std::cin >> curans;
														answ_info cans(userid, curans, cur_user.GetUserName(), iter3->second.GetId());
														iter3->second.AddAnswer(cans);
														system("cls");
														std::cout << "������Ϣ��"<< std::endl;
														std::cout << "������ʾ��ʽΪ������id-����ʱ��-�������ǳ�-����-����" << std::endl << std::endl;
														iter3->second.PrintProperty();
														std::cout << std::endl << "����Ϣ��" << std::endl;
														std::cout << "����ʾ��ʽΪ����id-�ش�ʱ��-�ش����ǳ�-���޴���-����" << std::endl << std::endl;
														iter3->second.PrintAnswers();
													}//�ش��������
													else {
														if (beh4 == 2)
														{
															std::string ansid;
															std::wcout << "������Ҫ��ͬ�Ĵ𰸵�id��";
															std::cin >> ansid;
															iter3->second.PraiseAnswer(ansid);
															system("cls");
															std::cout << "������Ϣ��" << std::endl;
															std::cout << "������ʾ��ʽΪ������id-����ʱ��-�������ǳ�-����-����" << std::endl << std::endl;
															iter3->second.PrintProperty();
															std::cout << std::endl << "����ʾ��ʽΪ����id-�ش�ʱ��-�ش����ǳ�-���޴���-����" << std::endl << std::endl;
															std::cout << "����Ϣ��" << std::endl;
															iter3->second.PrintAnswers();
														}//��ͬ�𰸲���
														else
														{	
															if (beh4 == 3)
															{
																std::string foid;
																std::cout << "�������û�id��";
																std::cin >> foid;
																cur_user.AddFoUs(foid);
																break;

															}
															else
															{
																break;

															}
														}//����ͬ�������˳���ǰѭ��
													}//�ǻش����
												}//��ĳһ��������Ĳ���ѭ��
												system("cls");
												i1 = 1;
												iter1 = ques_database.begin();
												std::cout << "������ʾ��ʽΪ������id-����ʱ��-�������ǳ�-����" << std::endl << std::endl;
												for (int interger = 1; interger <= 20 && (iter1 != ques_database.end()); i1++, iter1++, interger++)
												{
													iter1->second.PrintProperty();
												}
												
													

											}//����鿴ĳһ�������
										}//����һҳ����
									}//����һҳ����
								}//�������б�Ĳ���ѭ��
							}//�鿴���⼰��������
						}//�����ʲ���
					}//��ǰ�û�������ѭ��
				}//��¼���
			}//��¼���
		}//��¼����bbs�����к�������
		else
		{
			if (beh == 2)
			{
				//�û�ע���������Ҫ�ṩid��name��password
				std::string *pid(new std::string), *pname(new std::string), *ppassword1(new std::string), *ppassword2(new std::string);
				std::cout << "������id(��Ҫ�����ո�:";
				std::cin >> (*pid);
				auto iter = user_database.find(*pid);
				while (iter != user_database.end())
				{
					std::cout << "�û�id�Ѵ��ڣ��볢������id��";
					std::cin >> (*pid);
					iter = user_database.find(*pid);
				}
				std::cout << "�������ǳƣ�";
				std::cin >> (*pname);
				
				
				std::cout << "���������룺";
				std::cin >> (*ppassword1);
				std::cout << "���ٴ�����������ȷ�ϣ�";
				std::cin >> (*ppassword2);
				while ((*ppassword1) != (*ppassword2))
				{
					std::cout << "�����������벻һ��";
					std::cout << "���������룺";
					std::cin >> (*ppassword1);
					std::cout << "���ٴ�����������ȷ�ϣ�";
					std::cin >> (*ppassword2);
				}
				user user_((*pid), (*pname), (*ppassword1));
				user_database.insert(std::pair<std::string, user>((*pid), user_));
				std::cout << "ע��ɹ�";
				delete pid, pname, ppassword1, ppassword2;

			}//ע�����
			else
			{
				break;
			}//�˳�bbs����
		}//�˳���ע�����
	}//������ѭ��
	
	//����д��
	WriteInfoToDatabase(user_database, ques_database);
	
	//�����˳�
	return 0;
}

