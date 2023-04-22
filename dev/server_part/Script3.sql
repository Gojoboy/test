

use uchatdb.db;



CREATE TABLE "ChatType" (
	ct_id INTEGER not null primary key autoincrement,
	ct_name TEXT(50) not null,
	ct_type INTEGER not null
);
/*CREATE TABLE "ChatSetting" (
	cs_id INTEGER auto_increment primary key,
	cs_name TEXT(50) not null,
	cs_type INTEGER not null
);*/
CREATE TABLE "JoinType" (
	jt_id INTEGER not null primary key autoincrement,
	jt_name TEXT(50) not null,
	jt_type INTEGER not null
);
CREATE TABLE "Chat" (
	c_id INTEGER not null primary key autoincrement,
	c_name TEXT(50) not null,
	c_code TEXT(50),
	c_profile_image BLOB,
	c_description TEXT(512),
	
	jt_id INTEGER not null,
	--cs_id INTEGER not null,
	ct_id INTEGER not null,
	
	constraint "C_CT_FK" foreign key (ct_id) references "ChatType"(ct_id) on delete cascade on update cascade,
	constraint "C_JT_FK" foreign key (jt_id) references "JoinType"(jt_id) on delete cascade on update cascade
);



CREATE TABLE "ChatUser" (
	cu_id INTEGER not null primary key autoincrement,
	u_id INTEGER not null, --foreign key 
	c_id INTEGER not null, --foreign key 
	cus_id INTEGER, --foreign key
	
	cu_join INTEGER(3),
	cu_join_date INTEGER,
	cu_write INTEGER(3),
	cu_write_date INTEGER,
	
	cu_notifications INTEGER(3),
	
	constraint "CU_U_FK" foreign key (u_id) references "User"(u_id) on delete cascade on update cascade,
	constraint "CU_C_FK" foreign key (c_id) references "Chat"(c_id) on delete cascade on update cascade,
	constraint "CU_CUS_FK" foreign key (cus_id) references "ChatUserSetting"(cus_id) on delete set null on update cascade
);
CREATE TABLE "ChatUserSetting" (
	cus_id INTEGER not null primary key autoincrement,
	cus_name TEXT(50) not null,
	cus_type INTEGER not null
);



CREATE TABLE "UserContact" (
	uc_id INTEGER not null primary key autoincrement,
	u_1_id INTEGER not null,
	u_2_id INTEGER not null,
	constraint "UC_U1_FK" foreign key (u_1_id) references "User"(u_id) on delete cascade on update cascade,
	constraint "UC_U2_FK" foreign key (u_2_id) references "User"(u_id) on delete cascade on update cascade
);
CREATE TABLE "User" (
	u_id INTEGER not null primary key autoincrement,
	u_login TEXT(50) not null,
	u_password TEXT(25) not null,
	u_name TEXT(50) not null,
	u_code TEXT(50),
	u_profile_image BLOB,
	u_bio TEXT(512),
	u_online_date INTEGER
);
/*CREATE TABLE "UserSetting" (
	us_id INTEGER auto_increment primary key,
	us_name TEXT(50) not null,
	us_type INTEGER not null
);*/



CREATE TABLE "Message" (
	m_id INTEGER not null primary key autoincrement,
	u_id INTEGER,
	c_id INTEGER not null,
	m_m_id INTEGER,
	
	m_text TEXT(1024) not null,
	m_is_edited INTEGER not null,
	m_date INTEGER not null,
	
	m_type INTEGER(3),
	m_form INTEGER(3),
	
	constraint "M_U_FK" foreign key (u_id) references "User"(u_id) on delete set null on update cascade,
	constraint "M_C_FK" foreign key (c_id) references "Chat"(c_id) on delete cascade on update cascade
);
CREATE TABLE "MessageFile" (
	mf_id INTEGER not null primary key autoincrement,
	m_id INTEGER not null,
	
	mf_file BLOB not null,
	
	mf_name TEXT(100),		
	mf_size INTEGER,		

	constraint "MF_M_FK" foreign key (m_id) references "Message"(m_id) on delete cascade on update cascade
);



INSERT into "ChatType"(ct_id, ct_name, ct_type) values(1, "Chat", 1);
INSERT into "ChatType"(ct_id, ct_name, ct_type) values(2, "Group", 2);
--INSERT into ChatType(ct_name, ct_type) values("Chat", 1);

INSERT into "JoinType"(jt_id, jt_name, jt_type) values(1, "Public", 1);
INSERT into "JoinType"(jt_id, jt_name, jt_type) values(2, "Code", 2);
--INSERT into JoinType(jt_name, jt_type) values("", 3);

INSERT into "ChatUserSetting"(cus_id, cus_name, cus_type) values(1, "User", 1);
INSERT into "ChatUserSetting"(cus_id, cus_name, cus_type) values(2, "Moderator", 2);
INSERT into "ChatUserSetting"(cus_id, cus_name, cus_type) values(3, "Owner", 3);

--INSERT into JoinType(jt_name, jt_type) values("", );















