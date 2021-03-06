#include "Mail.h"

Mail::Mail() {
    ptrconfig=new Config();
	ptrinternet=new Internet();
}

Mail::Mail(const Mail& orig) {
}

Mail::~Mail() {
  
}

void Mail::corpmail()
{
    ptrconfig->lirevaleurattributs();
    mailMessage.addRecipient(Poco::Net::MailRecipient(Poco::Net::MailRecipient::PRIMARY_RECIPIENT,ptrconfig->getdestinataire()));
    mailMessage.setSubject(Poco::Net::MailMessage::encodeWord(ptrconfig->getsujet()));
    mailMessage.setSender(ptrconfig->getexpediteur());
    mailMessage.addAttachment(ptrconfig->getnomfichierbdd(), new Poco::Net::FilePartSource(ptrconfig->getlienbdd()));
    
}
int Mail::envoimail()
{
if ((ptrinternet->testinternet())==true) 
     { 
         try  
         { 
             this->corpmail(); 
             Poco::Net::SecureSMTPClientSession session(ptrconfig->getclientmessagerie(), ptrconfig->getport()); 
             session.open(); 
             Poco::Net::initializeSSL(); 
             Poco::SharedPtr<Poco::Net::InvalidCertificateHandler> ptrHandler = new Poco::Net::AcceptCertificateHandler(false); 
             Poco::Net::Context::Ptr ptrContext = new Poco::Net::Context(Poco::Net::Context::CLIENT_USE, "", "", "", Poco::Net::Context::VERIFY_RELAXED, 9, true, "ALL:!ADH:!LOW:!EXP:!MD5:@STRENGTH"); 
             Poco::Net::SSLManager::instance().initializeClient(NULL, ptrHandler, ptrContext); 
             try 
             { 
                 session.login(); 
                 if(session.startTLS(ptrContext)) 
                 { 
                     session.login(Poco::Net::SecureSMTPClientSession::AUTH_LOGIN, ptrconfig->getnomdecompte(), ptrconfig->getmotdepasse()); 
                     session.sendMessage(mailMessage); 
                 } 
                 session.close(); 
                 Poco::Net::uninitializeSSL(); 
				return OK; 
             } 
             catch(Poco::Net::SMTPException it) 
             { 
                 return PBSMTP; 
             } 
         } 
         catch (Poco::FileNotFoundException eb) 
         { 
             return FILENOTFOUND; 
         } 
         catch (Poco::Net::HostNotFoundException at) 
         { 
             return PBMCLIENTMSG; 
         }         
     } 
     else 
     { 
         return PASINTERNET; 
     } 

}
