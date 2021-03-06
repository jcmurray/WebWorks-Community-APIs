/*
* Copyright (c) 2013 - 2014 BlackBerry Limited
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#ifndef TEMPLATENDK_HPP_
#define TEMPLATENDK_HPP_

#include <string>
#include <pthread.h>
#include <bb/pim/account/AccountService>
#include <bb/pim/message/MessageService>
#include <bb/pim/message/MessageBuilder>

using namespace bb::pim::account;
using namespace bb::pim::message;

class EmailSenderJS;

namespace webworks {

class EmailSenderNDK {
public:
	explicit EmailSenderNDK(EmailSenderJS *parent = NULL);
	virtual ~EmailSenderNDK();

	// The extension methods are defined here
	std::string sendEmail(const std::string& inputString);
	std::string stripHtml(std::string msgBody);
    QString checkPath(std::string checkpath);
    void attachFile(MessageBuilder &builder, QString path);
	std::string getEmailAccounts();

private:
	EmailSenderJS *m_pParent;
	AccountService accountService;
	MessageService messageService;
};

} // namespace webworks

#endif /* TEMPLATENDK_H_ */
