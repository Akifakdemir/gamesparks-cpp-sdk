
# ChangeLog

## beta 2

- Added support for Marmalade
- Changed SSL-Method to TLS1
- Fixed all memory leaks
- Interface Changes:
	- The global GameSparks::Core::GS instance has been removed. If you find it convinient to have a global GS instance, you're still free to create one yourself.
	- GameSparks::Core::GS::GameSparksAvailable(bool available) => GameSparks::Core::GS::GameSparksAvailable(GameSparks::Core::GS/ gsInstance, bool available)
		The callback gets the current GS-instance passed as the first argument
	- GameSparks::Api::Requests::*Request: constructor now expects a GS-instance as the first argument
	- The callbacks passed to request.Send() now expect a GS-instance as their first argument
	- The method to register message handlers has changed: you used to write:
		GameSparks::Api::Messages::*Message::SetListener(MyListener); now you write:
		GS.SetMessageListerner<TheMessageType>(MyMessageListener). You can register one MessageListener for each message-type. Also MyMessageListener gets the
		GS-instance passed as the first argument.

		An example:
```cpp
			using namespace GameSparks::Api::Messages;


			/* OLD */
			void OnAchievementEarnedMessage(const AchievementEarnedMessage& message)
			{
				// do stuff with message
			}

			…

			AchievementEarnedMessage::SetListener(OnAchievementEarnedMessage);


			/* NEW */
			void OnAchievementEarnedMessage(GameSparks::Core::GS_& gsInstance, const AchievementEarnedMessage& message)
			{
				// do stuff with message	    
			}

			…

			// Message-type deduction works for c-style callbacks
			GS.SetMessageListener(OnAchievementEarnedMessage);


			/* If you want to better document the the message type the handler is registered for or you're using c++11, you can also write: */
			GS.SetMessageListener<AchievementEarnedMessage>(OnAchievementEarnedMessage)

			/* C++11 lambdas also work, if your compiler and standard library supports it: */
			GS.SetMessageListener<AchievementEarnedMessage>([](GameSparks::Core::GS_& gsInstance, const AchievementEarnedMessage& message){
				// do stuff with message
			});
```
These changes where necessary for the leak-free shutdown of the SDK. 



## Initial

- Initial C++ SDK with support for plain C++, Unreal and Cocos2d-x
