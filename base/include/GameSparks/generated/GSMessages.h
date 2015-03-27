#pragma once

//THIS FILE IS AUTO GENERATED, DO NOT MODIFY!!
//THIS FILE IS AUTO GENERATED, DO NOT MODIFY!!
//THIS FILE IS AUTO GENERATED, DO NOT MODIFY!!

#include "../GSMessage.h"
#include "../gsstl.h"

namespace GameSparks
{
	namespace Api
	{
		namespace Messages
		{
			class AchievementEarnedMessage : public GSMessage
			{
				public:
					// used by SetListener to register message creation functions
					static const char* GetTypeName()
					{
						return ".AchievementEarnedMessage";
					}

					AchievementEarnedMessage(const GSData& data)
					: GSMessage(data)
					{

					}
				public:
				/// <summary>
				/// The name of achievement.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetAchievementName () const
					{
						return m_Response.GetString("achievementName");
					}
				/// <summary>
				/// The short code of the achievement.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetAchievementShortCode () const
					{
						return m_Response.GetString("achievementShortCode");
					}
				/// <summary>
				/// The amount of type 1 currency earned.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetCurrency1Earned () const
					{
						return m_Response.GetString("currency1Earned");
					}
				/// <summary>
				/// The amount of type 2 currency earned.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetCurrency2Earned () const
					{
						return m_Response.GetString("currency2Earned");
					}
				/// <summary>
				/// The amount of type 2 currency earned.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetCurrency3Earned () const
					{
						return m_Response.GetString("currency3Earned");
					}
				/// <summary>
				/// The amount of type 4 currency earned.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetCurrency4Earned () const
					{
						return m_Response.GetString("currency4Earned");
					}
				/// <summary>
				/// The amount of type 5 currency earned.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetCurrency5Earned () const
					{
						return m_Response.GetString("currency5Earned");
					}
				/// <summary>
				/// The amount of type 6 currency earned.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetCurrency6Earned () const
					{
						return m_Response.GetString("currency6Earned");
					}
				/// <summary>
				/// Flag indicating whether this message could be sent as a push notification or not.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_BoolOptional GetNotification () const
					{
						return m_Response.GetBoolean("notification");
					}
				/// <summary>
				/// A textual title for the message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetSubTitle () const
					{
						return m_Response.GetString("subTitle");
					}
				/// <summary>
				/// A textual summary describing the message's purpose.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetSummary () const
					{
						return m_Response.GetString("summary");
					}
				/// <summary>
				/// A textual title for the message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetTitle () const
					{
						return m_Response.GetString("title");
					}
				/// <summary>
				/// The name of the virtual good that was earned.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetVirtualGoodEarned () const
					{
						return m_Response.GetString("virtualGoodEarned");
					}
			};
			
			class ChallengeAcceptedMessage : public GSMessage
			{
				public:
					// used by SetListener to register message creation functions
					static const char* GetTypeName()
					{
						return ".ChallengeAcceptedMessage";
					}

					ChallengeAcceptedMessage(const GSData& data)
					: GSMessage(data)
					{

					}
				public:
		class _Challenge : public GSTypedResponse
		{
		public:
			_Challenge(const GSData& data) 
				: GSTypedResponse(data)
			{

			}
			
		class _PlayerDetail : public GSTypedResponse
		{
		public:
			_PlayerDetail(const GSData& data) 
				: GSTypedResponse(data)
			{

			}
			
				/// <summary>
				/// A player's external identifiers
				/// </summary>
					// method type 4
					GameSparks::Core::GSData::t_Optional GetExternalIds () const
					{
						return m_Response.GetGSDataObject("externalIds");
					}
				/// <summary>
				/// A player's id
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetId () const
					{
						return m_Response.GetString("id");
					}
				/// <summary>
				/// A player's name
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetName () const
					{
						return m_Response.GetString("name");
					}
		};
		class _PlayerTurnCount : public GSTypedResponse
		{
		public:
			_PlayerTurnCount(const GSData& data) 
				: GSTypedResponse(data)
			{

			}
			
				/// <summary>
				/// The number of turns that the player has taken so far during this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetCount () const
					{
						return m_Response.GetString("count");
					}
				/// <summary>
				/// The unique player id.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetPlayerId () const
					{
						return m_Response.GetString("playerId");
					}
		};
				/// <summary>
				/// A list of PlayerDetail objects that represents the players that have accepted this challenge.
				/// </summary>
					// method type 1
					gsstl::vector<_PlayerDetail> GetAccepted() const
					{
						gsstl::vector<_PlayerDetail> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getAccepted");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerDetail(*it));
						}
						return result; 
					}
				/// <summary>
				/// A unique identifier for this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetChallengeId () const
					{
						return m_Response.GetString("challengeId");
					}
				/// <summary>
				/// The message included in the challenge by the challenging player who created the challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetChallengeMessage () const
					{
						return m_Response.GetString("challengeMessage");
					}
				/// <summary>
				/// The name of the challenge that this message relates to.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetChallengeName () const
					{
						return m_Response.GetString("challengeName");
					}
				/// <summary>
				/// A list of PlayerDetail objects that represents the players that were challenged in this challenge.
				/// </summary>
					// method type 1
					gsstl::vector<_PlayerDetail> GetChallenged() const
					{
						gsstl::vector<_PlayerDetail> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getChallenged");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerDetail(*it));
						}
						return result; 
					}
				/// <summary>
				/// Details of the player who issued this challenge.
				/// </summary>
					// method type 2
					_PlayerDetail GetChallenger() const
					{
						return _PlayerDetail(m_Response.GetGSDataObject("challenger").GetValue());
					}
				/// <summary>
				/// The amount of type 1 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency1Wager () const
					{
						return m_Response.GetLong("currency1Wager");
					}
				/// <summary>
				/// The amount of type 2 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency2Wager () const
					{
						return m_Response.GetLong("currency2Wager");
					}
				/// <summary>
				/// The amount of type 3 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency3Wager () const
					{
						return m_Response.GetLong("currency3Wager");
					}
				/// <summary>
				/// The amount of type 4 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency4Wager () const
					{
						return m_Response.GetLong("currency4Wager");
					}
				/// <summary>
				/// The amount of type 5 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency5Wager () const
					{
						return m_Response.GetLong("currency5Wager");
					}
				/// <summary>
				/// The amount of type 6 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency6Wager () const
					{
						return m_Response.GetLong("currency6Wager");
					}
				/// <summary>
				/// A list of PlayerDetail objects that represents the players that have declined this challenge.
				/// </summary>
					// method type 1
					gsstl::vector<_PlayerDetail> GetDeclined() const
					{
						gsstl::vector<_PlayerDetail> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getDeclined");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerDetail(*it));
						}
						return result; 
					}
				/// <summary>
				/// The date when the challenge ends.
				/// </summary>
					// method type 4
					GameSparks::Core::GSDateTime::t_Optional GetEndDate () const
					{
						return m_Response.GetDate("endDate");
					}
				/// <summary>
				/// The latest date that a player can accept the challenge.
				/// </summary>
					// method type 4
					GameSparks::Core::GSDateTime::t_Optional GetExpiryDate () const
					{
						return m_Response.GetDate("expiryDate");
					}
				/// <summary>
				/// The maximum number of turns that this challenge is configured for.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetMaxTurns () const
					{
						return m_Response.GetLong("maxTurns");
					}
				/// <summary>
				/// In a turn based challenge this fields contains the player's id whose turn it is next.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetNextPlayer () const
					{
						return m_Response.GetString("nextPlayer");
					}
				/// <summary>
				/// The challenge's short code.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetShortCode () const
					{
						return m_Response.GetString("shortCode");
					}
				/// <summary>
				/// The date when the challenge starts.
				/// </summary>
					// method type 4
					GameSparks::Core::GSDateTime::t_Optional GetStartDate () const
					{
						return m_Response.GetDate("startDate");
					}
				/// <summary>
				/// One of these possible state values: ISSUED, EXPIRED, ACCEPTED, DECLINED, COMPLETE, WITHDRAWN, RUNNING, WAITING, RECEIVED
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetState () const
					{
						return m_Response.GetString("state");
					}
				/// <summary>
				/// A collection containing the number of turns taken by each player that has accepted the challenge.
				/// Each turn count is a Long keyed on a String that represents the player's id
				/// </summary>
					// method type 1
					gsstl::vector<_PlayerTurnCount> GetTurnCount() const
					{
						gsstl::vector<_PlayerTurnCount> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getTurnCount");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerTurnCount(*it));
						}
						return result; 
					}
		};
				/// <summary>
				/// An object representing the challenge.
				/// </summary>
					// method type 2
					_Challenge GetChallenge() const
					{
						return _Challenge(m_Response.GetGSDataObject("challenge").GetValue());
					}
				/// <summary>
				/// A player message included in this message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetMessage () const
					{
						return m_Response.GetString("message");
					}
				/// <summary>
				/// Flag indicating whether this message could be sent as a push notification or not.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_BoolOptional GetNotification () const
					{
						return m_Response.GetBoolean("notification");
					}
				/// <summary>
				/// A textual title for the message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetSubTitle () const
					{
						return m_Response.GetString("subTitle");
					}
				/// <summary>
				/// A textual summary describing the message's purpose.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetSummary () const
					{
						return m_Response.GetString("summary");
					}
				/// <summary>
				/// A textual title for the message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetTitle () const
					{
						return m_Response.GetString("title");
					}
				/// <summary>
				/// The name of the player whose actions generated this message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetWho () const
					{
						return m_Response.GetString("who");
					}
			};
			
			class ChallengeChangedMessage : public GSMessage
			{
				public:
					// used by SetListener to register message creation functions
					static const char* GetTypeName()
					{
						return ".ChallengeChangedMessage";
					}

					ChallengeChangedMessage(const GSData& data)
					: GSMessage(data)
					{

					}
				public:
		class _Challenge : public GSTypedResponse
		{
		public:
			_Challenge(const GSData& data) 
				: GSTypedResponse(data)
			{

			}
			
		class _PlayerDetail : public GSTypedResponse
		{
		public:
			_PlayerDetail(const GSData& data) 
				: GSTypedResponse(data)
			{

			}
			
				/// <summary>
				/// A player's external identifiers
				/// </summary>
					// method type 4
					GameSparks::Core::GSData::t_Optional GetExternalIds () const
					{
						return m_Response.GetGSDataObject("externalIds");
					}
				/// <summary>
				/// A player's id
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetId () const
					{
						return m_Response.GetString("id");
					}
				/// <summary>
				/// A player's name
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetName () const
					{
						return m_Response.GetString("name");
					}
		};
		class _PlayerTurnCount : public GSTypedResponse
		{
		public:
			_PlayerTurnCount(const GSData& data) 
				: GSTypedResponse(data)
			{

			}
			
				/// <summary>
				/// The number of turns that the player has taken so far during this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetCount () const
					{
						return m_Response.GetString("count");
					}
				/// <summary>
				/// The unique player id.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetPlayerId () const
					{
						return m_Response.GetString("playerId");
					}
		};
				/// <summary>
				/// A list of PlayerDetail objects that represents the players that have accepted this challenge.
				/// </summary>
					// method type 1
					gsstl::vector<_PlayerDetail> GetAccepted() const
					{
						gsstl::vector<_PlayerDetail> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getAccepted");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerDetail(*it));
						}
						return result; 
					}
				/// <summary>
				/// A unique identifier for this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetChallengeId () const
					{
						return m_Response.GetString("challengeId");
					}
				/// <summary>
				/// The message included in the challenge by the challenging player who created the challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetChallengeMessage () const
					{
						return m_Response.GetString("challengeMessage");
					}
				/// <summary>
				/// The name of the challenge that this message relates to.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetChallengeName () const
					{
						return m_Response.GetString("challengeName");
					}
				/// <summary>
				/// A list of PlayerDetail objects that represents the players that were challenged in this challenge.
				/// </summary>
					// method type 1
					gsstl::vector<_PlayerDetail> GetChallenged() const
					{
						gsstl::vector<_PlayerDetail> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getChallenged");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerDetail(*it));
						}
						return result; 
					}
				/// <summary>
				/// Details of the player who issued this challenge.
				/// </summary>
					// method type 2
					_PlayerDetail GetChallenger() const
					{
						return _PlayerDetail(m_Response.GetGSDataObject("challenger").GetValue());
					}
				/// <summary>
				/// The amount of type 1 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency1Wager () const
					{
						return m_Response.GetLong("currency1Wager");
					}
				/// <summary>
				/// The amount of type 2 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency2Wager () const
					{
						return m_Response.GetLong("currency2Wager");
					}
				/// <summary>
				/// The amount of type 3 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency3Wager () const
					{
						return m_Response.GetLong("currency3Wager");
					}
				/// <summary>
				/// The amount of type 4 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency4Wager () const
					{
						return m_Response.GetLong("currency4Wager");
					}
				/// <summary>
				/// The amount of type 5 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency5Wager () const
					{
						return m_Response.GetLong("currency5Wager");
					}
				/// <summary>
				/// The amount of type 6 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency6Wager () const
					{
						return m_Response.GetLong("currency6Wager");
					}
				/// <summary>
				/// A list of PlayerDetail objects that represents the players that have declined this challenge.
				/// </summary>
					// method type 1
					gsstl::vector<_PlayerDetail> GetDeclined() const
					{
						gsstl::vector<_PlayerDetail> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getDeclined");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerDetail(*it));
						}
						return result; 
					}
				/// <summary>
				/// The date when the challenge ends.
				/// </summary>
					// method type 4
					GameSparks::Core::GSDateTime::t_Optional GetEndDate () const
					{
						return m_Response.GetDate("endDate");
					}
				/// <summary>
				/// The latest date that a player can accept the challenge.
				/// </summary>
					// method type 4
					GameSparks::Core::GSDateTime::t_Optional GetExpiryDate () const
					{
						return m_Response.GetDate("expiryDate");
					}
				/// <summary>
				/// The maximum number of turns that this challenge is configured for.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetMaxTurns () const
					{
						return m_Response.GetLong("maxTurns");
					}
				/// <summary>
				/// In a turn based challenge this fields contains the player's id whose turn it is next.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetNextPlayer () const
					{
						return m_Response.GetString("nextPlayer");
					}
				/// <summary>
				/// The challenge's short code.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetShortCode () const
					{
						return m_Response.GetString("shortCode");
					}
				/// <summary>
				/// The date when the challenge starts.
				/// </summary>
					// method type 4
					GameSparks::Core::GSDateTime::t_Optional GetStartDate () const
					{
						return m_Response.GetDate("startDate");
					}
				/// <summary>
				/// One of these possible state values: ISSUED, EXPIRED, ACCEPTED, DECLINED, COMPLETE, WITHDRAWN, RUNNING, WAITING, RECEIVED
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetState () const
					{
						return m_Response.GetString("state");
					}
				/// <summary>
				/// A collection containing the number of turns taken by each player that has accepted the challenge.
				/// Each turn count is a Long keyed on a String that represents the player's id
				/// </summary>
					// method type 1
					gsstl::vector<_PlayerTurnCount> GetTurnCount() const
					{
						gsstl::vector<_PlayerTurnCount> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getTurnCount");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerTurnCount(*it));
						}
						return result; 
					}
		};
		class _LeaderboardData : public GSTypedResponse
		{
		public:
			_LeaderboardData(const GSData& data) 
				: GSTypedResponse(data)
			{

			}
			
				/// <summary>
				/// The city where the player was located when they logged this leaderboard entry.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetCity () const
					{
						return m_Response.GetString("city");
					}
				/// <summary>
				/// The country code where the player was located when they logged this leaderboard entry.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetCountry () const
					{
						return m_Response.GetString("country");
					}
				/// <summary>
				/// The players rank.
				/// </summary>
					// method type 4
					GameSparks::Core::GSData::t_Optional GetExternalIds () const
					{
						return m_Response.GetGSDataObject("externalIds");
					}
				/// <summary>
				/// The unique leaderboard id.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetId () const
					{
						return m_Response.GetString("id");
					}
				/// <summary>
				/// The players rank.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetRank () const
					{
						return m_Response.GetLong("rank");
					}
				/// <summary>
				/// The unique player id for this leaderboard entry.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetUserId () const
					{
						return m_Response.GetString("userId");
					}
				/// <summary>
				/// The players display name.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetUserName () const
					{
						return m_Response.GetString("userName");
					}
				/// <summary>
				/// The date when this leaderboard entry was created.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetWhen () const
					{
						return m_Response.GetString("when");
					}
		};
				/// <summary>
				/// An object representing the challenge.
				/// </summary>
					// method type 2
					_Challenge GetChallenge() const
					{
						return _Challenge(m_Response.GetGSDataObject("challenge").GetValue());
					}
				/// <summary>
				/// The leaderboard data associated with this challenge.
				/// </summary>
					// method type 2
					_LeaderboardData GetLeaderboardData() const
					{
						return _LeaderboardData(m_Response.GetGSDataObject("leaderboardData").GetValue());
					}
				/// <summary>
				/// Flag indicating whether this message could be sent as a push notification or not.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_BoolOptional GetNotification () const
					{
						return m_Response.GetBoolean("notification");
					}
				/// <summary>
				/// A textual title for the message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetSubTitle () const
					{
						return m_Response.GetString("subTitle");
					}
				/// <summary>
				/// A textual summary describing the message's purpose.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetSummary () const
					{
						return m_Response.GetString("summary");
					}
				/// <summary>
				/// A textual title for the message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetTitle () const
					{
						return m_Response.GetString("title");
					}
				/// <summary>
				/// Indicates which player has changed the challenge
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetWho () const
					{
						return m_Response.GetString("who");
					}
			};
			
			class ChallengeChatMessage : public GSMessage
			{
				public:
					// used by SetListener to register message creation functions
					static const char* GetTypeName()
					{
						return ".ChallengeChatMessage";
					}

					ChallengeChatMessage(const GSData& data)
					: GSMessage(data)
					{

					}
				public:
		class _Challenge : public GSTypedResponse
		{
		public:
			_Challenge(const GSData& data) 
				: GSTypedResponse(data)
			{

			}
			
		class _PlayerDetail : public GSTypedResponse
		{
		public:
			_PlayerDetail(const GSData& data) 
				: GSTypedResponse(data)
			{

			}
			
				/// <summary>
				/// A player's external identifiers
				/// </summary>
					// method type 4
					GameSparks::Core::GSData::t_Optional GetExternalIds () const
					{
						return m_Response.GetGSDataObject("externalIds");
					}
				/// <summary>
				/// A player's id
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetId () const
					{
						return m_Response.GetString("id");
					}
				/// <summary>
				/// A player's name
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetName () const
					{
						return m_Response.GetString("name");
					}
		};
		class _PlayerTurnCount : public GSTypedResponse
		{
		public:
			_PlayerTurnCount(const GSData& data) 
				: GSTypedResponse(data)
			{

			}
			
				/// <summary>
				/// The number of turns that the player has taken so far during this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetCount () const
					{
						return m_Response.GetString("count");
					}
				/// <summary>
				/// The unique player id.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetPlayerId () const
					{
						return m_Response.GetString("playerId");
					}
		};
				/// <summary>
				/// A list of PlayerDetail objects that represents the players that have accepted this challenge.
				/// </summary>
					// method type 1
					gsstl::vector<_PlayerDetail> GetAccepted() const
					{
						gsstl::vector<_PlayerDetail> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getAccepted");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerDetail(*it));
						}
						return result; 
					}
				/// <summary>
				/// A unique identifier for this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetChallengeId () const
					{
						return m_Response.GetString("challengeId");
					}
				/// <summary>
				/// The message included in the challenge by the challenging player who created the challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetChallengeMessage () const
					{
						return m_Response.GetString("challengeMessage");
					}
				/// <summary>
				/// The name of the challenge that this message relates to.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetChallengeName () const
					{
						return m_Response.GetString("challengeName");
					}
				/// <summary>
				/// A list of PlayerDetail objects that represents the players that were challenged in this challenge.
				/// </summary>
					// method type 1
					gsstl::vector<_PlayerDetail> GetChallenged() const
					{
						gsstl::vector<_PlayerDetail> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getChallenged");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerDetail(*it));
						}
						return result; 
					}
				/// <summary>
				/// Details of the player who issued this challenge.
				/// </summary>
					// method type 2
					_PlayerDetail GetChallenger() const
					{
						return _PlayerDetail(m_Response.GetGSDataObject("challenger").GetValue());
					}
				/// <summary>
				/// The amount of type 1 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency1Wager () const
					{
						return m_Response.GetLong("currency1Wager");
					}
				/// <summary>
				/// The amount of type 2 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency2Wager () const
					{
						return m_Response.GetLong("currency2Wager");
					}
				/// <summary>
				/// The amount of type 3 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency3Wager () const
					{
						return m_Response.GetLong("currency3Wager");
					}
				/// <summary>
				/// The amount of type 4 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency4Wager () const
					{
						return m_Response.GetLong("currency4Wager");
					}
				/// <summary>
				/// The amount of type 5 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency5Wager () const
					{
						return m_Response.GetLong("currency5Wager");
					}
				/// <summary>
				/// The amount of type 6 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency6Wager () const
					{
						return m_Response.GetLong("currency6Wager");
					}
				/// <summary>
				/// A list of PlayerDetail objects that represents the players that have declined this challenge.
				/// </summary>
					// method type 1
					gsstl::vector<_PlayerDetail> GetDeclined() const
					{
						gsstl::vector<_PlayerDetail> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getDeclined");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerDetail(*it));
						}
						return result; 
					}
				/// <summary>
				/// The date when the challenge ends.
				/// </summary>
					// method type 4
					GameSparks::Core::GSDateTime::t_Optional GetEndDate () const
					{
						return m_Response.GetDate("endDate");
					}
				/// <summary>
				/// The latest date that a player can accept the challenge.
				/// </summary>
					// method type 4
					GameSparks::Core::GSDateTime::t_Optional GetExpiryDate () const
					{
						return m_Response.GetDate("expiryDate");
					}
				/// <summary>
				/// The maximum number of turns that this challenge is configured for.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetMaxTurns () const
					{
						return m_Response.GetLong("maxTurns");
					}
				/// <summary>
				/// In a turn based challenge this fields contains the player's id whose turn it is next.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetNextPlayer () const
					{
						return m_Response.GetString("nextPlayer");
					}
				/// <summary>
				/// The challenge's short code.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetShortCode () const
					{
						return m_Response.GetString("shortCode");
					}
				/// <summary>
				/// The date when the challenge starts.
				/// </summary>
					// method type 4
					GameSparks::Core::GSDateTime::t_Optional GetStartDate () const
					{
						return m_Response.GetDate("startDate");
					}
				/// <summary>
				/// One of these possible state values: ISSUED, EXPIRED, ACCEPTED, DECLINED, COMPLETE, WITHDRAWN, RUNNING, WAITING, RECEIVED
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetState () const
					{
						return m_Response.GetString("state");
					}
				/// <summary>
				/// A collection containing the number of turns taken by each player that has accepted the challenge.
				/// Each turn count is a Long keyed on a String that represents the player's id
				/// </summary>
					// method type 1
					gsstl::vector<_PlayerTurnCount> GetTurnCount() const
					{
						gsstl::vector<_PlayerTurnCount> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getTurnCount");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerTurnCount(*it));
						}
						return result; 
					}
		};
				/// <summary>
				/// An object representing the challenge.
				/// </summary>
					// method type 2
					_Challenge GetChallenge() const
					{
						return _Challenge(m_Response.GetGSDataObject("challenge").GetValue());
					}
				/// <summary>
				/// A player message included in this message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetMessage () const
					{
						return m_Response.GetString("message");
					}
				/// <summary>
				/// Flag indicating whether this message could be sent as a push notification or not.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_BoolOptional GetNotification () const
					{
						return m_Response.GetBoolean("notification");
					}
				/// <summary>
				/// A textual title for the message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetSubTitle () const
					{
						return m_Response.GetString("subTitle");
					}
				/// <summary>
				/// A textual summary describing the message's purpose.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetSummary () const
					{
						return m_Response.GetString("summary");
					}
				/// <summary>
				/// A textual title for the message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetTitle () const
					{
						return m_Response.GetString("title");
					}
				/// <summary>
				/// The name of the player whose actions generated this message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetWho () const
					{
						return m_Response.GetString("who");
					}
			};
			
			class ChallengeDeclinedMessage : public GSMessage
			{
				public:
					// used by SetListener to register message creation functions
					static const char* GetTypeName()
					{
						return ".ChallengeDeclinedMessage";
					}

					ChallengeDeclinedMessage(const GSData& data)
					: GSMessage(data)
					{

					}
				public:
		class _Challenge : public GSTypedResponse
		{
		public:
			_Challenge(const GSData& data) 
				: GSTypedResponse(data)
			{

			}
			
		class _PlayerDetail : public GSTypedResponse
		{
		public:
			_PlayerDetail(const GSData& data) 
				: GSTypedResponse(data)
			{

			}
			
				/// <summary>
				/// A player's external identifiers
				/// </summary>
					// method type 4
					GameSparks::Core::GSData::t_Optional GetExternalIds () const
					{
						return m_Response.GetGSDataObject("externalIds");
					}
				/// <summary>
				/// A player's id
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetId () const
					{
						return m_Response.GetString("id");
					}
				/// <summary>
				/// A player's name
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetName () const
					{
						return m_Response.GetString("name");
					}
		};
		class _PlayerTurnCount : public GSTypedResponse
		{
		public:
			_PlayerTurnCount(const GSData& data) 
				: GSTypedResponse(data)
			{

			}
			
				/// <summary>
				/// The number of turns that the player has taken so far during this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetCount () const
					{
						return m_Response.GetString("count");
					}
				/// <summary>
				/// The unique player id.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetPlayerId () const
					{
						return m_Response.GetString("playerId");
					}
		};
				/// <summary>
				/// A list of PlayerDetail objects that represents the players that have accepted this challenge.
				/// </summary>
					// method type 1
					gsstl::vector<_PlayerDetail> GetAccepted() const
					{
						gsstl::vector<_PlayerDetail> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getAccepted");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerDetail(*it));
						}
						return result; 
					}
				/// <summary>
				/// A unique identifier for this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetChallengeId () const
					{
						return m_Response.GetString("challengeId");
					}
				/// <summary>
				/// The message included in the challenge by the challenging player who created the challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetChallengeMessage () const
					{
						return m_Response.GetString("challengeMessage");
					}
				/// <summary>
				/// The name of the challenge that this message relates to.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetChallengeName () const
					{
						return m_Response.GetString("challengeName");
					}
				/// <summary>
				/// A list of PlayerDetail objects that represents the players that were challenged in this challenge.
				/// </summary>
					// method type 1
					gsstl::vector<_PlayerDetail> GetChallenged() const
					{
						gsstl::vector<_PlayerDetail> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getChallenged");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerDetail(*it));
						}
						return result; 
					}
				/// <summary>
				/// Details of the player who issued this challenge.
				/// </summary>
					// method type 2
					_PlayerDetail GetChallenger() const
					{
						return _PlayerDetail(m_Response.GetGSDataObject("challenger").GetValue());
					}
				/// <summary>
				/// The amount of type 1 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency1Wager () const
					{
						return m_Response.GetLong("currency1Wager");
					}
				/// <summary>
				/// The amount of type 2 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency2Wager () const
					{
						return m_Response.GetLong("currency2Wager");
					}
				/// <summary>
				/// The amount of type 3 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency3Wager () const
					{
						return m_Response.GetLong("currency3Wager");
					}
				/// <summary>
				/// The amount of type 4 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency4Wager () const
					{
						return m_Response.GetLong("currency4Wager");
					}
				/// <summary>
				/// The amount of type 5 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency5Wager () const
					{
						return m_Response.GetLong("currency5Wager");
					}
				/// <summary>
				/// The amount of type 6 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency6Wager () const
					{
						return m_Response.GetLong("currency6Wager");
					}
				/// <summary>
				/// A list of PlayerDetail objects that represents the players that have declined this challenge.
				/// </summary>
					// method type 1
					gsstl::vector<_PlayerDetail> GetDeclined() const
					{
						gsstl::vector<_PlayerDetail> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getDeclined");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerDetail(*it));
						}
						return result; 
					}
				/// <summary>
				/// The date when the challenge ends.
				/// </summary>
					// method type 4
					GameSparks::Core::GSDateTime::t_Optional GetEndDate () const
					{
						return m_Response.GetDate("endDate");
					}
				/// <summary>
				/// The latest date that a player can accept the challenge.
				/// </summary>
					// method type 4
					GameSparks::Core::GSDateTime::t_Optional GetExpiryDate () const
					{
						return m_Response.GetDate("expiryDate");
					}
				/// <summary>
				/// The maximum number of turns that this challenge is configured for.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetMaxTurns () const
					{
						return m_Response.GetLong("maxTurns");
					}
				/// <summary>
				/// In a turn based challenge this fields contains the player's id whose turn it is next.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetNextPlayer () const
					{
						return m_Response.GetString("nextPlayer");
					}
				/// <summary>
				/// The challenge's short code.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetShortCode () const
					{
						return m_Response.GetString("shortCode");
					}
				/// <summary>
				/// The date when the challenge starts.
				/// </summary>
					// method type 4
					GameSparks::Core::GSDateTime::t_Optional GetStartDate () const
					{
						return m_Response.GetDate("startDate");
					}
				/// <summary>
				/// One of these possible state values: ISSUED, EXPIRED, ACCEPTED, DECLINED, COMPLETE, WITHDRAWN, RUNNING, WAITING, RECEIVED
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetState () const
					{
						return m_Response.GetString("state");
					}
				/// <summary>
				/// A collection containing the number of turns taken by each player that has accepted the challenge.
				/// Each turn count is a Long keyed on a String that represents the player's id
				/// </summary>
					// method type 1
					gsstl::vector<_PlayerTurnCount> GetTurnCount() const
					{
						gsstl::vector<_PlayerTurnCount> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getTurnCount");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerTurnCount(*it));
						}
						return result; 
					}
		};
				/// <summary>
				/// An object representing the challenge.
				/// </summary>
					// method type 2
					_Challenge GetChallenge() const
					{
						return _Challenge(m_Response.GetGSDataObject("challenge").GetValue());
					}
				/// <summary>
				/// A player message included in this message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetMessage () const
					{
						return m_Response.GetString("message");
					}
				/// <summary>
				/// Flag indicating whether this message could be sent as a push notification or not.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_BoolOptional GetNotification () const
					{
						return m_Response.GetBoolean("notification");
					}
				/// <summary>
				/// A textual title for the message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetSubTitle () const
					{
						return m_Response.GetString("subTitle");
					}
				/// <summary>
				/// A textual summary describing the message's purpose.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetSummary () const
					{
						return m_Response.GetString("summary");
					}
				/// <summary>
				/// A textual title for the message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetTitle () const
					{
						return m_Response.GetString("title");
					}
				/// <summary>
				/// The name of the player whose actions generated this message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetWho () const
					{
						return m_Response.GetString("who");
					}
			};
			
			class ChallengeDrawnMessage : public GSMessage
			{
				public:
					// used by SetListener to register message creation functions
					static const char* GetTypeName()
					{
						return ".ChallengeDrawnMessage";
					}

					ChallengeDrawnMessage(const GSData& data)
					: GSMessage(data)
					{

					}
				public:
		class _Challenge : public GSTypedResponse
		{
		public:
			_Challenge(const GSData& data) 
				: GSTypedResponse(data)
			{

			}
			
		class _PlayerDetail : public GSTypedResponse
		{
		public:
			_PlayerDetail(const GSData& data) 
				: GSTypedResponse(data)
			{

			}
			
				/// <summary>
				/// A player's external identifiers
				/// </summary>
					// method type 4
					GameSparks::Core::GSData::t_Optional GetExternalIds () const
					{
						return m_Response.GetGSDataObject("externalIds");
					}
				/// <summary>
				/// A player's id
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetId () const
					{
						return m_Response.GetString("id");
					}
				/// <summary>
				/// A player's name
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetName () const
					{
						return m_Response.GetString("name");
					}
		};
		class _PlayerTurnCount : public GSTypedResponse
		{
		public:
			_PlayerTurnCount(const GSData& data) 
				: GSTypedResponse(data)
			{

			}
			
				/// <summary>
				/// The number of turns that the player has taken so far during this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetCount () const
					{
						return m_Response.GetString("count");
					}
				/// <summary>
				/// The unique player id.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetPlayerId () const
					{
						return m_Response.GetString("playerId");
					}
		};
				/// <summary>
				/// A list of PlayerDetail objects that represents the players that have accepted this challenge.
				/// </summary>
					// method type 1
					gsstl::vector<_PlayerDetail> GetAccepted() const
					{
						gsstl::vector<_PlayerDetail> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getAccepted");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerDetail(*it));
						}
						return result; 
					}
				/// <summary>
				/// A unique identifier for this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetChallengeId () const
					{
						return m_Response.GetString("challengeId");
					}
				/// <summary>
				/// The message included in the challenge by the challenging player who created the challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetChallengeMessage () const
					{
						return m_Response.GetString("challengeMessage");
					}
				/// <summary>
				/// The name of the challenge that this message relates to.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetChallengeName () const
					{
						return m_Response.GetString("challengeName");
					}
				/// <summary>
				/// A list of PlayerDetail objects that represents the players that were challenged in this challenge.
				/// </summary>
					// method type 1
					gsstl::vector<_PlayerDetail> GetChallenged() const
					{
						gsstl::vector<_PlayerDetail> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getChallenged");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerDetail(*it));
						}
						return result; 
					}
				/// <summary>
				/// Details of the player who issued this challenge.
				/// </summary>
					// method type 2
					_PlayerDetail GetChallenger() const
					{
						return _PlayerDetail(m_Response.GetGSDataObject("challenger").GetValue());
					}
				/// <summary>
				/// The amount of type 1 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency1Wager () const
					{
						return m_Response.GetLong("currency1Wager");
					}
				/// <summary>
				/// The amount of type 2 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency2Wager () const
					{
						return m_Response.GetLong("currency2Wager");
					}
				/// <summary>
				/// The amount of type 3 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency3Wager () const
					{
						return m_Response.GetLong("currency3Wager");
					}
				/// <summary>
				/// The amount of type 4 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency4Wager () const
					{
						return m_Response.GetLong("currency4Wager");
					}
				/// <summary>
				/// The amount of type 5 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency5Wager () const
					{
						return m_Response.GetLong("currency5Wager");
					}
				/// <summary>
				/// The amount of type 6 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency6Wager () const
					{
						return m_Response.GetLong("currency6Wager");
					}
				/// <summary>
				/// A list of PlayerDetail objects that represents the players that have declined this challenge.
				/// </summary>
					// method type 1
					gsstl::vector<_PlayerDetail> GetDeclined() const
					{
						gsstl::vector<_PlayerDetail> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getDeclined");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerDetail(*it));
						}
						return result; 
					}
				/// <summary>
				/// The date when the challenge ends.
				/// </summary>
					// method type 4
					GameSparks::Core::GSDateTime::t_Optional GetEndDate () const
					{
						return m_Response.GetDate("endDate");
					}
				/// <summary>
				/// The latest date that a player can accept the challenge.
				/// </summary>
					// method type 4
					GameSparks::Core::GSDateTime::t_Optional GetExpiryDate () const
					{
						return m_Response.GetDate("expiryDate");
					}
				/// <summary>
				/// The maximum number of turns that this challenge is configured for.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetMaxTurns () const
					{
						return m_Response.GetLong("maxTurns");
					}
				/// <summary>
				/// In a turn based challenge this fields contains the player's id whose turn it is next.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetNextPlayer () const
					{
						return m_Response.GetString("nextPlayer");
					}
				/// <summary>
				/// The challenge's short code.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetShortCode () const
					{
						return m_Response.GetString("shortCode");
					}
				/// <summary>
				/// The date when the challenge starts.
				/// </summary>
					// method type 4
					GameSparks::Core::GSDateTime::t_Optional GetStartDate () const
					{
						return m_Response.GetDate("startDate");
					}
				/// <summary>
				/// One of these possible state values: ISSUED, EXPIRED, ACCEPTED, DECLINED, COMPLETE, WITHDRAWN, RUNNING, WAITING, RECEIVED
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetState () const
					{
						return m_Response.GetString("state");
					}
				/// <summary>
				/// A collection containing the number of turns taken by each player that has accepted the challenge.
				/// Each turn count is a Long keyed on a String that represents the player's id
				/// </summary>
					// method type 1
					gsstl::vector<_PlayerTurnCount> GetTurnCount() const
					{
						gsstl::vector<_PlayerTurnCount> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getTurnCount");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerTurnCount(*it));
						}
						return result; 
					}
		};
		class _LeaderboardData : public GSTypedResponse
		{
		public:
			_LeaderboardData(const GSData& data) 
				: GSTypedResponse(data)
			{

			}
			
				/// <summary>
				/// The city where the player was located when they logged this leaderboard entry.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetCity () const
					{
						return m_Response.GetString("city");
					}
				/// <summary>
				/// The country code where the player was located when they logged this leaderboard entry.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetCountry () const
					{
						return m_Response.GetString("country");
					}
				/// <summary>
				/// The players rank.
				/// </summary>
					// method type 4
					GameSparks::Core::GSData::t_Optional GetExternalIds () const
					{
						return m_Response.GetGSDataObject("externalIds");
					}
				/// <summary>
				/// The unique leaderboard id.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetId () const
					{
						return m_Response.GetString("id");
					}
				/// <summary>
				/// The players rank.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetRank () const
					{
						return m_Response.GetLong("rank");
					}
				/// <summary>
				/// The unique player id for this leaderboard entry.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetUserId () const
					{
						return m_Response.GetString("userId");
					}
				/// <summary>
				/// The players display name.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetUserName () const
					{
						return m_Response.GetString("userName");
					}
				/// <summary>
				/// The date when this leaderboard entry was created.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetWhen () const
					{
						return m_Response.GetString("when");
					}
		};
				/// <summary>
				/// An object representing the challenge.
				/// </summary>
					// method type 2
					_Challenge GetChallenge() const
					{
						return _Challenge(m_Response.GetGSDataObject("challenge").GetValue());
					}
				/// <summary>
				/// The leaderboard data associated with this challenge.
				/// </summary>
					// method type 2
					_LeaderboardData GetLeaderboardData() const
					{
						return _LeaderboardData(m_Response.GetGSDataObject("leaderboardData").GetValue());
					}
				/// <summary>
				/// Flag indicating whether this message could be sent as a push notification or not.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_BoolOptional GetNotification () const
					{
						return m_Response.GetBoolean("notification");
					}
				/// <summary>
				/// A textual title for the message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetSubTitle () const
					{
						return m_Response.GetString("subTitle");
					}
				/// <summary>
				/// A textual summary describing the message's purpose.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetSummary () const
					{
						return m_Response.GetString("summary");
					}
				/// <summary>
				/// A textual title for the message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetTitle () const
					{
						return m_Response.GetString("title");
					}
			};
			
			class ChallengeExpiredMessage : public GSMessage
			{
				public:
					// used by SetListener to register message creation functions
					static const char* GetTypeName()
					{
						return ".ChallengeExpiredMessage";
					}

					ChallengeExpiredMessage(const GSData& data)
					: GSMessage(data)
					{

					}
				public:
		class _Challenge : public GSTypedResponse
		{
		public:
			_Challenge(const GSData& data) 
				: GSTypedResponse(data)
			{

			}
			
		class _PlayerDetail : public GSTypedResponse
		{
		public:
			_PlayerDetail(const GSData& data) 
				: GSTypedResponse(data)
			{

			}
			
				/// <summary>
				/// A player's external identifiers
				/// </summary>
					// method type 4
					GameSparks::Core::GSData::t_Optional GetExternalIds () const
					{
						return m_Response.GetGSDataObject("externalIds");
					}
				/// <summary>
				/// A player's id
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetId () const
					{
						return m_Response.GetString("id");
					}
				/// <summary>
				/// A player's name
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetName () const
					{
						return m_Response.GetString("name");
					}
		};
		class _PlayerTurnCount : public GSTypedResponse
		{
		public:
			_PlayerTurnCount(const GSData& data) 
				: GSTypedResponse(data)
			{

			}
			
				/// <summary>
				/// The number of turns that the player has taken so far during this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetCount () const
					{
						return m_Response.GetString("count");
					}
				/// <summary>
				/// The unique player id.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetPlayerId () const
					{
						return m_Response.GetString("playerId");
					}
		};
				/// <summary>
				/// A list of PlayerDetail objects that represents the players that have accepted this challenge.
				/// </summary>
					// method type 1
					gsstl::vector<_PlayerDetail> GetAccepted() const
					{
						gsstl::vector<_PlayerDetail> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getAccepted");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerDetail(*it));
						}
						return result; 
					}
				/// <summary>
				/// A unique identifier for this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetChallengeId () const
					{
						return m_Response.GetString("challengeId");
					}
				/// <summary>
				/// The message included in the challenge by the challenging player who created the challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetChallengeMessage () const
					{
						return m_Response.GetString("challengeMessage");
					}
				/// <summary>
				/// The name of the challenge that this message relates to.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetChallengeName () const
					{
						return m_Response.GetString("challengeName");
					}
				/// <summary>
				/// A list of PlayerDetail objects that represents the players that were challenged in this challenge.
				/// </summary>
					// method type 1
					gsstl::vector<_PlayerDetail> GetChallenged() const
					{
						gsstl::vector<_PlayerDetail> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getChallenged");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerDetail(*it));
						}
						return result; 
					}
				/// <summary>
				/// Details of the player who issued this challenge.
				/// </summary>
					// method type 2
					_PlayerDetail GetChallenger() const
					{
						return _PlayerDetail(m_Response.GetGSDataObject("challenger").GetValue());
					}
				/// <summary>
				/// The amount of type 1 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency1Wager () const
					{
						return m_Response.GetLong("currency1Wager");
					}
				/// <summary>
				/// The amount of type 2 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency2Wager () const
					{
						return m_Response.GetLong("currency2Wager");
					}
				/// <summary>
				/// The amount of type 3 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency3Wager () const
					{
						return m_Response.GetLong("currency3Wager");
					}
				/// <summary>
				/// The amount of type 4 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency4Wager () const
					{
						return m_Response.GetLong("currency4Wager");
					}
				/// <summary>
				/// The amount of type 5 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency5Wager () const
					{
						return m_Response.GetLong("currency5Wager");
					}
				/// <summary>
				/// The amount of type 6 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency6Wager () const
					{
						return m_Response.GetLong("currency6Wager");
					}
				/// <summary>
				/// A list of PlayerDetail objects that represents the players that have declined this challenge.
				/// </summary>
					// method type 1
					gsstl::vector<_PlayerDetail> GetDeclined() const
					{
						gsstl::vector<_PlayerDetail> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getDeclined");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerDetail(*it));
						}
						return result; 
					}
				/// <summary>
				/// The date when the challenge ends.
				/// </summary>
					// method type 4
					GameSparks::Core::GSDateTime::t_Optional GetEndDate () const
					{
						return m_Response.GetDate("endDate");
					}
				/// <summary>
				/// The latest date that a player can accept the challenge.
				/// </summary>
					// method type 4
					GameSparks::Core::GSDateTime::t_Optional GetExpiryDate () const
					{
						return m_Response.GetDate("expiryDate");
					}
				/// <summary>
				/// The maximum number of turns that this challenge is configured for.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetMaxTurns () const
					{
						return m_Response.GetLong("maxTurns");
					}
				/// <summary>
				/// In a turn based challenge this fields contains the player's id whose turn it is next.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetNextPlayer () const
					{
						return m_Response.GetString("nextPlayer");
					}
				/// <summary>
				/// The challenge's short code.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetShortCode () const
					{
						return m_Response.GetString("shortCode");
					}
				/// <summary>
				/// The date when the challenge starts.
				/// </summary>
					// method type 4
					GameSparks::Core::GSDateTime::t_Optional GetStartDate () const
					{
						return m_Response.GetDate("startDate");
					}
				/// <summary>
				/// One of these possible state values: ISSUED, EXPIRED, ACCEPTED, DECLINED, COMPLETE, WITHDRAWN, RUNNING, WAITING, RECEIVED
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetState () const
					{
						return m_Response.GetString("state");
					}
				/// <summary>
				/// A collection containing the number of turns taken by each player that has accepted the challenge.
				/// Each turn count is a Long keyed on a String that represents the player's id
				/// </summary>
					// method type 1
					gsstl::vector<_PlayerTurnCount> GetTurnCount() const
					{
						gsstl::vector<_PlayerTurnCount> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getTurnCount");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerTurnCount(*it));
						}
						return result; 
					}
		};
				/// <summary>
				/// An object representing the challenge.
				/// </summary>
					// method type 2
					_Challenge GetChallenge() const
					{
						return _Challenge(m_Response.GetGSDataObject("challenge").GetValue());
					}
				/// <summary>
				/// Flag indicating whether this message could be sent as a push notification or not.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_BoolOptional GetNotification () const
					{
						return m_Response.GetBoolean("notification");
					}
				/// <summary>
				/// A textual title for the message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetSubTitle () const
					{
						return m_Response.GetString("subTitle");
					}
				/// <summary>
				/// A textual summary describing the message's purpose.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetSummary () const
					{
						return m_Response.GetString("summary");
					}
				/// <summary>
				/// A textual title for the message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetTitle () const
					{
						return m_Response.GetString("title");
					}
			};
			
			class ChallengeIssuedMessage : public GSMessage
			{
				public:
					// used by SetListener to register message creation functions
					static const char* GetTypeName()
					{
						return ".ChallengeIssuedMessage";
					}

					ChallengeIssuedMessage(const GSData& data)
					: GSMessage(data)
					{

					}
				public:
		class _Challenge : public GSTypedResponse
		{
		public:
			_Challenge(const GSData& data) 
				: GSTypedResponse(data)
			{

			}
			
		class _PlayerDetail : public GSTypedResponse
		{
		public:
			_PlayerDetail(const GSData& data) 
				: GSTypedResponse(data)
			{

			}
			
				/// <summary>
				/// A player's external identifiers
				/// </summary>
					// method type 4
					GameSparks::Core::GSData::t_Optional GetExternalIds () const
					{
						return m_Response.GetGSDataObject("externalIds");
					}
				/// <summary>
				/// A player's id
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetId () const
					{
						return m_Response.GetString("id");
					}
				/// <summary>
				/// A player's name
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetName () const
					{
						return m_Response.GetString("name");
					}
		};
		class _PlayerTurnCount : public GSTypedResponse
		{
		public:
			_PlayerTurnCount(const GSData& data) 
				: GSTypedResponse(data)
			{

			}
			
				/// <summary>
				/// The number of turns that the player has taken so far during this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetCount () const
					{
						return m_Response.GetString("count");
					}
				/// <summary>
				/// The unique player id.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetPlayerId () const
					{
						return m_Response.GetString("playerId");
					}
		};
				/// <summary>
				/// A list of PlayerDetail objects that represents the players that have accepted this challenge.
				/// </summary>
					// method type 1
					gsstl::vector<_PlayerDetail> GetAccepted() const
					{
						gsstl::vector<_PlayerDetail> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getAccepted");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerDetail(*it));
						}
						return result; 
					}
				/// <summary>
				/// A unique identifier for this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetChallengeId () const
					{
						return m_Response.GetString("challengeId");
					}
				/// <summary>
				/// The message included in the challenge by the challenging player who created the challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetChallengeMessage () const
					{
						return m_Response.GetString("challengeMessage");
					}
				/// <summary>
				/// The name of the challenge that this message relates to.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetChallengeName () const
					{
						return m_Response.GetString("challengeName");
					}
				/// <summary>
				/// A list of PlayerDetail objects that represents the players that were challenged in this challenge.
				/// </summary>
					// method type 1
					gsstl::vector<_PlayerDetail> GetChallenged() const
					{
						gsstl::vector<_PlayerDetail> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getChallenged");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerDetail(*it));
						}
						return result; 
					}
				/// <summary>
				/// Details of the player who issued this challenge.
				/// </summary>
					// method type 2
					_PlayerDetail GetChallenger() const
					{
						return _PlayerDetail(m_Response.GetGSDataObject("challenger").GetValue());
					}
				/// <summary>
				/// The amount of type 1 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency1Wager () const
					{
						return m_Response.GetLong("currency1Wager");
					}
				/// <summary>
				/// The amount of type 2 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency2Wager () const
					{
						return m_Response.GetLong("currency2Wager");
					}
				/// <summary>
				/// The amount of type 3 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency3Wager () const
					{
						return m_Response.GetLong("currency3Wager");
					}
				/// <summary>
				/// The amount of type 4 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency4Wager () const
					{
						return m_Response.GetLong("currency4Wager");
					}
				/// <summary>
				/// The amount of type 5 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency5Wager () const
					{
						return m_Response.GetLong("currency5Wager");
					}
				/// <summary>
				/// The amount of type 6 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency6Wager () const
					{
						return m_Response.GetLong("currency6Wager");
					}
				/// <summary>
				/// A list of PlayerDetail objects that represents the players that have declined this challenge.
				/// </summary>
					// method type 1
					gsstl::vector<_PlayerDetail> GetDeclined() const
					{
						gsstl::vector<_PlayerDetail> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getDeclined");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerDetail(*it));
						}
						return result; 
					}
				/// <summary>
				/// The date when the challenge ends.
				/// </summary>
					// method type 4
					GameSparks::Core::GSDateTime::t_Optional GetEndDate () const
					{
						return m_Response.GetDate("endDate");
					}
				/// <summary>
				/// The latest date that a player can accept the challenge.
				/// </summary>
					// method type 4
					GameSparks::Core::GSDateTime::t_Optional GetExpiryDate () const
					{
						return m_Response.GetDate("expiryDate");
					}
				/// <summary>
				/// The maximum number of turns that this challenge is configured for.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetMaxTurns () const
					{
						return m_Response.GetLong("maxTurns");
					}
				/// <summary>
				/// In a turn based challenge this fields contains the player's id whose turn it is next.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetNextPlayer () const
					{
						return m_Response.GetString("nextPlayer");
					}
				/// <summary>
				/// The challenge's short code.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetShortCode () const
					{
						return m_Response.GetString("shortCode");
					}
				/// <summary>
				/// The date when the challenge starts.
				/// </summary>
					// method type 4
					GameSparks::Core::GSDateTime::t_Optional GetStartDate () const
					{
						return m_Response.GetDate("startDate");
					}
				/// <summary>
				/// One of these possible state values: ISSUED, EXPIRED, ACCEPTED, DECLINED, COMPLETE, WITHDRAWN, RUNNING, WAITING, RECEIVED
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetState () const
					{
						return m_Response.GetString("state");
					}
				/// <summary>
				/// A collection containing the number of turns taken by each player that has accepted the challenge.
				/// Each turn count is a Long keyed on a String that represents the player's id
				/// </summary>
					// method type 1
					gsstl::vector<_PlayerTurnCount> GetTurnCount() const
					{
						gsstl::vector<_PlayerTurnCount> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getTurnCount");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerTurnCount(*it));
						}
						return result; 
					}
		};
				/// <summary>
				/// An object representing the challenge.
				/// </summary>
					// method type 2
					_Challenge GetChallenge() const
					{
						return _Challenge(m_Response.GetGSDataObject("challenge").GetValue());
					}
				/// <summary>
				/// A player message included in this message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetMessage () const
					{
						return m_Response.GetString("message");
					}
				/// <summary>
				/// Flag indicating whether this message could be sent as a push notification or not.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_BoolOptional GetNotification () const
					{
						return m_Response.GetBoolean("notification");
					}
				/// <summary>
				/// A textual title for the message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetSubTitle () const
					{
						return m_Response.GetString("subTitle");
					}
				/// <summary>
				/// A textual summary describing the message's purpose.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetSummary () const
					{
						return m_Response.GetString("summary");
					}
				/// <summary>
				/// A textual title for the message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetTitle () const
					{
						return m_Response.GetString("title");
					}
				/// <summary>
				/// The name of the player whose actions generated this message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetWho () const
					{
						return m_Response.GetString("who");
					}
			};
			
			class ChallengeJoinedMessage : public GSMessage
			{
				public:
					// used by SetListener to register message creation functions
					static const char* GetTypeName()
					{
						return ".ChallengeJoinedMessage";
					}

					ChallengeJoinedMessage(const GSData& data)
					: GSMessage(data)
					{

					}
				public:
		class _Challenge : public GSTypedResponse
		{
		public:
			_Challenge(const GSData& data) 
				: GSTypedResponse(data)
			{

			}
			
		class _PlayerDetail : public GSTypedResponse
		{
		public:
			_PlayerDetail(const GSData& data) 
				: GSTypedResponse(data)
			{

			}
			
				/// <summary>
				/// A player's external identifiers
				/// </summary>
					// method type 4
					GameSparks::Core::GSData::t_Optional GetExternalIds () const
					{
						return m_Response.GetGSDataObject("externalIds");
					}
				/// <summary>
				/// A player's id
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetId () const
					{
						return m_Response.GetString("id");
					}
				/// <summary>
				/// A player's name
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetName () const
					{
						return m_Response.GetString("name");
					}
		};
		class _PlayerTurnCount : public GSTypedResponse
		{
		public:
			_PlayerTurnCount(const GSData& data) 
				: GSTypedResponse(data)
			{

			}
			
				/// <summary>
				/// The number of turns that the player has taken so far during this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetCount () const
					{
						return m_Response.GetString("count");
					}
				/// <summary>
				/// The unique player id.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetPlayerId () const
					{
						return m_Response.GetString("playerId");
					}
		};
				/// <summary>
				/// A list of PlayerDetail objects that represents the players that have accepted this challenge.
				/// </summary>
					// method type 1
					gsstl::vector<_PlayerDetail> GetAccepted() const
					{
						gsstl::vector<_PlayerDetail> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getAccepted");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerDetail(*it));
						}
						return result; 
					}
				/// <summary>
				/// A unique identifier for this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetChallengeId () const
					{
						return m_Response.GetString("challengeId");
					}
				/// <summary>
				/// The message included in the challenge by the challenging player who created the challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetChallengeMessage () const
					{
						return m_Response.GetString("challengeMessage");
					}
				/// <summary>
				/// The name of the challenge that this message relates to.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetChallengeName () const
					{
						return m_Response.GetString("challengeName");
					}
				/// <summary>
				/// A list of PlayerDetail objects that represents the players that were challenged in this challenge.
				/// </summary>
					// method type 1
					gsstl::vector<_PlayerDetail> GetChallenged() const
					{
						gsstl::vector<_PlayerDetail> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getChallenged");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerDetail(*it));
						}
						return result; 
					}
				/// <summary>
				/// Details of the player who issued this challenge.
				/// </summary>
					// method type 2
					_PlayerDetail GetChallenger() const
					{
						return _PlayerDetail(m_Response.GetGSDataObject("challenger").GetValue());
					}
				/// <summary>
				/// The amount of type 1 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency1Wager () const
					{
						return m_Response.GetLong("currency1Wager");
					}
				/// <summary>
				/// The amount of type 2 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency2Wager () const
					{
						return m_Response.GetLong("currency2Wager");
					}
				/// <summary>
				/// The amount of type 3 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency3Wager () const
					{
						return m_Response.GetLong("currency3Wager");
					}
				/// <summary>
				/// The amount of type 4 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency4Wager () const
					{
						return m_Response.GetLong("currency4Wager");
					}
				/// <summary>
				/// The amount of type 5 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency5Wager () const
					{
						return m_Response.GetLong("currency5Wager");
					}
				/// <summary>
				/// The amount of type 6 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency6Wager () const
					{
						return m_Response.GetLong("currency6Wager");
					}
				/// <summary>
				/// A list of PlayerDetail objects that represents the players that have declined this challenge.
				/// </summary>
					// method type 1
					gsstl::vector<_PlayerDetail> GetDeclined() const
					{
						gsstl::vector<_PlayerDetail> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getDeclined");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerDetail(*it));
						}
						return result; 
					}
				/// <summary>
				/// The date when the challenge ends.
				/// </summary>
					// method type 4
					GameSparks::Core::GSDateTime::t_Optional GetEndDate () const
					{
						return m_Response.GetDate("endDate");
					}
				/// <summary>
				/// The latest date that a player can accept the challenge.
				/// </summary>
					// method type 4
					GameSparks::Core::GSDateTime::t_Optional GetExpiryDate () const
					{
						return m_Response.GetDate("expiryDate");
					}
				/// <summary>
				/// The maximum number of turns that this challenge is configured for.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetMaxTurns () const
					{
						return m_Response.GetLong("maxTurns");
					}
				/// <summary>
				/// In a turn based challenge this fields contains the player's id whose turn it is next.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetNextPlayer () const
					{
						return m_Response.GetString("nextPlayer");
					}
				/// <summary>
				/// The challenge's short code.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetShortCode () const
					{
						return m_Response.GetString("shortCode");
					}
				/// <summary>
				/// The date when the challenge starts.
				/// </summary>
					// method type 4
					GameSparks::Core::GSDateTime::t_Optional GetStartDate () const
					{
						return m_Response.GetDate("startDate");
					}
				/// <summary>
				/// One of these possible state values: ISSUED, EXPIRED, ACCEPTED, DECLINED, COMPLETE, WITHDRAWN, RUNNING, WAITING, RECEIVED
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetState () const
					{
						return m_Response.GetString("state");
					}
				/// <summary>
				/// A collection containing the number of turns taken by each player that has accepted the challenge.
				/// Each turn count is a Long keyed on a String that represents the player's id
				/// </summary>
					// method type 1
					gsstl::vector<_PlayerTurnCount> GetTurnCount() const
					{
						gsstl::vector<_PlayerTurnCount> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getTurnCount");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerTurnCount(*it));
						}
						return result; 
					}
		};
				/// <summary>
				/// An object representing the challenge.
				/// </summary>
					// method type 2
					_Challenge GetChallenge() const
					{
						return _Challenge(m_Response.GetGSDataObject("challenge").GetValue());
					}
				/// <summary>
				/// A player message included in this message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetMessage () const
					{
						return m_Response.GetString("message");
					}
				/// <summary>
				/// Flag indicating whether this message could be sent as a push notification or not.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_BoolOptional GetNotification () const
					{
						return m_Response.GetBoolean("notification");
					}
				/// <summary>
				/// A textual title for the message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetSubTitle () const
					{
						return m_Response.GetString("subTitle");
					}
				/// <summary>
				/// A textual summary describing the message's purpose.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetSummary () const
					{
						return m_Response.GetString("summary");
					}
				/// <summary>
				/// A textual title for the message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetTitle () const
					{
						return m_Response.GetString("title");
					}
				/// <summary>
				/// The name of the player whose actions generated this message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetWho () const
					{
						return m_Response.GetString("who");
					}
			};
			
			class ChallengeLapsedMessage : public GSMessage
			{
				public:
					// used by SetListener to register message creation functions
					static const char* GetTypeName()
					{
						return ".ChallengeLapsedMessage";
					}

					ChallengeLapsedMessage(const GSData& data)
					: GSMessage(data)
					{

					}
				public:
		class _Challenge : public GSTypedResponse
		{
		public:
			_Challenge(const GSData& data) 
				: GSTypedResponse(data)
			{

			}
			
		class _PlayerDetail : public GSTypedResponse
		{
		public:
			_PlayerDetail(const GSData& data) 
				: GSTypedResponse(data)
			{

			}
			
				/// <summary>
				/// A player's external identifiers
				/// </summary>
					// method type 4
					GameSparks::Core::GSData::t_Optional GetExternalIds () const
					{
						return m_Response.GetGSDataObject("externalIds");
					}
				/// <summary>
				/// A player's id
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetId () const
					{
						return m_Response.GetString("id");
					}
				/// <summary>
				/// A player's name
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetName () const
					{
						return m_Response.GetString("name");
					}
		};
		class _PlayerTurnCount : public GSTypedResponse
		{
		public:
			_PlayerTurnCount(const GSData& data) 
				: GSTypedResponse(data)
			{

			}
			
				/// <summary>
				/// The number of turns that the player has taken so far during this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetCount () const
					{
						return m_Response.GetString("count");
					}
				/// <summary>
				/// The unique player id.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetPlayerId () const
					{
						return m_Response.GetString("playerId");
					}
		};
				/// <summary>
				/// A list of PlayerDetail objects that represents the players that have accepted this challenge.
				/// </summary>
					// method type 1
					gsstl::vector<_PlayerDetail> GetAccepted() const
					{
						gsstl::vector<_PlayerDetail> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getAccepted");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerDetail(*it));
						}
						return result; 
					}
				/// <summary>
				/// A unique identifier for this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetChallengeId () const
					{
						return m_Response.GetString("challengeId");
					}
				/// <summary>
				/// The message included in the challenge by the challenging player who created the challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetChallengeMessage () const
					{
						return m_Response.GetString("challengeMessage");
					}
				/// <summary>
				/// The name of the challenge that this message relates to.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetChallengeName () const
					{
						return m_Response.GetString("challengeName");
					}
				/// <summary>
				/// A list of PlayerDetail objects that represents the players that were challenged in this challenge.
				/// </summary>
					// method type 1
					gsstl::vector<_PlayerDetail> GetChallenged() const
					{
						gsstl::vector<_PlayerDetail> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getChallenged");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerDetail(*it));
						}
						return result; 
					}
				/// <summary>
				/// Details of the player who issued this challenge.
				/// </summary>
					// method type 2
					_PlayerDetail GetChallenger() const
					{
						return _PlayerDetail(m_Response.GetGSDataObject("challenger").GetValue());
					}
				/// <summary>
				/// The amount of type 1 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency1Wager () const
					{
						return m_Response.GetLong("currency1Wager");
					}
				/// <summary>
				/// The amount of type 2 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency2Wager () const
					{
						return m_Response.GetLong("currency2Wager");
					}
				/// <summary>
				/// The amount of type 3 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency3Wager () const
					{
						return m_Response.GetLong("currency3Wager");
					}
				/// <summary>
				/// The amount of type 4 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency4Wager () const
					{
						return m_Response.GetLong("currency4Wager");
					}
				/// <summary>
				/// The amount of type 5 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency5Wager () const
					{
						return m_Response.GetLong("currency5Wager");
					}
				/// <summary>
				/// The amount of type 6 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency6Wager () const
					{
						return m_Response.GetLong("currency6Wager");
					}
				/// <summary>
				/// A list of PlayerDetail objects that represents the players that have declined this challenge.
				/// </summary>
					// method type 1
					gsstl::vector<_PlayerDetail> GetDeclined() const
					{
						gsstl::vector<_PlayerDetail> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getDeclined");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerDetail(*it));
						}
						return result; 
					}
				/// <summary>
				/// The date when the challenge ends.
				/// </summary>
					// method type 4
					GameSparks::Core::GSDateTime::t_Optional GetEndDate () const
					{
						return m_Response.GetDate("endDate");
					}
				/// <summary>
				/// The latest date that a player can accept the challenge.
				/// </summary>
					// method type 4
					GameSparks::Core::GSDateTime::t_Optional GetExpiryDate () const
					{
						return m_Response.GetDate("expiryDate");
					}
				/// <summary>
				/// The maximum number of turns that this challenge is configured for.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetMaxTurns () const
					{
						return m_Response.GetLong("maxTurns");
					}
				/// <summary>
				/// In a turn based challenge this fields contains the player's id whose turn it is next.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetNextPlayer () const
					{
						return m_Response.GetString("nextPlayer");
					}
				/// <summary>
				/// The challenge's short code.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetShortCode () const
					{
						return m_Response.GetString("shortCode");
					}
				/// <summary>
				/// The date when the challenge starts.
				/// </summary>
					// method type 4
					GameSparks::Core::GSDateTime::t_Optional GetStartDate () const
					{
						return m_Response.GetDate("startDate");
					}
				/// <summary>
				/// One of these possible state values: ISSUED, EXPIRED, ACCEPTED, DECLINED, COMPLETE, WITHDRAWN, RUNNING, WAITING, RECEIVED
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetState () const
					{
						return m_Response.GetString("state");
					}
				/// <summary>
				/// A collection containing the number of turns taken by each player that has accepted the challenge.
				/// Each turn count is a Long keyed on a String that represents the player's id
				/// </summary>
					// method type 1
					gsstl::vector<_PlayerTurnCount> GetTurnCount() const
					{
						gsstl::vector<_PlayerTurnCount> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getTurnCount");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerTurnCount(*it));
						}
						return result; 
					}
		};
				/// <summary>
				/// An object representing the challenge.
				/// </summary>
					// method type 2
					_Challenge GetChallenge() const
					{
						return _Challenge(m_Response.GetGSDataObject("challenge").GetValue());
					}
				/// <summary>
				/// Flag indicating whether this message could be sent as a push notification or not.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_BoolOptional GetNotification () const
					{
						return m_Response.GetBoolean("notification");
					}
				/// <summary>
				/// A textual title for the message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetSubTitle () const
					{
						return m_Response.GetString("subTitle");
					}
				/// <summary>
				/// A textual summary describing the message's purpose.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetSummary () const
					{
						return m_Response.GetString("summary");
					}
				/// <summary>
				/// A textual title for the message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetTitle () const
					{
						return m_Response.GetString("title");
					}
			};
			
			class ChallengeLostMessage : public GSMessage
			{
				public:
					// used by SetListener to register message creation functions
					static const char* GetTypeName()
					{
						return ".ChallengeLostMessage";
					}

					ChallengeLostMessage(const GSData& data)
					: GSMessage(data)
					{

					}
				public:
		class _Challenge : public GSTypedResponse
		{
		public:
			_Challenge(const GSData& data) 
				: GSTypedResponse(data)
			{

			}
			
		class _PlayerDetail : public GSTypedResponse
		{
		public:
			_PlayerDetail(const GSData& data) 
				: GSTypedResponse(data)
			{

			}
			
				/// <summary>
				/// A player's external identifiers
				/// </summary>
					// method type 4
					GameSparks::Core::GSData::t_Optional GetExternalIds () const
					{
						return m_Response.GetGSDataObject("externalIds");
					}
				/// <summary>
				/// A player's id
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetId () const
					{
						return m_Response.GetString("id");
					}
				/// <summary>
				/// A player's name
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetName () const
					{
						return m_Response.GetString("name");
					}
		};
		class _PlayerTurnCount : public GSTypedResponse
		{
		public:
			_PlayerTurnCount(const GSData& data) 
				: GSTypedResponse(data)
			{

			}
			
				/// <summary>
				/// The number of turns that the player has taken so far during this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetCount () const
					{
						return m_Response.GetString("count");
					}
				/// <summary>
				/// The unique player id.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetPlayerId () const
					{
						return m_Response.GetString("playerId");
					}
		};
				/// <summary>
				/// A list of PlayerDetail objects that represents the players that have accepted this challenge.
				/// </summary>
					// method type 1
					gsstl::vector<_PlayerDetail> GetAccepted() const
					{
						gsstl::vector<_PlayerDetail> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getAccepted");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerDetail(*it));
						}
						return result; 
					}
				/// <summary>
				/// A unique identifier for this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetChallengeId () const
					{
						return m_Response.GetString("challengeId");
					}
				/// <summary>
				/// The message included in the challenge by the challenging player who created the challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetChallengeMessage () const
					{
						return m_Response.GetString("challengeMessage");
					}
				/// <summary>
				/// The name of the challenge that this message relates to.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetChallengeName () const
					{
						return m_Response.GetString("challengeName");
					}
				/// <summary>
				/// A list of PlayerDetail objects that represents the players that were challenged in this challenge.
				/// </summary>
					// method type 1
					gsstl::vector<_PlayerDetail> GetChallenged() const
					{
						gsstl::vector<_PlayerDetail> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getChallenged");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerDetail(*it));
						}
						return result; 
					}
				/// <summary>
				/// Details of the player who issued this challenge.
				/// </summary>
					// method type 2
					_PlayerDetail GetChallenger() const
					{
						return _PlayerDetail(m_Response.GetGSDataObject("challenger").GetValue());
					}
				/// <summary>
				/// The amount of type 1 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency1Wager () const
					{
						return m_Response.GetLong("currency1Wager");
					}
				/// <summary>
				/// The amount of type 2 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency2Wager () const
					{
						return m_Response.GetLong("currency2Wager");
					}
				/// <summary>
				/// The amount of type 3 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency3Wager () const
					{
						return m_Response.GetLong("currency3Wager");
					}
				/// <summary>
				/// The amount of type 4 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency4Wager () const
					{
						return m_Response.GetLong("currency4Wager");
					}
				/// <summary>
				/// The amount of type 5 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency5Wager () const
					{
						return m_Response.GetLong("currency5Wager");
					}
				/// <summary>
				/// The amount of type 6 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency6Wager () const
					{
						return m_Response.GetLong("currency6Wager");
					}
				/// <summary>
				/// A list of PlayerDetail objects that represents the players that have declined this challenge.
				/// </summary>
					// method type 1
					gsstl::vector<_PlayerDetail> GetDeclined() const
					{
						gsstl::vector<_PlayerDetail> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getDeclined");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerDetail(*it));
						}
						return result; 
					}
				/// <summary>
				/// The date when the challenge ends.
				/// </summary>
					// method type 4
					GameSparks::Core::GSDateTime::t_Optional GetEndDate () const
					{
						return m_Response.GetDate("endDate");
					}
				/// <summary>
				/// The latest date that a player can accept the challenge.
				/// </summary>
					// method type 4
					GameSparks::Core::GSDateTime::t_Optional GetExpiryDate () const
					{
						return m_Response.GetDate("expiryDate");
					}
				/// <summary>
				/// The maximum number of turns that this challenge is configured for.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetMaxTurns () const
					{
						return m_Response.GetLong("maxTurns");
					}
				/// <summary>
				/// In a turn based challenge this fields contains the player's id whose turn it is next.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetNextPlayer () const
					{
						return m_Response.GetString("nextPlayer");
					}
				/// <summary>
				/// The challenge's short code.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetShortCode () const
					{
						return m_Response.GetString("shortCode");
					}
				/// <summary>
				/// The date when the challenge starts.
				/// </summary>
					// method type 4
					GameSparks::Core::GSDateTime::t_Optional GetStartDate () const
					{
						return m_Response.GetDate("startDate");
					}
				/// <summary>
				/// One of these possible state values: ISSUED, EXPIRED, ACCEPTED, DECLINED, COMPLETE, WITHDRAWN, RUNNING, WAITING, RECEIVED
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetState () const
					{
						return m_Response.GetString("state");
					}
				/// <summary>
				/// A collection containing the number of turns taken by each player that has accepted the challenge.
				/// Each turn count is a Long keyed on a String that represents the player's id
				/// </summary>
					// method type 1
					gsstl::vector<_PlayerTurnCount> GetTurnCount() const
					{
						gsstl::vector<_PlayerTurnCount> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getTurnCount");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerTurnCount(*it));
						}
						return result; 
					}
		};
		class _LeaderboardData : public GSTypedResponse
		{
		public:
			_LeaderboardData(const GSData& data) 
				: GSTypedResponse(data)
			{

			}
			
				/// <summary>
				/// The city where the player was located when they logged this leaderboard entry.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetCity () const
					{
						return m_Response.GetString("city");
					}
				/// <summary>
				/// The country code where the player was located when they logged this leaderboard entry.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetCountry () const
					{
						return m_Response.GetString("country");
					}
				/// <summary>
				/// The players rank.
				/// </summary>
					// method type 4
					GameSparks::Core::GSData::t_Optional GetExternalIds () const
					{
						return m_Response.GetGSDataObject("externalIds");
					}
				/// <summary>
				/// The unique leaderboard id.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetId () const
					{
						return m_Response.GetString("id");
					}
				/// <summary>
				/// The players rank.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetRank () const
					{
						return m_Response.GetLong("rank");
					}
				/// <summary>
				/// The unique player id for this leaderboard entry.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetUserId () const
					{
						return m_Response.GetString("userId");
					}
				/// <summary>
				/// The players display name.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetUserName () const
					{
						return m_Response.GetString("userName");
					}
				/// <summary>
				/// The date when this leaderboard entry was created.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetWhen () const
					{
						return m_Response.GetString("when");
					}
		};
				/// <summary>
				/// An object representing the challenge.
				/// </summary>
					// method type 2
					_Challenge GetChallenge() const
					{
						return _Challenge(m_Response.GetGSDataObject("challenge").GetValue());
					}
				/// <summary>
				/// The leaderboard data associated with this challenge.
				/// </summary>
					// method type 2
					_LeaderboardData GetLeaderboardData() const
					{
						return _LeaderboardData(m_Response.GetGSDataObject("leaderboardData").GetValue());
					}
				/// <summary>
				/// Flag indicating whether this message could be sent as a push notification or not.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_BoolOptional GetNotification () const
					{
						return m_Response.GetBoolean("notification");
					}
				/// <summary>
				/// A textual title for the message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetSubTitle () const
					{
						return m_Response.GetString("subTitle");
					}
				/// <summary>
				/// A textual summary describing the message's purpose.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetSummary () const
					{
						return m_Response.GetString("summary");
					}
				/// <summary>
				/// A textual title for the message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetTitle () const
					{
						return m_Response.GetString("title");
					}
				/// <summary>
				/// The winning players name
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetWinnerName () const
					{
						return m_Response.GetString("winnerName");
					}
			};
			
			class ChallengeStartedMessage : public GSMessage
			{
				public:
					// used by SetListener to register message creation functions
					static const char* GetTypeName()
					{
						return ".ChallengeStartedMessage";
					}

					ChallengeStartedMessage(const GSData& data)
					: GSMessage(data)
					{

					}
				public:
		class _Challenge : public GSTypedResponse
		{
		public:
			_Challenge(const GSData& data) 
				: GSTypedResponse(data)
			{

			}
			
		class _PlayerDetail : public GSTypedResponse
		{
		public:
			_PlayerDetail(const GSData& data) 
				: GSTypedResponse(data)
			{

			}
			
				/// <summary>
				/// A player's external identifiers
				/// </summary>
					// method type 4
					GameSparks::Core::GSData::t_Optional GetExternalIds () const
					{
						return m_Response.GetGSDataObject("externalIds");
					}
				/// <summary>
				/// A player's id
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetId () const
					{
						return m_Response.GetString("id");
					}
				/// <summary>
				/// A player's name
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetName () const
					{
						return m_Response.GetString("name");
					}
		};
		class _PlayerTurnCount : public GSTypedResponse
		{
		public:
			_PlayerTurnCount(const GSData& data) 
				: GSTypedResponse(data)
			{

			}
			
				/// <summary>
				/// The number of turns that the player has taken so far during this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetCount () const
					{
						return m_Response.GetString("count");
					}
				/// <summary>
				/// The unique player id.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetPlayerId () const
					{
						return m_Response.GetString("playerId");
					}
		};
				/// <summary>
				/// A list of PlayerDetail objects that represents the players that have accepted this challenge.
				/// </summary>
					// method type 1
					gsstl::vector<_PlayerDetail> GetAccepted() const
					{
						gsstl::vector<_PlayerDetail> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getAccepted");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerDetail(*it));
						}
						return result; 
					}
				/// <summary>
				/// A unique identifier for this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetChallengeId () const
					{
						return m_Response.GetString("challengeId");
					}
				/// <summary>
				/// The message included in the challenge by the challenging player who created the challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetChallengeMessage () const
					{
						return m_Response.GetString("challengeMessage");
					}
				/// <summary>
				/// The name of the challenge that this message relates to.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetChallengeName () const
					{
						return m_Response.GetString("challengeName");
					}
				/// <summary>
				/// A list of PlayerDetail objects that represents the players that were challenged in this challenge.
				/// </summary>
					// method type 1
					gsstl::vector<_PlayerDetail> GetChallenged() const
					{
						gsstl::vector<_PlayerDetail> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getChallenged");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerDetail(*it));
						}
						return result; 
					}
				/// <summary>
				/// Details of the player who issued this challenge.
				/// </summary>
					// method type 2
					_PlayerDetail GetChallenger() const
					{
						return _PlayerDetail(m_Response.GetGSDataObject("challenger").GetValue());
					}
				/// <summary>
				/// The amount of type 1 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency1Wager () const
					{
						return m_Response.GetLong("currency1Wager");
					}
				/// <summary>
				/// The amount of type 2 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency2Wager () const
					{
						return m_Response.GetLong("currency2Wager");
					}
				/// <summary>
				/// The amount of type 3 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency3Wager () const
					{
						return m_Response.GetLong("currency3Wager");
					}
				/// <summary>
				/// The amount of type 4 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency4Wager () const
					{
						return m_Response.GetLong("currency4Wager");
					}
				/// <summary>
				/// The amount of type 5 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency5Wager () const
					{
						return m_Response.GetLong("currency5Wager");
					}
				/// <summary>
				/// The amount of type 6 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency6Wager () const
					{
						return m_Response.GetLong("currency6Wager");
					}
				/// <summary>
				/// A list of PlayerDetail objects that represents the players that have declined this challenge.
				/// </summary>
					// method type 1
					gsstl::vector<_PlayerDetail> GetDeclined() const
					{
						gsstl::vector<_PlayerDetail> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getDeclined");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerDetail(*it));
						}
						return result; 
					}
				/// <summary>
				/// The date when the challenge ends.
				/// </summary>
					// method type 4
					GameSparks::Core::GSDateTime::t_Optional GetEndDate () const
					{
						return m_Response.GetDate("endDate");
					}
				/// <summary>
				/// The latest date that a player can accept the challenge.
				/// </summary>
					// method type 4
					GameSparks::Core::GSDateTime::t_Optional GetExpiryDate () const
					{
						return m_Response.GetDate("expiryDate");
					}
				/// <summary>
				/// The maximum number of turns that this challenge is configured for.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetMaxTurns () const
					{
						return m_Response.GetLong("maxTurns");
					}
				/// <summary>
				/// In a turn based challenge this fields contains the player's id whose turn it is next.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetNextPlayer () const
					{
						return m_Response.GetString("nextPlayer");
					}
				/// <summary>
				/// The challenge's short code.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetShortCode () const
					{
						return m_Response.GetString("shortCode");
					}
				/// <summary>
				/// The date when the challenge starts.
				/// </summary>
					// method type 4
					GameSparks::Core::GSDateTime::t_Optional GetStartDate () const
					{
						return m_Response.GetDate("startDate");
					}
				/// <summary>
				/// One of these possible state values: ISSUED, EXPIRED, ACCEPTED, DECLINED, COMPLETE, WITHDRAWN, RUNNING, WAITING, RECEIVED
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetState () const
					{
						return m_Response.GetString("state");
					}
				/// <summary>
				/// A collection containing the number of turns taken by each player that has accepted the challenge.
				/// Each turn count is a Long keyed on a String that represents the player's id
				/// </summary>
					// method type 1
					gsstl::vector<_PlayerTurnCount> GetTurnCount() const
					{
						gsstl::vector<_PlayerTurnCount> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getTurnCount");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerTurnCount(*it));
						}
						return result; 
					}
		};
				/// <summary>
				/// An object representing the challenge.
				/// </summary>
					// method type 2
					_Challenge GetChallenge() const
					{
						return _Challenge(m_Response.GetGSDataObject("challenge").GetValue());
					}
				/// <summary>
				/// Flag indicating whether this message could be sent as a push notification or not.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_BoolOptional GetNotification () const
					{
						return m_Response.GetBoolean("notification");
					}
				/// <summary>
				/// A textual title for the message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetSubTitle () const
					{
						return m_Response.GetString("subTitle");
					}
				/// <summary>
				/// A textual summary describing the message's purpose.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetSummary () const
					{
						return m_Response.GetString("summary");
					}
				/// <summary>
				/// A textual title for the message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetTitle () const
					{
						return m_Response.GetString("title");
					}
			};
			
			class ChallengeTurnTakenMessage : public GSMessage
			{
				public:
					// used by SetListener to register message creation functions
					static const char* GetTypeName()
					{
						return ".ChallengeTurnTakenMessage";
					}

					ChallengeTurnTakenMessage(const GSData& data)
					: GSMessage(data)
					{

					}
				public:
		class _Challenge : public GSTypedResponse
		{
		public:
			_Challenge(const GSData& data) 
				: GSTypedResponse(data)
			{

			}
			
		class _PlayerDetail : public GSTypedResponse
		{
		public:
			_PlayerDetail(const GSData& data) 
				: GSTypedResponse(data)
			{

			}
			
				/// <summary>
				/// A player's external identifiers
				/// </summary>
					// method type 4
					GameSparks::Core::GSData::t_Optional GetExternalIds () const
					{
						return m_Response.GetGSDataObject("externalIds");
					}
				/// <summary>
				/// A player's id
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetId () const
					{
						return m_Response.GetString("id");
					}
				/// <summary>
				/// A player's name
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetName () const
					{
						return m_Response.GetString("name");
					}
		};
		class _PlayerTurnCount : public GSTypedResponse
		{
		public:
			_PlayerTurnCount(const GSData& data) 
				: GSTypedResponse(data)
			{

			}
			
				/// <summary>
				/// The number of turns that the player has taken so far during this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetCount () const
					{
						return m_Response.GetString("count");
					}
				/// <summary>
				/// The unique player id.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetPlayerId () const
					{
						return m_Response.GetString("playerId");
					}
		};
				/// <summary>
				/// A list of PlayerDetail objects that represents the players that have accepted this challenge.
				/// </summary>
					// method type 1
					gsstl::vector<_PlayerDetail> GetAccepted() const
					{
						gsstl::vector<_PlayerDetail> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getAccepted");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerDetail(*it));
						}
						return result; 
					}
				/// <summary>
				/// A unique identifier for this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetChallengeId () const
					{
						return m_Response.GetString("challengeId");
					}
				/// <summary>
				/// The message included in the challenge by the challenging player who created the challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetChallengeMessage () const
					{
						return m_Response.GetString("challengeMessage");
					}
				/// <summary>
				/// The name of the challenge that this message relates to.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetChallengeName () const
					{
						return m_Response.GetString("challengeName");
					}
				/// <summary>
				/// A list of PlayerDetail objects that represents the players that were challenged in this challenge.
				/// </summary>
					// method type 1
					gsstl::vector<_PlayerDetail> GetChallenged() const
					{
						gsstl::vector<_PlayerDetail> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getChallenged");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerDetail(*it));
						}
						return result; 
					}
				/// <summary>
				/// Details of the player who issued this challenge.
				/// </summary>
					// method type 2
					_PlayerDetail GetChallenger() const
					{
						return _PlayerDetail(m_Response.GetGSDataObject("challenger").GetValue());
					}
				/// <summary>
				/// The amount of type 1 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency1Wager () const
					{
						return m_Response.GetLong("currency1Wager");
					}
				/// <summary>
				/// The amount of type 2 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency2Wager () const
					{
						return m_Response.GetLong("currency2Wager");
					}
				/// <summary>
				/// The amount of type 3 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency3Wager () const
					{
						return m_Response.GetLong("currency3Wager");
					}
				/// <summary>
				/// The amount of type 4 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency4Wager () const
					{
						return m_Response.GetLong("currency4Wager");
					}
				/// <summary>
				/// The amount of type 5 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency5Wager () const
					{
						return m_Response.GetLong("currency5Wager");
					}
				/// <summary>
				/// The amount of type 6 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency6Wager () const
					{
						return m_Response.GetLong("currency6Wager");
					}
				/// <summary>
				/// A list of PlayerDetail objects that represents the players that have declined this challenge.
				/// </summary>
					// method type 1
					gsstl::vector<_PlayerDetail> GetDeclined() const
					{
						gsstl::vector<_PlayerDetail> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getDeclined");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerDetail(*it));
						}
						return result; 
					}
				/// <summary>
				/// The date when the challenge ends.
				/// </summary>
					// method type 4
					GameSparks::Core::GSDateTime::t_Optional GetEndDate () const
					{
						return m_Response.GetDate("endDate");
					}
				/// <summary>
				/// The latest date that a player can accept the challenge.
				/// </summary>
					// method type 4
					GameSparks::Core::GSDateTime::t_Optional GetExpiryDate () const
					{
						return m_Response.GetDate("expiryDate");
					}
				/// <summary>
				/// The maximum number of turns that this challenge is configured for.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetMaxTurns () const
					{
						return m_Response.GetLong("maxTurns");
					}
				/// <summary>
				/// In a turn based challenge this fields contains the player's id whose turn it is next.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetNextPlayer () const
					{
						return m_Response.GetString("nextPlayer");
					}
				/// <summary>
				/// The challenge's short code.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetShortCode () const
					{
						return m_Response.GetString("shortCode");
					}
				/// <summary>
				/// The date when the challenge starts.
				/// </summary>
					// method type 4
					GameSparks::Core::GSDateTime::t_Optional GetStartDate () const
					{
						return m_Response.GetDate("startDate");
					}
				/// <summary>
				/// One of these possible state values: ISSUED, EXPIRED, ACCEPTED, DECLINED, COMPLETE, WITHDRAWN, RUNNING, WAITING, RECEIVED
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetState () const
					{
						return m_Response.GetString("state");
					}
				/// <summary>
				/// A collection containing the number of turns taken by each player that has accepted the challenge.
				/// Each turn count is a Long keyed on a String that represents the player's id
				/// </summary>
					// method type 1
					gsstl::vector<_PlayerTurnCount> GetTurnCount() const
					{
						gsstl::vector<_PlayerTurnCount> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getTurnCount");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerTurnCount(*it));
						}
						return result; 
					}
		};
				/// <summary>
				/// An object representing the challenge.
				/// </summary>
					// method type 2
					_Challenge GetChallenge() const
					{
						return _Challenge(m_Response.GetGSDataObject("challenge").GetValue());
					}
				/// <summary>
				/// Flag indicating whether this message could be sent as a push notification or not.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_BoolOptional GetNotification () const
					{
						return m_Response.GetBoolean("notification");
					}
				/// <summary>
				/// A textual title for the message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetSubTitle () const
					{
						return m_Response.GetString("subTitle");
					}
				/// <summary>
				/// A textual summary describing the message's purpose.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetSummary () const
					{
						return m_Response.GetString("summary");
					}
				/// <summary>
				/// A textual title for the message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetTitle () const
					{
						return m_Response.GetString("title");
					}
				/// <summary>
				/// The name of the player whoe has taken their turn.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetWho () const
					{
						return m_Response.GetString("who");
					}
			};
			
			class ChallengeWaitingMessage : public GSMessage
			{
				public:
					// used by SetListener to register message creation functions
					static const char* GetTypeName()
					{
						return ".ChallengeWaitingMessage";
					}

					ChallengeWaitingMessage(const GSData& data)
					: GSMessage(data)
					{

					}
				public:
		class _Challenge : public GSTypedResponse
		{
		public:
			_Challenge(const GSData& data) 
				: GSTypedResponse(data)
			{

			}
			
		class _PlayerDetail : public GSTypedResponse
		{
		public:
			_PlayerDetail(const GSData& data) 
				: GSTypedResponse(data)
			{

			}
			
				/// <summary>
				/// A player's external identifiers
				/// </summary>
					// method type 4
					GameSparks::Core::GSData::t_Optional GetExternalIds () const
					{
						return m_Response.GetGSDataObject("externalIds");
					}
				/// <summary>
				/// A player's id
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetId () const
					{
						return m_Response.GetString("id");
					}
				/// <summary>
				/// A player's name
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetName () const
					{
						return m_Response.GetString("name");
					}
		};
		class _PlayerTurnCount : public GSTypedResponse
		{
		public:
			_PlayerTurnCount(const GSData& data) 
				: GSTypedResponse(data)
			{

			}
			
				/// <summary>
				/// The number of turns that the player has taken so far during this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetCount () const
					{
						return m_Response.GetString("count");
					}
				/// <summary>
				/// The unique player id.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetPlayerId () const
					{
						return m_Response.GetString("playerId");
					}
		};
				/// <summary>
				/// A list of PlayerDetail objects that represents the players that have accepted this challenge.
				/// </summary>
					// method type 1
					gsstl::vector<_PlayerDetail> GetAccepted() const
					{
						gsstl::vector<_PlayerDetail> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getAccepted");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerDetail(*it));
						}
						return result; 
					}
				/// <summary>
				/// A unique identifier for this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetChallengeId () const
					{
						return m_Response.GetString("challengeId");
					}
				/// <summary>
				/// The message included in the challenge by the challenging player who created the challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetChallengeMessage () const
					{
						return m_Response.GetString("challengeMessage");
					}
				/// <summary>
				/// The name of the challenge that this message relates to.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetChallengeName () const
					{
						return m_Response.GetString("challengeName");
					}
				/// <summary>
				/// A list of PlayerDetail objects that represents the players that were challenged in this challenge.
				/// </summary>
					// method type 1
					gsstl::vector<_PlayerDetail> GetChallenged() const
					{
						gsstl::vector<_PlayerDetail> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getChallenged");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerDetail(*it));
						}
						return result; 
					}
				/// <summary>
				/// Details of the player who issued this challenge.
				/// </summary>
					// method type 2
					_PlayerDetail GetChallenger() const
					{
						return _PlayerDetail(m_Response.GetGSDataObject("challenger").GetValue());
					}
				/// <summary>
				/// The amount of type 1 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency1Wager () const
					{
						return m_Response.GetLong("currency1Wager");
					}
				/// <summary>
				/// The amount of type 2 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency2Wager () const
					{
						return m_Response.GetLong("currency2Wager");
					}
				/// <summary>
				/// The amount of type 3 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency3Wager () const
					{
						return m_Response.GetLong("currency3Wager");
					}
				/// <summary>
				/// The amount of type 4 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency4Wager () const
					{
						return m_Response.GetLong("currency4Wager");
					}
				/// <summary>
				/// The amount of type 5 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency5Wager () const
					{
						return m_Response.GetLong("currency5Wager");
					}
				/// <summary>
				/// The amount of type 6 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency6Wager () const
					{
						return m_Response.GetLong("currency6Wager");
					}
				/// <summary>
				/// A list of PlayerDetail objects that represents the players that have declined this challenge.
				/// </summary>
					// method type 1
					gsstl::vector<_PlayerDetail> GetDeclined() const
					{
						gsstl::vector<_PlayerDetail> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getDeclined");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerDetail(*it));
						}
						return result; 
					}
				/// <summary>
				/// The date when the challenge ends.
				/// </summary>
					// method type 4
					GameSparks::Core::GSDateTime::t_Optional GetEndDate () const
					{
						return m_Response.GetDate("endDate");
					}
				/// <summary>
				/// The latest date that a player can accept the challenge.
				/// </summary>
					// method type 4
					GameSparks::Core::GSDateTime::t_Optional GetExpiryDate () const
					{
						return m_Response.GetDate("expiryDate");
					}
				/// <summary>
				/// The maximum number of turns that this challenge is configured for.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetMaxTurns () const
					{
						return m_Response.GetLong("maxTurns");
					}
				/// <summary>
				/// In a turn based challenge this fields contains the player's id whose turn it is next.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetNextPlayer () const
					{
						return m_Response.GetString("nextPlayer");
					}
				/// <summary>
				/// The challenge's short code.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetShortCode () const
					{
						return m_Response.GetString("shortCode");
					}
				/// <summary>
				/// The date when the challenge starts.
				/// </summary>
					// method type 4
					GameSparks::Core::GSDateTime::t_Optional GetStartDate () const
					{
						return m_Response.GetDate("startDate");
					}
				/// <summary>
				/// One of these possible state values: ISSUED, EXPIRED, ACCEPTED, DECLINED, COMPLETE, WITHDRAWN, RUNNING, WAITING, RECEIVED
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetState () const
					{
						return m_Response.GetString("state");
					}
				/// <summary>
				/// A collection containing the number of turns taken by each player that has accepted the challenge.
				/// Each turn count is a Long keyed on a String that represents the player's id
				/// </summary>
					// method type 1
					gsstl::vector<_PlayerTurnCount> GetTurnCount() const
					{
						gsstl::vector<_PlayerTurnCount> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getTurnCount");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerTurnCount(*it));
						}
						return result; 
					}
		};
				/// <summary>
				/// An object representing the challenge.
				/// </summary>
					// method type 2
					_Challenge GetChallenge() const
					{
						return _Challenge(m_Response.GetGSDataObject("challenge").GetValue());
					}
				/// <summary>
				/// Flag indicating whether this message could be sent as a push notification or not.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_BoolOptional GetNotification () const
					{
						return m_Response.GetBoolean("notification");
					}
				/// <summary>
				/// A textual title for the message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetSubTitle () const
					{
						return m_Response.GetString("subTitle");
					}
				/// <summary>
				/// A textual summary describing the message's purpose.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetSummary () const
					{
						return m_Response.GetString("summary");
					}
				/// <summary>
				/// A textual title for the message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetTitle () const
					{
						return m_Response.GetString("title");
					}
			};
			
			class ChallengeWithdrawnMessage : public GSMessage
			{
				public:
					// used by SetListener to register message creation functions
					static const char* GetTypeName()
					{
						return ".ChallengeWithdrawnMessage";
					}

					ChallengeWithdrawnMessage(const GSData& data)
					: GSMessage(data)
					{

					}
				public:
		class _Challenge : public GSTypedResponse
		{
		public:
			_Challenge(const GSData& data) 
				: GSTypedResponse(data)
			{

			}
			
		class _PlayerDetail : public GSTypedResponse
		{
		public:
			_PlayerDetail(const GSData& data) 
				: GSTypedResponse(data)
			{

			}
			
				/// <summary>
				/// A player's external identifiers
				/// </summary>
					// method type 4
					GameSparks::Core::GSData::t_Optional GetExternalIds () const
					{
						return m_Response.GetGSDataObject("externalIds");
					}
				/// <summary>
				/// A player's id
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetId () const
					{
						return m_Response.GetString("id");
					}
				/// <summary>
				/// A player's name
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetName () const
					{
						return m_Response.GetString("name");
					}
		};
		class _PlayerTurnCount : public GSTypedResponse
		{
		public:
			_PlayerTurnCount(const GSData& data) 
				: GSTypedResponse(data)
			{

			}
			
				/// <summary>
				/// The number of turns that the player has taken so far during this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetCount () const
					{
						return m_Response.GetString("count");
					}
				/// <summary>
				/// The unique player id.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetPlayerId () const
					{
						return m_Response.GetString("playerId");
					}
		};
				/// <summary>
				/// A list of PlayerDetail objects that represents the players that have accepted this challenge.
				/// </summary>
					// method type 1
					gsstl::vector<_PlayerDetail> GetAccepted() const
					{
						gsstl::vector<_PlayerDetail> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getAccepted");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerDetail(*it));
						}
						return result; 
					}
				/// <summary>
				/// A unique identifier for this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetChallengeId () const
					{
						return m_Response.GetString("challengeId");
					}
				/// <summary>
				/// The message included in the challenge by the challenging player who created the challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetChallengeMessage () const
					{
						return m_Response.GetString("challengeMessage");
					}
				/// <summary>
				/// The name of the challenge that this message relates to.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetChallengeName () const
					{
						return m_Response.GetString("challengeName");
					}
				/// <summary>
				/// A list of PlayerDetail objects that represents the players that were challenged in this challenge.
				/// </summary>
					// method type 1
					gsstl::vector<_PlayerDetail> GetChallenged() const
					{
						gsstl::vector<_PlayerDetail> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getChallenged");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerDetail(*it));
						}
						return result; 
					}
				/// <summary>
				/// Details of the player who issued this challenge.
				/// </summary>
					// method type 2
					_PlayerDetail GetChallenger() const
					{
						return _PlayerDetail(m_Response.GetGSDataObject("challenger").GetValue());
					}
				/// <summary>
				/// The amount of type 1 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency1Wager () const
					{
						return m_Response.GetLong("currency1Wager");
					}
				/// <summary>
				/// The amount of type 2 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency2Wager () const
					{
						return m_Response.GetLong("currency2Wager");
					}
				/// <summary>
				/// The amount of type 3 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency3Wager () const
					{
						return m_Response.GetLong("currency3Wager");
					}
				/// <summary>
				/// The amount of type 4 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency4Wager () const
					{
						return m_Response.GetLong("currency4Wager");
					}
				/// <summary>
				/// The amount of type 5 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency5Wager () const
					{
						return m_Response.GetLong("currency5Wager");
					}
				/// <summary>
				/// The amount of type 6 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency6Wager () const
					{
						return m_Response.GetLong("currency6Wager");
					}
				/// <summary>
				/// A list of PlayerDetail objects that represents the players that have declined this challenge.
				/// </summary>
					// method type 1
					gsstl::vector<_PlayerDetail> GetDeclined() const
					{
						gsstl::vector<_PlayerDetail> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getDeclined");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerDetail(*it));
						}
						return result; 
					}
				/// <summary>
				/// The date when the challenge ends.
				/// </summary>
					// method type 4
					GameSparks::Core::GSDateTime::t_Optional GetEndDate () const
					{
						return m_Response.GetDate("endDate");
					}
				/// <summary>
				/// The latest date that a player can accept the challenge.
				/// </summary>
					// method type 4
					GameSparks::Core::GSDateTime::t_Optional GetExpiryDate () const
					{
						return m_Response.GetDate("expiryDate");
					}
				/// <summary>
				/// The maximum number of turns that this challenge is configured for.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetMaxTurns () const
					{
						return m_Response.GetLong("maxTurns");
					}
				/// <summary>
				/// In a turn based challenge this fields contains the player's id whose turn it is next.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetNextPlayer () const
					{
						return m_Response.GetString("nextPlayer");
					}
				/// <summary>
				/// The challenge's short code.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetShortCode () const
					{
						return m_Response.GetString("shortCode");
					}
				/// <summary>
				/// The date when the challenge starts.
				/// </summary>
					// method type 4
					GameSparks::Core::GSDateTime::t_Optional GetStartDate () const
					{
						return m_Response.GetDate("startDate");
					}
				/// <summary>
				/// One of these possible state values: ISSUED, EXPIRED, ACCEPTED, DECLINED, COMPLETE, WITHDRAWN, RUNNING, WAITING, RECEIVED
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetState () const
					{
						return m_Response.GetString("state");
					}
				/// <summary>
				/// A collection containing the number of turns taken by each player that has accepted the challenge.
				/// Each turn count is a Long keyed on a String that represents the player's id
				/// </summary>
					// method type 1
					gsstl::vector<_PlayerTurnCount> GetTurnCount() const
					{
						gsstl::vector<_PlayerTurnCount> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getTurnCount");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerTurnCount(*it));
						}
						return result; 
					}
		};
				/// <summary>
				/// An object representing the challenge.
				/// </summary>
					// method type 2
					_Challenge GetChallenge() const
					{
						return _Challenge(m_Response.GetGSDataObject("challenge").GetValue());
					}
				/// <summary>
				/// A player message included in this message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetMessage () const
					{
						return m_Response.GetString("message");
					}
				/// <summary>
				/// Flag indicating whether this message could be sent as a push notification or not.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_BoolOptional GetNotification () const
					{
						return m_Response.GetBoolean("notification");
					}
				/// <summary>
				/// A textual title for the message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetSubTitle () const
					{
						return m_Response.GetString("subTitle");
					}
				/// <summary>
				/// A textual summary describing the message's purpose.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetSummary () const
					{
						return m_Response.GetString("summary");
					}
				/// <summary>
				/// A textual title for the message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetTitle () const
					{
						return m_Response.GetString("title");
					}
				/// <summary>
				/// The name of the player whose actions generated this message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetWho () const
					{
						return m_Response.GetString("who");
					}
			};
			
			class ChallengeWonMessage : public GSMessage
			{
				public:
					// used by SetListener to register message creation functions
					static const char* GetTypeName()
					{
						return ".ChallengeWonMessage";
					}

					ChallengeWonMessage(const GSData& data)
					: GSMessage(data)
					{

					}
				public:
		class _Challenge : public GSTypedResponse
		{
		public:
			_Challenge(const GSData& data) 
				: GSTypedResponse(data)
			{

			}
			
		class _PlayerDetail : public GSTypedResponse
		{
		public:
			_PlayerDetail(const GSData& data) 
				: GSTypedResponse(data)
			{

			}
			
				/// <summary>
				/// A player's external identifiers
				/// </summary>
					// method type 4
					GameSparks::Core::GSData::t_Optional GetExternalIds () const
					{
						return m_Response.GetGSDataObject("externalIds");
					}
				/// <summary>
				/// A player's id
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetId () const
					{
						return m_Response.GetString("id");
					}
				/// <summary>
				/// A player's name
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetName () const
					{
						return m_Response.GetString("name");
					}
		};
		class _PlayerTurnCount : public GSTypedResponse
		{
		public:
			_PlayerTurnCount(const GSData& data) 
				: GSTypedResponse(data)
			{

			}
			
				/// <summary>
				/// The number of turns that the player has taken so far during this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetCount () const
					{
						return m_Response.GetString("count");
					}
				/// <summary>
				/// The unique player id.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetPlayerId () const
					{
						return m_Response.GetString("playerId");
					}
		};
				/// <summary>
				/// A list of PlayerDetail objects that represents the players that have accepted this challenge.
				/// </summary>
					// method type 1
					gsstl::vector<_PlayerDetail> GetAccepted() const
					{
						gsstl::vector<_PlayerDetail> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getAccepted");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerDetail(*it));
						}
						return result; 
					}
				/// <summary>
				/// A unique identifier for this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetChallengeId () const
					{
						return m_Response.GetString("challengeId");
					}
				/// <summary>
				/// The message included in the challenge by the challenging player who created the challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetChallengeMessage () const
					{
						return m_Response.GetString("challengeMessage");
					}
				/// <summary>
				/// The name of the challenge that this message relates to.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetChallengeName () const
					{
						return m_Response.GetString("challengeName");
					}
				/// <summary>
				/// A list of PlayerDetail objects that represents the players that were challenged in this challenge.
				/// </summary>
					// method type 1
					gsstl::vector<_PlayerDetail> GetChallenged() const
					{
						gsstl::vector<_PlayerDetail> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getChallenged");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerDetail(*it));
						}
						return result; 
					}
				/// <summary>
				/// Details of the player who issued this challenge.
				/// </summary>
					// method type 2
					_PlayerDetail GetChallenger() const
					{
						return _PlayerDetail(m_Response.GetGSDataObject("challenger").GetValue());
					}
				/// <summary>
				/// The amount of type 1 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency1Wager () const
					{
						return m_Response.GetLong("currency1Wager");
					}
				/// <summary>
				/// The amount of type 2 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency2Wager () const
					{
						return m_Response.GetLong("currency2Wager");
					}
				/// <summary>
				/// The amount of type 3 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency3Wager () const
					{
						return m_Response.GetLong("currency3Wager");
					}
				/// <summary>
				/// The amount of type 4 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency4Wager () const
					{
						return m_Response.GetLong("currency4Wager");
					}
				/// <summary>
				/// The amount of type 5 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency5Wager () const
					{
						return m_Response.GetLong("currency5Wager");
					}
				/// <summary>
				/// The amount of type 6 currency that has been wagered on this challenge.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency6Wager () const
					{
						return m_Response.GetLong("currency6Wager");
					}
				/// <summary>
				/// A list of PlayerDetail objects that represents the players that have declined this challenge.
				/// </summary>
					// method type 1
					gsstl::vector<_PlayerDetail> GetDeclined() const
					{
						gsstl::vector<_PlayerDetail> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getDeclined");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerDetail(*it));
						}
						return result; 
					}
				/// <summary>
				/// The date when the challenge ends.
				/// </summary>
					// method type 4
					GameSparks::Core::GSDateTime::t_Optional GetEndDate () const
					{
						return m_Response.GetDate("endDate");
					}
				/// <summary>
				/// The latest date that a player can accept the challenge.
				/// </summary>
					// method type 4
					GameSparks::Core::GSDateTime::t_Optional GetExpiryDate () const
					{
						return m_Response.GetDate("expiryDate");
					}
				/// <summary>
				/// The maximum number of turns that this challenge is configured for.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetMaxTurns () const
					{
						return m_Response.GetLong("maxTurns");
					}
				/// <summary>
				/// In a turn based challenge this fields contains the player's id whose turn it is next.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetNextPlayer () const
					{
						return m_Response.GetString("nextPlayer");
					}
				/// <summary>
				/// The challenge's short code.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetShortCode () const
					{
						return m_Response.GetString("shortCode");
					}
				/// <summary>
				/// The date when the challenge starts.
				/// </summary>
					// method type 4
					GameSparks::Core::GSDateTime::t_Optional GetStartDate () const
					{
						return m_Response.GetDate("startDate");
					}
				/// <summary>
				/// One of these possible state values: ISSUED, EXPIRED, ACCEPTED, DECLINED, COMPLETE, WITHDRAWN, RUNNING, WAITING, RECEIVED
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetState () const
					{
						return m_Response.GetString("state");
					}
				/// <summary>
				/// A collection containing the number of turns taken by each player that has accepted the challenge.
				/// Each turn count is a Long keyed on a String that represents the player's id
				/// </summary>
					// method type 1
					gsstl::vector<_PlayerTurnCount> GetTurnCount() const
					{
						gsstl::vector<_PlayerTurnCount> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getTurnCount");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerTurnCount(*it));
						}
						return result; 
					}
		};
		class _LeaderboardData : public GSTypedResponse
		{
		public:
			_LeaderboardData(const GSData& data) 
				: GSTypedResponse(data)
			{

			}
			
				/// <summary>
				/// The city where the player was located when they logged this leaderboard entry.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetCity () const
					{
						return m_Response.GetString("city");
					}
				/// <summary>
				/// The country code where the player was located when they logged this leaderboard entry.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetCountry () const
					{
						return m_Response.GetString("country");
					}
				/// <summary>
				/// The players rank.
				/// </summary>
					// method type 4
					GameSparks::Core::GSData::t_Optional GetExternalIds () const
					{
						return m_Response.GetGSDataObject("externalIds");
					}
				/// <summary>
				/// The unique leaderboard id.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetId () const
					{
						return m_Response.GetString("id");
					}
				/// <summary>
				/// The players rank.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetRank () const
					{
						return m_Response.GetLong("rank");
					}
				/// <summary>
				/// The unique player id for this leaderboard entry.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetUserId () const
					{
						return m_Response.GetString("userId");
					}
				/// <summary>
				/// The players display name.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetUserName () const
					{
						return m_Response.GetString("userName");
					}
				/// <summary>
				/// The date when this leaderboard entry was created.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetWhen () const
					{
						return m_Response.GetString("when");
					}
		};
				/// <summary>
				/// An object representing the challenge.
				/// </summary>
					// method type 2
					_Challenge GetChallenge() const
					{
						return _Challenge(m_Response.GetGSDataObject("challenge").GetValue());
					}
				/// <summary>
				/// The amount of type 1 currency the player has won.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency1Won () const
					{
						return m_Response.GetLong("currency1Won");
					}
				/// <summary>
				/// The amount of type 2 currency the player has won.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency2Won () const
					{
						return m_Response.GetLong("currency2Won");
					}
				/// <summary>
				/// The amount of type 3 currency the player has won.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency3Won () const
					{
						return m_Response.GetLong("currency3Won");
					}
				/// <summary>
				/// The amount of type 4 currency the player has won.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency4Won () const
					{
						return m_Response.GetLong("currency4Won");
					}
				/// <summary>
				/// The amount of type 5 currency the player has won.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency5Won () const
					{
						return m_Response.GetLong("currency5Won");
					}
				/// <summary>
				/// The amount of type 6 currency the player has won.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency6Won () const
					{
						return m_Response.GetLong("currency6Won");
					}
				/// <summary>
				/// The leaderboard data associated with this challenge.
				/// </summary>
					// method type 2
					_LeaderboardData GetLeaderboardData() const
					{
						return _LeaderboardData(m_Response.GetGSDataObject("leaderboardData").GetValue());
					}
				/// <summary>
				/// Flag indicating whether this message could be sent as a push notification or not.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_BoolOptional GetNotification () const
					{
						return m_Response.GetBoolean("notification");
					}
				/// <summary>
				/// A textual title for the message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetSubTitle () const
					{
						return m_Response.GetString("subTitle");
					}
				/// <summary>
				/// A textual summary describing the message's purpose.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetSummary () const
					{
						return m_Response.GetString("summary");
					}
				/// <summary>
				/// A textual title for the message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetTitle () const
					{
						return m_Response.GetString("title");
					}
				/// <summary>
				/// The winning player's name.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetWinnerName () const
					{
						return m_Response.GetString("winnerName");
					}
			};
			
			class FriendMessage : public GSMessage
			{
				public:
					// used by SetListener to register message creation functions
					static const char* GetTypeName()
					{
						return ".FriendMessage";
					}

					FriendMessage(const GSData& data)
					: GSMessage(data)
					{

					}
				public:
				/// <summary>
				/// The player's id who is sending the message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetFromId () const
					{
						return m_Response.GetString("fromId");
					}
				/// <summary>
				/// The player's message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetMessage () const
					{
						return m_Response.GetString("message");
					}
				/// <summary>
				/// Flag indicating whether this message could be sent as a push notification or not.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_BoolOptional GetNotification () const
					{
						return m_Response.GetBoolean("notification");
					}
				/// <summary>
				/// A textual title for the message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetSubTitle () const
					{
						return m_Response.GetString("subTitle");
					}
				/// <summary>
				/// A textual summary describing the message's purpose.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetSummary () const
					{
						return m_Response.GetString("summary");
					}
				/// <summary>
				/// A textual title for the message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetTitle () const
					{
						return m_Response.GetString("title");
					}
				/// <summary>
				/// The name of the player who is sending the message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetWho () const
					{
						return m_Response.GetString("who");
					}
			};
			
			class GlobalRankChangedMessage : public GSMessage
			{
				public:
					// used by SetListener to register message creation functions
					static const char* GetTypeName()
					{
						return ".GlobalRankChangedMessage";
					}

					GlobalRankChangedMessage(const GSData& data)
					: GSMessage(data)
					{

					}
				public:
		class _LeaderboardData : public GSTypedResponse
		{
		public:
			_LeaderboardData(const GSData& data) 
				: GSTypedResponse(data)
			{

			}
			
				/// <summary>
				/// The city where the player was located when they logged this leaderboard entry.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetCity () const
					{
						return m_Response.GetString("city");
					}
				/// <summary>
				/// The country code where the player was located when they logged this leaderboard entry.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetCountry () const
					{
						return m_Response.GetString("country");
					}
				/// <summary>
				/// The players rank.
				/// </summary>
					// method type 4
					GameSparks::Core::GSData::t_Optional GetExternalIds () const
					{
						return m_Response.GetGSDataObject("externalIds");
					}
				/// <summary>
				/// The unique leaderboard id.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetId () const
					{
						return m_Response.GetString("id");
					}
				/// <summary>
				/// The players rank.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetRank () const
					{
						return m_Response.GetLong("rank");
					}
				/// <summary>
				/// The unique player id for this leaderboard entry.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetUserId () const
					{
						return m_Response.GetString("userId");
					}
				/// <summary>
				/// The players display name.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetUserName () const
					{
						return m_Response.GetString("userName");
					}
				/// <summary>
				/// The date when this leaderboard entry was created.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetWhen () const
					{
						return m_Response.GetString("when");
					}
		};
				/// <summary>
				/// The game id that this message relates to.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetGameId () const
					{
						return m_Response.GetLong("gameId");
					}
				/// <summary>
				/// The leaderboard's name.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetLeaderboardName () const
					{
						return m_Response.GetString("leaderboardName");
					}
				/// <summary>
				/// The leaderboard shortcode.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetLeaderboardShortCode () const
					{
						return m_Response.GetString("leaderboardShortCode");
					}
				/// <summary>
				/// Flag indicating whether this message could be sent as a push notification or not.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_BoolOptional GetNotification () const
					{
						return m_Response.GetBoolean("notification");
					}
				/// <summary>
				/// A textual title for the message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetSubTitle () const
					{
						return m_Response.GetString("subTitle");
					}
				/// <summary>
				/// A textual summary describing the message's purpose.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetSummary () const
					{
						return m_Response.GetString("summary");
					}
				/// <summary>
				/// The score details of the player whose score the receiving player has passed.
				/// </summary>
					// method type 2
					_LeaderboardData GetThem() const
					{
						return _LeaderboardData(m_Response.GetGSDataObject("them").GetValue());
					}
				/// <summary>
				/// A textual title for the message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetTitle () const
					{
						return m_Response.GetString("title");
					}
				/// <summary>
				/// The score details of the receiving player.
				/// </summary>
					// method type 2
					_LeaderboardData GetYou() const
					{
						return _LeaderboardData(m_Response.GetGSDataObject("you").GetValue());
					}
			};
			
			class NewHighScoreMessage : public GSMessage
			{
				public:
					// used by SetListener to register message creation functions
					static const char* GetTypeName()
					{
						return ".NewHighScoreMessage";
					}

					NewHighScoreMessage(const GSData& data)
					: GSMessage(data)
					{

					}
				public:
		class _LeaderboardRankDetails : public GSTypedResponse
		{
		public:
			_LeaderboardRankDetails(const GSData& data) 
				: GSTypedResponse(data)
			{

			}
			
		class _LeaderboardData : public GSTypedResponse
		{
		public:
			_LeaderboardData(const GSData& data) 
				: GSTypedResponse(data)
			{

			}
			
				/// <summary>
				/// The city where the player was located when they logged this leaderboard entry.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetCity () const
					{
						return m_Response.GetString("city");
					}
				/// <summary>
				/// The country code where the player was located when they logged this leaderboard entry.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetCountry () const
					{
						return m_Response.GetString("country");
					}
				/// <summary>
				/// The players rank.
				/// </summary>
					// method type 4
					GameSparks::Core::GSData::t_Optional GetExternalIds () const
					{
						return m_Response.GetGSDataObject("externalIds");
					}
				/// <summary>
				/// The unique leaderboard id.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetId () const
					{
						return m_Response.GetString("id");
					}
				/// <summary>
				/// The players rank.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetRank () const
					{
						return m_Response.GetLong("rank");
					}
				/// <summary>
				/// The unique player id for this leaderboard entry.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetUserId () const
					{
						return m_Response.GetString("userId");
					}
				/// <summary>
				/// The players display name.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetUserName () const
					{
						return m_Response.GetString("userName");
					}
				/// <summary>
				/// The date when this leaderboard entry was created.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetWhen () const
					{
						return m_Response.GetString("when");
					}
		};
				/// <summary>
				/// The leaderboard entries of the players friends that were beaten as part of this score submission.
				/// </summary>
					// method type 1
					gsstl::vector<_LeaderboardData> GetFriendsPassed() const
					{
						gsstl::vector<_LeaderboardData> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getFriendsPassed");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_LeaderboardData(*it));
						}
						return result; 
					}
				/// <summary>
				/// The number of entries in this leaderboard.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetGlobalCount () const
					{
						return m_Response.GetLong("globalCount");
					}
				/// <summary>
				/// The Global Rank of the player in this leaderboard before the score was submitted.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetGlobalFrom () const
					{
						return m_Response.GetLong("globalFrom");
					}
				/// <summary>
				/// The old global rank of the player as a percentage of the total number of scores in this leaderboard .
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetGlobalFromPercent () const
					{
						return m_Response.GetLong("globalFromPercent");
					}
				/// <summary>
				/// The Global Rank of the player in this leaderboard after the score was submitted.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetGlobalTo () const
					{
						return m_Response.GetLong("globalTo");
					}
				/// <summary>
				/// The new global rank of the player as a percentage of the total number of scores in this leaderboard .
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetGlobalToPercent () const
					{
						return m_Response.GetLong("globalToPercent");
					}
				/// <summary>
				/// The number of friend entries the player has in this leaderboard.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetSocialCount () const
					{
						return m_Response.GetLong("socialCount");
					}
				/// <summary>
				/// The Social Rank of the player in this leaderboard before the score was submitted.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetSocialFrom () const
					{
						return m_Response.GetLong("socialFrom");
					}
				/// <summary>
				/// The old social rank of the player as a percentage of the total number of friend scores in this leaderboard.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetSocialFromPercent () const
					{
						return m_Response.GetLong("socialFromPercent");
					}
				/// <summary>
				/// The Social Rank of the player in this leaderboard after the score was submitted.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetSocialTo () const
					{
						return m_Response.GetLong("socialTo");
					}
				/// <summary>
				/// The old global rank of the player as a percentage of the total number of friend scores in this leaderboard.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetSocialToPercent () const
					{
						return m_Response.GetLong("socialToPercent");
					}
				/// <summary>
				/// The leaderboard entries of the global players that were beaten as part of this score submission. Requires Top N to be configured on the leaderboard
				/// </summary>
					// method type 1
					gsstl::vector<_LeaderboardData> GetTopNPassed() const
					{
						gsstl::vector<_LeaderboardData> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getTopNPassed");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_LeaderboardData(*it));
						}
						return result; 
					}
		};
		class _LeaderboardData : public GSTypedResponse
		{
		public:
			_LeaderboardData(const GSData& data) 
				: GSTypedResponse(data)
			{

			}
			
				/// <summary>
				/// The city where the player was located when they logged this leaderboard entry.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetCity () const
					{
						return m_Response.GetString("city");
					}
				/// <summary>
				/// The country code where the player was located when they logged this leaderboard entry.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetCountry () const
					{
						return m_Response.GetString("country");
					}
				/// <summary>
				/// The players rank.
				/// </summary>
					// method type 4
					GameSparks::Core::GSData::t_Optional GetExternalIds () const
					{
						return m_Response.GetGSDataObject("externalIds");
					}
				/// <summary>
				/// The unique leaderboard id.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetId () const
					{
						return m_Response.GetString("id");
					}
				/// <summary>
				/// The players rank.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetRank () const
					{
						return m_Response.GetLong("rank");
					}
				/// <summary>
				/// The unique player id for this leaderboard entry.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetUserId () const
					{
						return m_Response.GetString("userId");
					}
				/// <summary>
				/// The players display name.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetUserName () const
					{
						return m_Response.GetString("userName");
					}
				/// <summary>
				/// The date when this leaderboard entry was created.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetWhen () const
					{
						return m_Response.GetString("when");
					}
		};
				/// <summary>
				/// The new leaderboard data associated with this message.
				/// </summary>
					// method type 2
					_LeaderboardData GetLeaderboardData() const
					{
						return _LeaderboardData(m_Response.GetGSDataObject("leaderboardData").GetValue());
					}
				/// <summary>
				/// The leaderboard's name.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetLeaderboardName () const
					{
						return m_Response.GetString("leaderboardName");
					}
				/// <summary>
				/// The leaderboard shortcode.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetLeaderboardShortCode () const
					{
						return m_Response.GetString("leaderboardShortCode");
					}
				/// <summary>
				/// Flag indicating whether this message could be sent as a push notification or not.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_BoolOptional GetNotification () const
					{
						return m_Response.GetBoolean("notification");
					}
				/// <summary>
				/// The ranking information for the new score.
				/// </summary>
					// method type 2
					_LeaderboardRankDetails GetRankDetails() const
					{
						return _LeaderboardRankDetails(m_Response.GetGSDataObject("rankDetails").GetValue());
					}
				/// <summary>
				/// A textual title for the message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetSubTitle () const
					{
						return m_Response.GetString("subTitle");
					}
				/// <summary>
				/// A textual summary describing the message's purpose.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetSummary () const
					{
						return m_Response.GetString("summary");
					}
				/// <summary>
				/// A textual title for the message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetTitle () const
					{
						return m_Response.GetString("title");
					}
			};
			
			class NewTeamScoreMessage : public GSMessage
			{
				public:
					// used by SetListener to register message creation functions
					static const char* GetTypeName()
					{
						return ".NewTeamScoreMessage";
					}

					NewTeamScoreMessage(const GSData& data)
					: GSMessage(data)
					{

					}
				public:
		class _LeaderboardRankDetails : public GSTypedResponse
		{
		public:
			_LeaderboardRankDetails(const GSData& data) 
				: GSTypedResponse(data)
			{

			}
			
		class _LeaderboardData : public GSTypedResponse
		{
		public:
			_LeaderboardData(const GSData& data) 
				: GSTypedResponse(data)
			{

			}
			
				/// <summary>
				/// The city where the player was located when they logged this leaderboard entry.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetCity () const
					{
						return m_Response.GetString("city");
					}
				/// <summary>
				/// The country code where the player was located when they logged this leaderboard entry.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetCountry () const
					{
						return m_Response.GetString("country");
					}
				/// <summary>
				/// The players rank.
				/// </summary>
					// method type 4
					GameSparks::Core::GSData::t_Optional GetExternalIds () const
					{
						return m_Response.GetGSDataObject("externalIds");
					}
				/// <summary>
				/// The unique leaderboard id.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetId () const
					{
						return m_Response.GetString("id");
					}
				/// <summary>
				/// The players rank.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetRank () const
					{
						return m_Response.GetLong("rank");
					}
				/// <summary>
				/// The unique player id for this leaderboard entry.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetUserId () const
					{
						return m_Response.GetString("userId");
					}
				/// <summary>
				/// The players display name.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetUserName () const
					{
						return m_Response.GetString("userName");
					}
				/// <summary>
				/// The date when this leaderboard entry was created.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetWhen () const
					{
						return m_Response.GetString("when");
					}
		};
				/// <summary>
				/// The leaderboard entries of the players friends that were beaten as part of this score submission.
				/// </summary>
					// method type 1
					gsstl::vector<_LeaderboardData> GetFriendsPassed() const
					{
						gsstl::vector<_LeaderboardData> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getFriendsPassed");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_LeaderboardData(*it));
						}
						return result; 
					}
				/// <summary>
				/// The number of entries in this leaderboard.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetGlobalCount () const
					{
						return m_Response.GetLong("globalCount");
					}
				/// <summary>
				/// The Global Rank of the player in this leaderboard before the score was submitted.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetGlobalFrom () const
					{
						return m_Response.GetLong("globalFrom");
					}
				/// <summary>
				/// The old global rank of the player as a percentage of the total number of scores in this leaderboard .
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetGlobalFromPercent () const
					{
						return m_Response.GetLong("globalFromPercent");
					}
				/// <summary>
				/// The Global Rank of the player in this leaderboard after the score was submitted.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetGlobalTo () const
					{
						return m_Response.GetLong("globalTo");
					}
				/// <summary>
				/// The new global rank of the player as a percentage of the total number of scores in this leaderboard .
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetGlobalToPercent () const
					{
						return m_Response.GetLong("globalToPercent");
					}
				/// <summary>
				/// The number of friend entries the player has in this leaderboard.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetSocialCount () const
					{
						return m_Response.GetLong("socialCount");
					}
				/// <summary>
				/// The Social Rank of the player in this leaderboard before the score was submitted.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetSocialFrom () const
					{
						return m_Response.GetLong("socialFrom");
					}
				/// <summary>
				/// The old social rank of the player as a percentage of the total number of friend scores in this leaderboard.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetSocialFromPercent () const
					{
						return m_Response.GetLong("socialFromPercent");
					}
				/// <summary>
				/// The Social Rank of the player in this leaderboard after the score was submitted.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetSocialTo () const
					{
						return m_Response.GetLong("socialTo");
					}
				/// <summary>
				/// The old global rank of the player as a percentage of the total number of friend scores in this leaderboard.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetSocialToPercent () const
					{
						return m_Response.GetLong("socialToPercent");
					}
				/// <summary>
				/// The leaderboard entries of the global players that were beaten as part of this score submission. Requires Top N to be configured on the leaderboard
				/// </summary>
					// method type 1
					gsstl::vector<_LeaderboardData> GetTopNPassed() const
					{
						gsstl::vector<_LeaderboardData> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("getTopNPassed");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_LeaderboardData(*it));
						}
						return result; 
					}
		};
		class _LeaderboardData : public GSTypedResponse
		{
		public:
			_LeaderboardData(const GSData& data) 
				: GSTypedResponse(data)
			{

			}
			
				/// <summary>
				/// The city where the player was located when they logged this leaderboard entry.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetCity () const
					{
						return m_Response.GetString("city");
					}
				/// <summary>
				/// The country code where the player was located when they logged this leaderboard entry.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetCountry () const
					{
						return m_Response.GetString("country");
					}
				/// <summary>
				/// The players rank.
				/// </summary>
					// method type 4
					GameSparks::Core::GSData::t_Optional GetExternalIds () const
					{
						return m_Response.GetGSDataObject("externalIds");
					}
				/// <summary>
				/// The unique leaderboard id.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetId () const
					{
						return m_Response.GetString("id");
					}
				/// <summary>
				/// The players rank.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetRank () const
					{
						return m_Response.GetLong("rank");
					}
				/// <summary>
				/// The unique player id for this leaderboard entry.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetUserId () const
					{
						return m_Response.GetString("userId");
					}
				/// <summary>
				/// The players display name.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetUserName () const
					{
						return m_Response.GetString("userName");
					}
				/// <summary>
				/// The date when this leaderboard entry was created.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetWhen () const
					{
						return m_Response.GetString("when");
					}
		};
				/// <summary>
				/// The new leaderboard data associated with this message.
				/// </summary>
					// method type 2
					_LeaderboardData GetLeaderboardData() const
					{
						return _LeaderboardData(m_Response.GetGSDataObject("leaderboardData").GetValue());
					}
				/// <summary>
				/// The leaderboard's name.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetLeaderboardName () const
					{
						return m_Response.GetString("leaderboardName");
					}
				/// <summary>
				/// The leaderboard shortcode.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetLeaderboardShortCode () const
					{
						return m_Response.GetString("leaderboardShortCode");
					}
				/// <summary>
				/// Flag indicating whether this message could be sent as a push notification or not.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_BoolOptional GetNotification () const
					{
						return m_Response.GetBoolean("notification");
					}
				/// <summary>
				/// The ranking information for the new score.
				/// </summary>
					// method type 2
					_LeaderboardRankDetails GetRankDetails() const
					{
						return _LeaderboardRankDetails(m_Response.GetGSDataObject("rankDetails").GetValue());
					}
				/// <summary>
				/// A textual title for the message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetSubTitle () const
					{
						return m_Response.GetString("subTitle");
					}
				/// <summary>
				/// A textual summary describing the message's purpose.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetSummary () const
					{
						return m_Response.GetString("summary");
					}
				/// <summary>
				/// A textual title for the message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetTitle () const
					{
						return m_Response.GetString("title");
					}
			};
			
			class ScriptMessage : public GSMessage
			{
				public:
					// used by SetListener to register message creation functions
					static const char* GetTypeName()
					{
						return ".ScriptMessage";
					}

					ScriptMessage(const GSData& data)
					: GSMessage(data)
					{

					}
				public:
				/// <summary>
				/// JSON data sent from a Cloud Code script.
				/// </summary>
					// method type 4
					GameSparks::Core::GSData::t_Optional GetData () const
					{
						return m_Response.GetGSDataObject("data");
					}
				/// <summary>
				/// The extension code used wen creating this script message
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetExtCode () const
					{
						return m_Response.GetString("extCode");
					}
				/// <summary>
				/// Flag indicating whether this message could be sent as a push notification or not.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_BoolOptional GetNotification () const
					{
						return m_Response.GetBoolean("notification");
					}
				/// <summary>
				/// A textual title for the message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetSubTitle () const
					{
						return m_Response.GetString("subTitle");
					}
				/// <summary>
				/// A textual summary describing the message's purpose.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetSummary () const
					{
						return m_Response.GetString("summary");
					}
				/// <summary>
				/// A textual title for the message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetTitle () const
					{
						return m_Response.GetString("title");
					}
			};
			
			class SessionTerminatedMessage : public GSMessage
			{
				public:
					// used by SetListener to register message creation functions
					static const char* GetTypeName()
					{
						return ".SessionTerminatedMessage";
					}

					SessionTerminatedMessage(const GSData& data)
					: GSMessage(data)
					{

					}
				public:
				/// <summary>
				/// Used to automatically re-authenticate a client during socket connect.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetAuthToken () const
					{
						return m_Response.GetString("authToken");
					}
			};
			
			class SocialRankChangedMessage : public GSMessage
			{
				public:
					// used by SetListener to register message creation functions
					static const char* GetTypeName()
					{
						return ".SocialRankChangedMessage";
					}

					SocialRankChangedMessage(const GSData& data)
					: GSMessage(data)
					{

					}
				public:
		class _LeaderboardData : public GSTypedResponse
		{
		public:
			_LeaderboardData(const GSData& data) 
				: GSTypedResponse(data)
			{

			}
			
				/// <summary>
				/// The city where the player was located when they logged this leaderboard entry.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetCity () const
					{
						return m_Response.GetString("city");
					}
				/// <summary>
				/// The country code where the player was located when they logged this leaderboard entry.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetCountry () const
					{
						return m_Response.GetString("country");
					}
				/// <summary>
				/// The players rank.
				/// </summary>
					// method type 4
					GameSparks::Core::GSData::t_Optional GetExternalIds () const
					{
						return m_Response.GetGSDataObject("externalIds");
					}
				/// <summary>
				/// The unique leaderboard id.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetId () const
					{
						return m_Response.GetString("id");
					}
				/// <summary>
				/// The players rank.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetRank () const
					{
						return m_Response.GetLong("rank");
					}
				/// <summary>
				/// The unique player id for this leaderboard entry.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetUserId () const
					{
						return m_Response.GetString("userId");
					}
				/// <summary>
				/// The players display name.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetUserName () const
					{
						return m_Response.GetString("userName");
					}
				/// <summary>
				/// The date when this leaderboard entry was created.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetWhen () const
					{
						return m_Response.GetString("when");
					}
		};
				/// <summary>
				/// The game id that this message relates to.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetGameId () const
					{
						return m_Response.GetLong("gameId");
					}
				/// <summary>
				/// The leaderboard's name.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetLeaderboardName () const
					{
						return m_Response.GetString("leaderboardName");
					}
				/// <summary>
				/// The leaderboard shortcode.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetLeaderboardShortCode () const
					{
						return m_Response.GetString("leaderboardShortCode");
					}
				/// <summary>
				/// Flag indicating whether this message could be sent as a push notification or not.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_BoolOptional GetNotification () const
					{
						return m_Response.GetBoolean("notification");
					}
				/// <summary>
				/// A textual title for the message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetSubTitle () const
					{
						return m_Response.GetString("subTitle");
					}
				/// <summary>
				/// A textual summary describing the message's purpose.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetSummary () const
					{
						return m_Response.GetString("summary");
					}
				/// <summary>
				/// The score details of the player whose score the receiving player has passed.
				/// </summary>
					// method type 2
					_LeaderboardData GetThem() const
					{
						return _LeaderboardData(m_Response.GetGSDataObject("them").GetValue());
					}
				/// <summary>
				/// A textual title for the message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetTitle () const
					{
						return m_Response.GetString("title");
					}
				/// <summary>
				/// The score details of the receiving player.
				/// </summary>
					// method type 2
					_LeaderboardData GetYou() const
					{
						return _LeaderboardData(m_Response.GetGSDataObject("you").GetValue());
					}
			};
			
			class TeamChatMessage : public GSMessage
			{
				public:
					// used by SetListener to register message creation functions
					static const char* GetTypeName()
					{
						return ".TeamChatMessage";
					}

					TeamChatMessage(const GSData& data)
					: GSMessage(data)
					{

					}
				public:
				/// <summary>
				/// The identifier for this message as it appears in the chat history.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetChatMessageId () const
					{
						return m_Response.GetString("chatMessageId");
					}
				/// <summary>
				/// The player's id who is sending the message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetFromId () const
					{
						return m_Response.GetString("fromId");
					}
				/// <summary>
				/// The message to send to the team.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetMessage () const
					{
						return m_Response.GetString("message");
					}
				/// <summary>
				/// Flag indicating whether this message could be sent as a push notification or not.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_BoolOptional GetNotification () const
					{
						return m_Response.GetBoolean("notification");
					}
				/// <summary>
				/// The id of the owner
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetOwnerId () const
					{
						return m_Response.GetString("ownerId");
					}
				/// <summary>
				/// A textual title for the message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetSubTitle () const
					{
						return m_Response.GetString("subTitle");
					}
				/// <summary>
				/// A textual summary describing the message's purpose.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetSummary () const
					{
						return m_Response.GetString("summary");
					}
				/// <summary>
				/// The id of the team
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetTeamId () const
					{
						return m_Response.GetString("teamId");
					}
				/// <summary>
				/// The team type
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetTeamType () const
					{
						return m_Response.GetString("teamType");
					}
				/// <summary>
				/// A textual title for the message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetTitle () const
					{
						return m_Response.GetString("title");
					}
				/// <summary>
				/// The name of the player who is sending the message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetWho () const
					{
						return m_Response.GetString("who");
					}
			};
			
			class TeamRankChangedMessage : public GSMessage
			{
				public:
					// used by SetListener to register message creation functions
					static const char* GetTypeName()
					{
						return ".TeamRankChangedMessage";
					}

					TeamRankChangedMessage(const GSData& data)
					: GSMessage(data)
					{

					}
				public:
		class _LeaderboardData : public GSTypedResponse
		{
		public:
			_LeaderboardData(const GSData& data) 
				: GSTypedResponse(data)
			{

			}
			
				/// <summary>
				/// The city where the player was located when they logged this leaderboard entry.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetCity () const
					{
						return m_Response.GetString("city");
					}
				/// <summary>
				/// The country code where the player was located when they logged this leaderboard entry.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetCountry () const
					{
						return m_Response.GetString("country");
					}
				/// <summary>
				/// The players rank.
				/// </summary>
					// method type 4
					GameSparks::Core::GSData::t_Optional GetExternalIds () const
					{
						return m_Response.GetGSDataObject("externalIds");
					}
				/// <summary>
				/// The unique leaderboard id.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetId () const
					{
						return m_Response.GetString("id");
					}
				/// <summary>
				/// The players rank.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetRank () const
					{
						return m_Response.GetLong("rank");
					}
				/// <summary>
				/// The unique player id for this leaderboard entry.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetUserId () const
					{
						return m_Response.GetString("userId");
					}
				/// <summary>
				/// The players display name.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetUserName () const
					{
						return m_Response.GetString("userName");
					}
				/// <summary>
				/// The date when this leaderboard entry was created.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetWhen () const
					{
						return m_Response.GetString("when");
					}
		};
				/// <summary>
				/// The game id that this message relates to.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetGameId () const
					{
						return m_Response.GetLong("gameId");
					}
				/// <summary>
				/// The leaderboard's name.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetLeaderboardName () const
					{
						return m_Response.GetString("leaderboardName");
					}
				/// <summary>
				/// The leaderboard shortcode.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetLeaderboardShortCode () const
					{
						return m_Response.GetString("leaderboardShortCode");
					}
				/// <summary>
				/// Flag indicating whether this message could be sent as a push notification or not.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_BoolOptional GetNotification () const
					{
						return m_Response.GetBoolean("notification");
					}
				/// <summary>
				/// A textual title for the message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetSubTitle () const
					{
						return m_Response.GetString("subTitle");
					}
				/// <summary>
				/// A textual summary describing the message's purpose.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetSummary () const
					{
						return m_Response.GetString("summary");
					}
				/// <summary>
				/// The score details of the team whose score the receiving team's players have passed.
				/// </summary>
					// method type 2
					_LeaderboardData GetThem() const
					{
						return _LeaderboardData(m_Response.GetGSDataObject("them").GetValue());
					}
				/// <summary>
				/// A textual title for the message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetTitle () const
					{
						return m_Response.GetString("title");
					}
				/// <summary>
				/// The score details of the receiving team.
				/// </summary>
					// method type 2
					_LeaderboardData GetYou() const
					{
						return _LeaderboardData(m_Response.GetGSDataObject("you").GetValue());
					}
			};
			
			class UploadCompleteMessage : public GSMessage
			{
				public:
					// used by SetListener to register message creation functions
					static const char* GetTypeName()
					{
						return ".UploadCompleteMessage";
					}

					UploadCompleteMessage(const GSData& data)
					: GSMessage(data)
					{

					}
				public:
		class _UploadData : public GSTypedResponse
		{
		public:
			_UploadData(const GSData& data) 
				: GSTypedResponse(data)
			{

			}
			
				/// <summary>
				/// The filename of the file that was uploaded.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetFileName () const
					{
						return m_Response.GetString("fileName");
					}
				/// <summary>
				/// The unique player id of the player that uploaded the file.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetPlayerId () const
					{
						return m_Response.GetString("playerId");
					}
		};
				/// <summary>
				/// Flag indicating whether this message could be sent as a push notification or not.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_BoolOptional GetNotification () const
					{
						return m_Response.GetBoolean("notification");
					}
				/// <summary>
				/// A textual title for the message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetSubTitle () const
					{
						return m_Response.GetString("subTitle");
					}
				/// <summary>
				/// A textual summary describing the message's purpose.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetSummary () const
					{
						return m_Response.GetString("summary");
					}
				/// <summary>
				/// A textual title for the message.
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetTitle () const
					{
						return m_Response.GetString("title");
					}
				/// <summary>
				/// The upload data (if supplied as part of GetUploadUrlRequest) of UploadData objects
				/// </summary>
					// method type 2
					_UploadData GetUploadData() const
					{
						return _UploadData(m_Response.GetGSDataObject("uploadData").GetValue());
					}
				/// <summary>
				/// The id of the upload
				/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetUploadId () const
					{
						return m_Response.GetString("uploadId");
					}
			};
			
		}
	}
}	


