#pragma once

//THIS FILE IS AUTO GENERATED, DO NOT MODIFY!!
//THIS FILE IS AUTO GENERATED, DO NOT MODIFY!!
//THIS FILE IS AUTO GENERATED, DO NOT MODIFY!!

#include "../GSTypedResponse.h"

namespace GameSparks
{
	namespace Api
	{
		namespace Responses
		{
			class AcceptChallengeResponse : public  GameSparks::Core::GSTypedResponse
			{
			public:
				AcceptChallengeResponse(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				AcceptChallengeResponse(const AcceptChallengeResponse& other)
					: GSTypedResponse(other)
				{
				}

			/// <summary>
			/// The ID of the challenge
			/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetChallengeInstanceId () const
					{
						return m_Response.GetString("challengeInstanceId");
					}
			};
			class AccountDetailsResponse : public  GameSparks::Core::GSTypedResponse
			{
			public:
				AccountDetailsResponse(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				AccountDetailsResponse(const AccountDetailsResponse& other)
					: GSTypedResponse(other)
				{
				}

		class _Location : public GSTypedResponse
		{
		public:
			_Location(const GameSparks::Core::GSData& data) 
				: GSTypedResponse(data)
			{

			}

			/// <summary>
			/// The city
			/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetCity () const
					{
						return m_Response.GetString("city");
					}
			/// <summary>
			/// The country
			/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetCountry () const
					{
						return m_Response.GetString("country");
					}
			/// <summary>
			/// The latitude
			/// </summary>
					// method type 4
					GameSparks::Optional::t_FloatOptional GetLatitide () const
					{
						return m_Response.GetFloat("latitide");
					}
			/// <summary>
			/// The longditute
			/// </summary>
					// method type 4
					GameSparks::Optional::t_FloatOptional GetLongditute () const
					{
						return m_Response.GetFloat("longditute");
					}
			
		};
			/// <summary>
			/// A JSON object containing the player's achievments
			/// </summary>
						gsstl::vector<gsstl::string> GetAchievements() const
						{
							return m_Response.GetStringList("achievements");
						}
			/// <summary>
			/// The amount of type 1 currency that the player holds
			/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency1 () const
					{
						return m_Response.GetLong("currency1");
					}
			/// <summary>
			/// The amount of type 2 currency that the player holds
			/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency2 () const
					{
						return m_Response.GetLong("currency2");
					}
			/// <summary>
			/// The amount of type 3 currency that the player holds
			/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency3 () const
					{
						return m_Response.GetLong("currency3");
					}
			/// <summary>
			/// The amount of type 4 currency that the player holds
			/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency4 () const
					{
						return m_Response.GetLong("currency4");
					}
			/// <summary>
			/// The amount of type 5 currency that the player holds
			/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency5 () const
					{
						return m_Response.GetLong("currency5");
					}
			/// <summary>
			/// The amount of type 6 currency that the player holds
			/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency6 () const
					{
						return m_Response.GetLong("currency6");
					}
			/// <summary>
			/// The player's display name
			/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetDisplayName () const
					{
						return m_Response.GetString("displayName");
					}
			/// <summary>
			/// A JSON object containing the player's external account details
			/// </summary>
					// method type 4
					GameSparks::Core::GSData::t_Optional GetExternalIds () const
					{
						return m_Response.GetGSDataObject("externalIds");
					}
			/// <summary>
			/// A JSON object containing the player's location
			/// </summary>
					// method type 2
					_Location GetLocation() const
					{
						return _Location(m_Response.GetGSDataObject("location").GetValue());
					}
			/// <summary>
			/// The amount of type 1 currency that the player holds which is currently reserved
			/// </summary>
					// method type 4
					GameSparks::Core::GSData::t_Optional GetReservedCurrency1 () const
					{
						return m_Response.GetGSDataObject("reservedCurrency1");
					}
			/// <summary>
			/// The amount of type 2 currency that the player holds which is currently reserved
			/// </summary>
					// method type 4
					GameSparks::Core::GSData::t_Optional GetReservedCurrency2 () const
					{
						return m_Response.GetGSDataObject("reservedCurrency2");
					}
			/// <summary>
			/// The amount of type 3 currency that the player holds which is currently reserved
			/// </summary>
					// method type 4
					GameSparks::Core::GSData::t_Optional GetReservedCurrency3 () const
					{
						return m_Response.GetGSDataObject("reservedCurrency3");
					}
			/// <summary>
			/// The amount of type 4 currency that the player holds which is currently reserved
			/// </summary>
					// method type 4
					GameSparks::Core::GSData::t_Optional GetReservedCurrency4 () const
					{
						return m_Response.GetGSDataObject("reservedCurrency4");
					}
			/// <summary>
			/// The amount of type 5 currency that the player holds which is currently reserved
			/// </summary>
					// method type 4
					GameSparks::Core::GSData::t_Optional GetReservedCurrency5 () const
					{
						return m_Response.GetGSDataObject("reservedCurrency5");
					}
			/// <summary>
			/// The amount of type 6 currency that the player holds which is currently reserved
			/// </summary>
					// method type 4
					GameSparks::Core::GSData::t_Optional GetReservedCurrency6 () const
					{
						return m_Response.GetGSDataObject("reservedCurrency6");
					}
			/// <summary>
			/// The player's id
			/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetUserId () const
					{
						return m_Response.GetString("userId");
					}
			/// <summary>
			/// A JSON object containing the virtual goods that the player owns
			/// </summary>
					// method type 4
					GameSparks::Core::GSData::t_Optional GetVirtualGoods () const
					{
						return m_Response.GetGSDataObject("virtualGoods");
					}
			};
			class AnalyticsResponse : public  GameSparks::Core::GSTypedResponse
			{
			public:
				AnalyticsResponse(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				AnalyticsResponse(const AnalyticsResponse& other)
					: GSTypedResponse(other)
				{
				}

			};
			class AroundMeLeaderboardResponse : public  GameSparks::Core::GSTypedResponse
			{
			public:
				AroundMeLeaderboardResponse(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				AroundMeLeaderboardResponse(const AroundMeLeaderboardResponse& other)
					: GSTypedResponse(other)
				{
				}

		class _LeaderboardData : public GSTypedResponse
		{
		public:
			_LeaderboardData(const GameSparks::Core::GSData& data) 
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
			
			GameSparks::Optional::t_LongOptional GetNumberValue(const gsstl::string& key)
			{
				return m_Response.GetLong(key);
			}
			
			GameSparks::Optional::t_StringOptional GetStringValue(const gsstl::string& key)
			{
				return m_Response.GetString(key);
			}
		};
			/// <summary>
			/// The leaderboard's challenge id
			/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetChallengeInstanceId () const
					{
						return m_Response.GetString("challengeInstanceId");
					}
			/// <summary>
			/// The leaderboard data
			/// </summary>
					// method type 1
					gsstl::vector<_LeaderboardData> GetData() const
					{
						gsstl::vector<_LeaderboardData> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("data");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_LeaderboardData(*it));
						}
						return result; 
					}
			/// <summary>
			/// The first item in the leaderboard data
			/// </summary>
					// method type 1
					gsstl::vector<_LeaderboardData> GetFirst() const
					{
						gsstl::vector<_LeaderboardData> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("first");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_LeaderboardData(*it));
						}
						return result; 
					}
			/// <summary>
			/// The last item in the leaderboard data
			/// </summary>
					// method type 1
					gsstl::vector<_LeaderboardData> GetLast() const
					{
						gsstl::vector<_LeaderboardData> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("last");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_LeaderboardData(*it));
						}
						return result; 
					}
			/// <summary>
			/// The leaderboard short code
			/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetLeaderboardShortCode () const
					{
						return m_Response.GetString("leaderboardShortCode");
					}
			/// <summary>
			/// True if the response contains a social leaderboard's data
			/// </summary>
					// method type 4
					GameSparks::Optional::t_BoolOptional GetSocial () const
					{
						return m_Response.GetBoolean("social");
					}
			};
			class AuthenticationResponse : public  GameSparks::Core::GSTypedResponse
			{
			public:
				AuthenticationResponse(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				AuthenticationResponse(const AuthenticationResponse& other)
					: GSTypedResponse(other)
				{
				}

		class _Player : public GSTypedResponse
		{
		public:
			_Player(const GameSparks::Core::GSData& data) 
				: GSTypedResponse(data)
			{

			}

			/// <summary>
			/// The achievements of the Player
			/// </summary>
						gsstl::vector<gsstl::string> GetAchievements() const
						{
							return m_Response.GetStringList("achievements");
						}
			/// <summary>
			/// The display name of the Player
			/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetDisplayName () const
					{
						return m_Response.GetString("displayName");
					}
			/// <summary>
			/// The external Id's of the Player
			/// </summary>
					// method type 4
					GameSparks::Core::GSData::t_Optional GetExternalIds () const
					{
						return m_Response.GetGSDataObject("externalIds");
					}
			/// <summary>
			/// The id of the Player
			/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetId () const
					{
						return m_Response.GetString("id");
					}
			/// <summary>
			/// The online status of the Player
			/// </summary>
					// method type 4
					GameSparks::Optional::t_BoolOptional GetOnline () const
					{
						return m_Response.GetBoolean("online");
					}
			/// <summary>
			/// The virtual goods of the Player
			/// </summary>
						gsstl::vector<gsstl::string> GetVirtualGoods() const
						{
							return m_Response.GetStringList("virtualGoods");
						}
			
		};
			/// <summary>
			/// 44b297a8-162a-4220-8c14-dad9a1946ad2
			/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetAuthToken () const
					{
						return m_Response.GetString("authToken");
					}
			/// <summary>
			/// The player's display name
			/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetDisplayName () const
					{
						return m_Response.GetString("displayName");
					}
			/// <summary>
			/// Indicates whether the player was created as part of this request
			/// </summary>
					// method type 4
					GameSparks::Optional::t_BoolOptional GetNewPlayer () const
					{
						return m_Response.GetBoolean("newPlayer");
					}
			/// <summary>
			/// A summary of the player that would be switched to.  Only returned as part of an error response for a request where automatic switching is disabled.
			/// </summary>
					// method type 2
					_Player GetSwitchSummary() const
					{
						return _Player(m_Response.GetGSDataObject("switchSummary").GetValue());
					}
			/// <summary>
			/// The player's id
			/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetUserId () const
					{
						return m_Response.GetString("userId");
					}
			};
			class BuyVirtualGoodResponse : public  GameSparks::Core::GSTypedResponse
			{
			public:
				BuyVirtualGoodResponse(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				BuyVirtualGoodResponse(const BuyVirtualGoodResponse& other)
					: GSTypedResponse(other)
				{
				}

		class _Boughtitem : public GSTypedResponse
		{
		public:
			_Boughtitem(const GameSparks::Core::GSData& data) 
				: GSTypedResponse(data)
			{

			}

			/// <summary>
			/// The quantity of the bought item
			/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetQuantity () const
					{
						return m_Response.GetLong("quantity");
					}
			/// <summary>
			/// The short code of the bought item
			/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetShortCode () const
					{
						return m_Response.GetString("shortCode");
					}
			
		};
			/// <summary>
			/// A JSON object containing details of the bought items
			/// </summary>
					// method type 1
					gsstl::vector<_Boughtitem> GetBoughtItems() const
					{
						gsstl::vector<_Boughtitem> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("boughtItems");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_Boughtitem(*it));
						}
						return result; 
					}
			/// <summary>
			/// How much currency type 1 was added
			/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency1Added () const
					{
						return m_Response.GetLong("currency1Added");
					}
			/// <summary>
			/// How much currency type 2 was added
			/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency2Added () const
					{
						return m_Response.GetLong("currency2Added");
					}
			/// <summary>
			/// How much currency type 3 was added
			/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency3Added () const
					{
						return m_Response.GetLong("currency3Added");
					}
			/// <summary>
			/// How much currency type 4 was added
			/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency4Added () const
					{
						return m_Response.GetLong("currency4Added");
					}
			/// <summary>
			/// How much currency type 5 was added
			/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency5Added () const
					{
						return m_Response.GetLong("currency5Added");
					}
			/// <summary>
			/// How much currency type 6 was added
			/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency6Added () const
					{
						return m_Response.GetLong("currency6Added");
					}
			/// <summary>
			/// For a buy with currency request, how much currency was used
			/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrencyConsumed () const
					{
						return m_Response.GetLong("currencyConsumed");
					}
			/// <summary>
			/// For a buy with currency request, which currency type was used
			/// </summary>
					// method type 4
					GameSparks::Optional::t_IntOptional GetCurrencyType () const
					{
						return m_Response.GetInt("currencyType");
					}
			};
			class ChangeUserDetailsResponse : public  GameSparks::Core::GSTypedResponse
			{
			public:
				ChangeUserDetailsResponse(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				ChangeUserDetailsResponse(const ChangeUserDetailsResponse& other)
					: GSTypedResponse(other)
				{
				}

			};
			class ChatOnChallengeResponse : public  GameSparks::Core::GSTypedResponse
			{
			public:
				ChatOnChallengeResponse(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				ChatOnChallengeResponse(const ChatOnChallengeResponse& other)
					: GSTypedResponse(other)
				{
				}

			/// <summary>
			/// The challenge instance id
			/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetChallengeInstanceId () const
					{
						return m_Response.GetString("challengeInstanceId");
					}
			};
			class ConsumeVirtualGoodResponse : public  GameSparks::Core::GSTypedResponse
			{
			public:
				ConsumeVirtualGoodResponse(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				ConsumeVirtualGoodResponse(const ConsumeVirtualGoodResponse& other)
					: GSTypedResponse(other)
				{
				}

			};
			class CreateChallengeResponse : public  GameSparks::Core::GSTypedResponse
			{
			public:
				CreateChallengeResponse(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				CreateChallengeResponse(const CreateChallengeResponse& other)
					: GSTypedResponse(other)
				{
				}

			};
			class CreateTeamResponse : public  GameSparks::Core::GSTypedResponse
			{
			public:
				CreateTeamResponse(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				CreateTeamResponse(const CreateTeamResponse& other)
					: GSTypedResponse(other)
				{
				}

		class _Player : public GSTypedResponse
		{
		public:
			_Player(const GameSparks::Core::GSData& data) 
				: GSTypedResponse(data)
			{

			}

			/// <summary>
			/// The achievements of the Player
			/// </summary>
						gsstl::vector<gsstl::string> GetAchievements() const
						{
							return m_Response.GetStringList("achievements");
						}
			/// <summary>
			/// The display name of the Player
			/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetDisplayName () const
					{
						return m_Response.GetString("displayName");
					}
			/// <summary>
			/// The external Id's of the Player
			/// </summary>
					// method type 4
					GameSparks::Core::GSData::t_Optional GetExternalIds () const
					{
						return m_Response.GetGSDataObject("externalIds");
					}
			/// <summary>
			/// The id of the Player
			/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetId () const
					{
						return m_Response.GetString("id");
					}
			/// <summary>
			/// The online status of the Player
			/// </summary>
					// method type 4
					GameSparks::Optional::t_BoolOptional GetOnline () const
					{
						return m_Response.GetBoolean("online");
					}
			/// <summary>
			/// The virtual goods of the Player
			/// </summary>
						gsstl::vector<gsstl::string> GetVirtualGoods() const
						{
							return m_Response.GetStringList("virtualGoods");
						}
			
		};
			/// <summary>
			/// The team members
			/// </summary>
					// method type 1
					gsstl::vector<_Player> GetMembers() const
					{
						gsstl::vector<_Player> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("members");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_Player(*it));
						}
						return result; 
					}
			/// <summary>
			/// A summary of the owner
			/// </summary>
					// method type 2
					_Player GetOwner() const
					{
						return _Player(m_Response.GetGSDataObject("owner").GetValue());
					}
			/// <summary>
			/// The Id of the team
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
			};
			class DeclineChallengeResponse : public  GameSparks::Core::GSTypedResponse
			{
			public:
				DeclineChallengeResponse(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				DeclineChallengeResponse(const DeclineChallengeResponse& other)
					: GSTypedResponse(other)
				{
				}

			/// <summary>
			/// The challenge instance id
			/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetChallengeInstanceId () const
					{
						return m_Response.GetString("challengeInstanceId");
					}
			};
			class DismissMessageResponse : public  GameSparks::Core::GSTypedResponse
			{
			public:
				DismissMessageResponse(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				DismissMessageResponse(const DismissMessageResponse& other)
					: GSTypedResponse(other)
				{
				}

			};
			class DropTeamResponse : public  GameSparks::Core::GSTypedResponse
			{
			public:
				DropTeamResponse(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				DropTeamResponse(const DropTeamResponse& other)
					: GSTypedResponse(other)
				{
				}

		class _Player : public GSTypedResponse
		{
		public:
			_Player(const GameSparks::Core::GSData& data) 
				: GSTypedResponse(data)
			{

			}

			/// <summary>
			/// The achievements of the Player
			/// </summary>
						gsstl::vector<gsstl::string> GetAchievements() const
						{
							return m_Response.GetStringList("achievements");
						}
			/// <summary>
			/// The display name of the Player
			/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetDisplayName () const
					{
						return m_Response.GetString("displayName");
					}
			/// <summary>
			/// The external Id's of the Player
			/// </summary>
					// method type 4
					GameSparks::Core::GSData::t_Optional GetExternalIds () const
					{
						return m_Response.GetGSDataObject("externalIds");
					}
			/// <summary>
			/// The id of the Player
			/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetId () const
					{
						return m_Response.GetString("id");
					}
			/// <summary>
			/// The online status of the Player
			/// </summary>
					// method type 4
					GameSparks::Optional::t_BoolOptional GetOnline () const
					{
						return m_Response.GetBoolean("online");
					}
			/// <summary>
			/// The virtual goods of the Player
			/// </summary>
						gsstl::vector<gsstl::string> GetVirtualGoods() const
						{
							return m_Response.GetStringList("virtualGoods");
						}
			
		};
			/// <summary>
			/// The team members
			/// </summary>
					// method type 1
					gsstl::vector<_Player> GetMembers() const
					{
						gsstl::vector<_Player> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("members");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_Player(*it));
						}
						return result; 
					}
			/// <summary>
			/// A summary of the owner
			/// </summary>
					// method type 2
					_Player GetOwner() const
					{
						return _Player(m_Response.GetGSDataObject("owner").GetValue());
					}
			/// <summary>
			/// The Id of the team
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
			};
			class EndSessionResponse : public  GameSparks::Core::GSTypedResponse
			{
			public:
				EndSessionResponse(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				EndSessionResponse(const EndSessionResponse& other)
					: GSTypedResponse(other)
				{
				}

			};
			class FindChallengeResponse : public  GameSparks::Core::GSTypedResponse
			{
			public:
				FindChallengeResponse(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				FindChallengeResponse(const FindChallengeResponse& other)
					: GSTypedResponse(other)
				{
				}

		class _Challenge : public GSTypedResponse
		{
		public:
			_Challenge(const GameSparks::Core::GSData& data) 
				: GSTypedResponse(data)
			{

			}

		class _PlayerDetail : public GSTypedResponse
		{
		public:
			_PlayerDetail(const GameSparks::Core::GSData& data) 
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
			_PlayerTurnCount(const GameSparks::Core::GSData& data) 
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
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("accepted");
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
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("challenged");
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
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("declined");
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
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("turnCount");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerTurnCount(*it));
						}
						return result; 
					}
			
		};
			/// <summary>
			/// A list of JSON objects representing the challenges.
			/// </summary>
					// method type 1
					gsstl::vector<_Challenge> GetChallengeInstances() const
					{
						gsstl::vector<_Challenge> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("challengeInstances");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_Challenge(*it));
						}
						return result; 
					}
			};
			class GameSparksErrorResponse : public  GameSparks::Core::GSTypedResponse
			{
			public:
				GameSparksErrorResponse(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				GameSparksErrorResponse(const GameSparksErrorResponse& other)
					: GSTypedResponse(other)
				{
				}

			};
			class GetChallengeResponse : public  GameSparks::Core::GSTypedResponse
			{
			public:
				GetChallengeResponse(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				GetChallengeResponse(const GetChallengeResponse& other)
					: GSTypedResponse(other)
				{
				}

		class _Challenge : public GSTypedResponse
		{
		public:
			_Challenge(const GameSparks::Core::GSData& data) 
				: GSTypedResponse(data)
			{

			}

		class _PlayerDetail : public GSTypedResponse
		{
		public:
			_PlayerDetail(const GameSparks::Core::GSData& data) 
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
			_PlayerTurnCount(const GameSparks::Core::GSData& data) 
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
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("accepted");
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
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("challenged");
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
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("declined");
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
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("turnCount");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerTurnCount(*it));
						}
						return result; 
					}
			
		};
			/// <summary>
			/// A JSON object representing the challenge.
			/// </summary>
					// method type 2
					_Challenge GetChallenge() const
					{
						return _Challenge(m_Response.GetGSDataObject("challenge").GetValue());
					}
			};
			class GetDownloadableResponse : public  GameSparks::Core::GSTypedResponse
			{
			public:
				GetDownloadableResponse(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				GetDownloadableResponse(const GetDownloadableResponse& other)
					: GSTypedResponse(other)
				{
				}

			/// <summary>
			/// The date when the downloadable item was last modified
			/// </summary>
					// method type 4
					GameSparks::Core::GSDateTime::t_Optional GetLastModified () const
					{
						return m_Response.GetDate("lastModified");
					}
			/// <summary>
			/// The short code of the item
			/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetShortCode () const
					{
						return m_Response.GetString("shortCode");
					}
			/// <summary>
			/// The size of the item in bytes
			/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetSize () const
					{
						return m_Response.GetLong("size");
					}
			/// <summary>
			/// The download URL
			/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetUrl () const
					{
						return m_Response.GetString("url");
					}
			};
			class GetLeaderboardEntriesResponse : public  GameSparks::Core::GSTypedResponse
			{
			public:
				GetLeaderboardEntriesResponse(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				GetLeaderboardEntriesResponse(const GetLeaderboardEntriesResponse& other)
					: GSTypedResponse(other)
				{
				}

			/// <summary>
			/// The leaderboard entry data
			/// </summary>
					// method type 4
					GameSparks::Core::GSData::t_Optional GetResults () const
					{
						return m_Response.GetGSDataObject("results");
					}
			};
			class GetMessageResponse : public  GameSparks::Core::GSTypedResponse
			{
			public:
				GetMessageResponse(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				GetMessageResponse(const GetMessageResponse& other)
					: GSTypedResponse(other)
				{
				}

			/// <summary>
			/// The message data
			/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetMessage () const
					{
						return m_Response.GetString("message");
					}
			};
			class GetMyTeamsResponse : public  GameSparks::Core::GSTypedResponse
			{
			public:
				GetMyTeamsResponse(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				GetMyTeamsResponse(const GetMyTeamsResponse& other)
					: GSTypedResponse(other)
				{
				}

		class _Team : public GSTypedResponse
		{
		public:
			_Team(const GameSparks::Core::GSData& data) 
				: GSTypedResponse(data)
			{

			}

		class _Player : public GSTypedResponse
		{
		public:
			_Player(const GameSparks::Core::GSData& data) 
				: GSTypedResponse(data)
			{

			}

			/// <summary>
			/// The achievements of the Player
			/// </summary>
						gsstl::vector<gsstl::string> GetAchievements() const
						{
							return m_Response.GetStringList("achievements");
						}
			/// <summary>
			/// The display name of the Player
			/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetDisplayName () const
					{
						return m_Response.GetString("displayName");
					}
			/// <summary>
			/// The external Id's of the Player
			/// </summary>
					// method type 4
					GameSparks::Core::GSData::t_Optional GetExternalIds () const
					{
						return m_Response.GetGSDataObject("externalIds");
					}
			/// <summary>
			/// The id of the Player
			/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetId () const
					{
						return m_Response.GetString("id");
					}
			/// <summary>
			/// The online status of the Player
			/// </summary>
					// method type 4
					GameSparks::Optional::t_BoolOptional GetOnline () const
					{
						return m_Response.GetBoolean("online");
					}
			/// <summary>
			/// The virtual goods of the Player
			/// </summary>
						gsstl::vector<gsstl::string> GetVirtualGoods() const
						{
							return m_Response.GetStringList("virtualGoods");
						}
			
		};
			/// <summary>
			/// The team members
			/// </summary>
					// method type 1
					gsstl::vector<_Player> GetMembers() const
					{
						gsstl::vector<_Player> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("members");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_Player(*it));
						}
						return result; 
					}
			/// <summary>
			/// A summary of the owner
			/// </summary>
					// method type 2
					_Player GetOwner() const
					{
						return _Player(m_Response.GetGSDataObject("owner").GetValue());
					}
			/// <summary>
			/// The Id of the team
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
			
		};
			/// <summary>
			/// The team data
			/// </summary>
					// method type 1
					gsstl::vector<_Team> GetTeams() const
					{
						gsstl::vector<_Team> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("teams");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_Team(*it));
						}
						return result; 
					}
			};
			class GetRunningTotalsResponse : public  GameSparks::Core::GSTypedResponse
			{
			public:
				GetRunningTotalsResponse(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				GetRunningTotalsResponse(const GetRunningTotalsResponse& other)
					: GSTypedResponse(other)
				{
				}

			/// <summary>
			/// A list of JSON objects representing the aggregation data
			/// </summary>
					// method type 4
					GameSparks::Core::GSData::t_Optional GetRunningTotals () const
					{
						return m_Response.GetGSDataObject("runningTotals");
					}
			};
			class GetTeamResponse : public  GameSparks::Core::GSTypedResponse
			{
			public:
				GetTeamResponse(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				GetTeamResponse(const GetTeamResponse& other)
					: GSTypedResponse(other)
				{
				}

		class _Player : public GSTypedResponse
		{
		public:
			_Player(const GameSparks::Core::GSData& data) 
				: GSTypedResponse(data)
			{

			}

			/// <summary>
			/// The achievements of the Player
			/// </summary>
						gsstl::vector<gsstl::string> GetAchievements() const
						{
							return m_Response.GetStringList("achievements");
						}
			/// <summary>
			/// The display name of the Player
			/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetDisplayName () const
					{
						return m_Response.GetString("displayName");
					}
			/// <summary>
			/// The external Id's of the Player
			/// </summary>
					// method type 4
					GameSparks::Core::GSData::t_Optional GetExternalIds () const
					{
						return m_Response.GetGSDataObject("externalIds");
					}
			/// <summary>
			/// The id of the Player
			/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetId () const
					{
						return m_Response.GetString("id");
					}
			/// <summary>
			/// The online status of the Player
			/// </summary>
					// method type 4
					GameSparks::Optional::t_BoolOptional GetOnline () const
					{
						return m_Response.GetBoolean("online");
					}
			/// <summary>
			/// The virtual goods of the Player
			/// </summary>
						gsstl::vector<gsstl::string> GetVirtualGoods() const
						{
							return m_Response.GetStringList("virtualGoods");
						}
			
		};
			/// <summary>
			/// The team members
			/// </summary>
					// method type 1
					gsstl::vector<_Player> GetMembers() const
					{
						gsstl::vector<_Player> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("members");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_Player(*it));
						}
						return result; 
					}
			/// <summary>
			/// A summary of the owner
			/// </summary>
					// method type 2
					_Player GetOwner() const
					{
						return _Player(m_Response.GetGSDataObject("owner").GetValue());
					}
			/// <summary>
			/// The Id of the team
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
			};
			class GetUploadUrlResponse : public  GameSparks::Core::GSTypedResponse
			{
			public:
				GetUploadUrlResponse(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				GetUploadUrlResponse(const GetUploadUrlResponse& other)
					: GSTypedResponse(other)
				{
				}

			/// <summary>
			/// The time sensitive upload URL
			/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetUrl () const
					{
						return m_Response.GetString("url");
					}
			};
			class GetUploadedResponse : public  GameSparks::Core::GSTypedResponse
			{
			public:
				GetUploadedResponse(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				GetUploadedResponse(const GetUploadedResponse& other)
					: GSTypedResponse(other)
				{
				}

			/// <summary>
			/// The size of the file in bytes
			/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetSize () const
					{
						return m_Response.GetLong("size");
					}
			/// <summary>
			/// A time sensitive URL to a piece of content
			/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetUrl () const
					{
						return m_Response.GetString("url");
					}
			};
			class JoinChallengeResponse : public  GameSparks::Core::GSTypedResponse
			{
			public:
				JoinChallengeResponse(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				JoinChallengeResponse(const JoinChallengeResponse& other)
					: GSTypedResponse(other)
				{
				}

			};
			class JoinTeamResponse : public  GameSparks::Core::GSTypedResponse
			{
			public:
				JoinTeamResponse(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				JoinTeamResponse(const JoinTeamResponse& other)
					: GSTypedResponse(other)
				{
				}

		class _Player : public GSTypedResponse
		{
		public:
			_Player(const GameSparks::Core::GSData& data) 
				: GSTypedResponse(data)
			{

			}

			/// <summary>
			/// The achievements of the Player
			/// </summary>
						gsstl::vector<gsstl::string> GetAchievements() const
						{
							return m_Response.GetStringList("achievements");
						}
			/// <summary>
			/// The display name of the Player
			/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetDisplayName () const
					{
						return m_Response.GetString("displayName");
					}
			/// <summary>
			/// The external Id's of the Player
			/// </summary>
					// method type 4
					GameSparks::Core::GSData::t_Optional GetExternalIds () const
					{
						return m_Response.GetGSDataObject("externalIds");
					}
			/// <summary>
			/// The id of the Player
			/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetId () const
					{
						return m_Response.GetString("id");
					}
			/// <summary>
			/// The online status of the Player
			/// </summary>
					// method type 4
					GameSparks::Optional::t_BoolOptional GetOnline () const
					{
						return m_Response.GetBoolean("online");
					}
			/// <summary>
			/// The virtual goods of the Player
			/// </summary>
						gsstl::vector<gsstl::string> GetVirtualGoods() const
						{
							return m_Response.GetStringList("virtualGoods");
						}
			
		};
			/// <summary>
			/// The team members
			/// </summary>
					// method type 1
					gsstl::vector<_Player> GetMembers() const
					{
						gsstl::vector<_Player> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("members");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_Player(*it));
						}
						return result; 
					}
			/// <summary>
			/// A summary of the owner
			/// </summary>
					// method type 2
					_Player GetOwner() const
					{
						return _Player(m_Response.GetGSDataObject("owner").GetValue());
					}
			/// <summary>
			/// The Id of the team
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
			};
			class LeaderboardDataResponse : public  GameSparks::Core::GSTypedResponse
			{
			public:
				LeaderboardDataResponse(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				LeaderboardDataResponse(const LeaderboardDataResponse& other)
					: GSTypedResponse(other)
				{
				}

		class _LeaderboardData : public GSTypedResponse
		{
		public:
			_LeaderboardData(const GameSparks::Core::GSData& data) 
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
			
			GameSparks::Optional::t_LongOptional GetNumberValue(const gsstl::string& key)
			{
				return m_Response.GetLong(key);
			}
			
			GameSparks::Optional::t_StringOptional GetStringValue(const gsstl::string& key)
			{
				return m_Response.GetString(key);
			}
		};
			/// <summary>
			/// The leaderboard's challenge id
			/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetChallengeInstanceId () const
					{
						return m_Response.GetString("challengeInstanceId");
					}
			/// <summary>
			/// The leaderboard data
			/// </summary>
					// method type 1
					gsstl::vector<_LeaderboardData> GetData() const
					{
						gsstl::vector<_LeaderboardData> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("data");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_LeaderboardData(*it));
						}
						return result; 
					}
			/// <summary>
			/// The first item in the leaderboard data
			/// </summary>
					// method type 1
					gsstl::vector<_LeaderboardData> GetFirst() const
					{
						gsstl::vector<_LeaderboardData> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("first");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_LeaderboardData(*it));
						}
						return result; 
					}
			/// <summary>
			/// The last item in the leaderboard data
			/// </summary>
					// method type 1
					gsstl::vector<_LeaderboardData> GetLast() const
					{
						gsstl::vector<_LeaderboardData> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("last");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_LeaderboardData(*it));
						}
						return result; 
					}
			/// <summary>
			/// The leaderboard short code
			/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetLeaderboardShortCode () const
					{
						return m_Response.GetString("leaderboardShortCode");
					}
			};
			class LeaveTeamResponse : public  GameSparks::Core::GSTypedResponse
			{
			public:
				LeaveTeamResponse(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				LeaveTeamResponse(const LeaveTeamResponse& other)
					: GSTypedResponse(other)
				{
				}

		class _Player : public GSTypedResponse
		{
		public:
			_Player(const GameSparks::Core::GSData& data) 
				: GSTypedResponse(data)
			{

			}

			/// <summary>
			/// The achievements of the Player
			/// </summary>
						gsstl::vector<gsstl::string> GetAchievements() const
						{
							return m_Response.GetStringList("achievements");
						}
			/// <summary>
			/// The display name of the Player
			/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetDisplayName () const
					{
						return m_Response.GetString("displayName");
					}
			/// <summary>
			/// The external Id's of the Player
			/// </summary>
					// method type 4
					GameSparks::Core::GSData::t_Optional GetExternalIds () const
					{
						return m_Response.GetGSDataObject("externalIds");
					}
			/// <summary>
			/// The id of the Player
			/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetId () const
					{
						return m_Response.GetString("id");
					}
			/// <summary>
			/// The online status of the Player
			/// </summary>
					// method type 4
					GameSparks::Optional::t_BoolOptional GetOnline () const
					{
						return m_Response.GetBoolean("online");
					}
			/// <summary>
			/// The virtual goods of the Player
			/// </summary>
						gsstl::vector<gsstl::string> GetVirtualGoods() const
						{
							return m_Response.GetStringList("virtualGoods");
						}
			
		};
			/// <summary>
			/// The team members
			/// </summary>
					// method type 1
					gsstl::vector<_Player> GetMembers() const
					{
						gsstl::vector<_Player> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("members");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_Player(*it));
						}
						return result; 
					}
			/// <summary>
			/// A summary of the owner
			/// </summary>
					// method type 2
					_Player GetOwner() const
					{
						return _Player(m_Response.GetGSDataObject("owner").GetValue());
					}
			/// <summary>
			/// The Id of the team
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
			};
			class ListAchievementsResponse : public  GameSparks::Core::GSTypedResponse
			{
			public:
				ListAchievementsResponse(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				ListAchievementsResponse(const ListAchievementsResponse& other)
					: GSTypedResponse(other)
				{
				}

		class _Achievement : public GSTypedResponse
		{
		public:
			_Achievement(const GameSparks::Core::GSData& data) 
				: GSTypedResponse(data)
			{

			}

			/// <summary>
			/// The desciption of the Achievement
			/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetDescription () const
					{
						return m_Response.GetString("description");
					}
			/// <summary>
			/// Whether to current player has earned the achievement
			/// </summary>
					// method type 4
					GameSparks::Optional::t_BoolOptional GetEarned () const
					{
						return m_Response.GetBoolean("earned");
					}
			/// <summary>
			/// The name of the Achievement
			/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetName () const
					{
						return m_Response.GetString("name");
					}
			/// <summary>
			/// The shortCode of the Achievement
			/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetShortCode () const
					{
						return m_Response.GetString("shortCode");
					}
			
		};
			/// <summary>
			/// A list of JSON achievment objects
			/// </summary>
					// method type 1
					gsstl::vector<_Achievement> GetAchievements() const
					{
						gsstl::vector<_Achievement> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("achievements");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_Achievement(*it));
						}
						return result; 
					}
			};
			class ListChallengeResponse : public  GameSparks::Core::GSTypedResponse
			{
			public:
				ListChallengeResponse(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				ListChallengeResponse(const ListChallengeResponse& other)
					: GSTypedResponse(other)
				{
				}

		class _Challenge : public GSTypedResponse
		{
		public:
			_Challenge(const GameSparks::Core::GSData& data) 
				: GSTypedResponse(data)
			{

			}

		class _PlayerDetail : public GSTypedResponse
		{
		public:
			_PlayerDetail(const GameSparks::Core::GSData& data) 
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
			_PlayerTurnCount(const GameSparks::Core::GSData& data) 
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
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("accepted");
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
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("challenged");
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
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("declined");
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
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("turnCount");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_PlayerTurnCount(*it));
						}
						return result; 
					}
			
		};
			/// <summary>
			/// A list of JSON objects representing the challenges.
			/// </summary>
					// method type 1
					gsstl::vector<_Challenge> GetChallengeInstances() const
					{
						gsstl::vector<_Challenge> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("challengeInstances");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_Challenge(*it));
						}
						return result; 
					}
			};
			class ListChallengeTypeResponse : public  GameSparks::Core::GSTypedResponse
			{
			public:
				ListChallengeTypeResponse(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				ListChallengeTypeResponse(const ListChallengeTypeResponse& other)
					: GSTypedResponse(other)
				{
				}

		class _ChallengeType : public GSTypedResponse
		{
		public:
			_ChallengeType(const GameSparks::Core::GSData& data) 
				: GSTypedResponse(data)
			{

			}

			/// <summary>
			/// The shortCode for this challenge.
			/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetChallengeShortCode () const
					{
						return m_Response.GetString("challengeShortCode");
					}
			/// <summary>
			/// The description of this challenge.
			/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetDescription () const
					{
						return m_Response.GetString("description");
					}
			/// <summary>
			/// The name of the leaderboard for this challenge.
			/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetGetleaderboardName () const
					{
						return m_Response.GetString("getleaderboardName");
					}
			/// <summary>
			/// The name of this challenge.
			/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetName () const
					{
						return m_Response.GetString("name");
					}
			/// <summary>
			/// The tags for this challenge.
			/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetTags () const
					{
						return m_Response.GetString("tags");
					}
			
		};
			/// <summary>
			/// A list of JSON objects containing the challenge templates for the game
			/// </summary>
					// method type 1
					gsstl::vector<_ChallengeType> GetChallengeTemplates() const
					{
						gsstl::vector<_ChallengeType> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("challengeTemplates");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_ChallengeType(*it));
						}
						return result; 
					}
			};
			class ListGameFriendsResponse : public  GameSparks::Core::GSTypedResponse
			{
			public:
				ListGameFriendsResponse(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				ListGameFriendsResponse(const ListGameFriendsResponse& other)
					: GSTypedResponse(other)
				{
				}

		class _Player : public GSTypedResponse
		{
		public:
			_Player(const GameSparks::Core::GSData& data) 
				: GSTypedResponse(data)
			{

			}

			/// <summary>
			/// The achievements of the Player
			/// </summary>
						gsstl::vector<gsstl::string> GetAchievements() const
						{
							return m_Response.GetStringList("achievements");
						}
			/// <summary>
			/// The display name of the Player
			/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetDisplayName () const
					{
						return m_Response.GetString("displayName");
					}
			/// <summary>
			/// The external Id's of the Player
			/// </summary>
					// method type 4
					GameSparks::Core::GSData::t_Optional GetExternalIds () const
					{
						return m_Response.GetGSDataObject("externalIds");
					}
			/// <summary>
			/// The id of the Player
			/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetId () const
					{
						return m_Response.GetString("id");
					}
			/// <summary>
			/// The online status of the Player
			/// </summary>
					// method type 4
					GameSparks::Optional::t_BoolOptional GetOnline () const
					{
						return m_Response.GetBoolean("online");
					}
			/// <summary>
			/// The virtual goods of the Player
			/// </summary>
						gsstl::vector<gsstl::string> GetVirtualGoods() const
						{
							return m_Response.GetStringList("virtualGoods");
						}
			
		};
			/// <summary>
			/// A list of JSON objects containing game friend data
			/// </summary>
					// method type 1
					gsstl::vector<_Player> GetFriends() const
					{
						gsstl::vector<_Player> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("friends");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_Player(*it));
						}
						return result; 
					}
			};
			class ListInviteFriendsResponse : public  GameSparks::Core::GSTypedResponse
			{
			public:
				ListInviteFriendsResponse(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				ListInviteFriendsResponse(const ListInviteFriendsResponse& other)
					: GSTypedResponse(other)
				{
				}

		class _InvitableFriend : public GSTypedResponse
		{
		public:
			_InvitableFriend(const GameSparks::Core::GSData& data) 
				: GSTypedResponse(data)
			{

			}

			/// <summary>
			/// The display name of the External Friend
			/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetDisplayName () const
					{
						return m_Response.GetString("displayName");
					}
			/// <summary>
			/// The ID of the External Friend
			/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetId () const
					{
						return m_Response.GetString("id");
					}
			/// <summary>
			/// The profile picture URL of the External Friend
			/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetProfilePic () const
					{
						return m_Response.GetString("profilePic");
					}
			
		};
			/// <summary>
			/// A list of JSON objects containing gME friend data
			/// </summary>
					// method type 1
					gsstl::vector<_InvitableFriend> GetFriends() const
					{
						gsstl::vector<_InvitableFriend> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("friends");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_InvitableFriend(*it));
						}
						return result; 
					}
			};
			class ListLeaderboardsResponse : public  GameSparks::Core::GSTypedResponse
			{
			public:
				ListLeaderboardsResponse(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				ListLeaderboardsResponse(const ListLeaderboardsResponse& other)
					: GSTypedResponse(other)
				{
				}

		class _Leaderboard : public GSTypedResponse
		{
		public:
			_Leaderboard(const GameSparks::Core::GSData& data) 
				: GSTypedResponse(data)
			{

			}

			/// <summary>
			/// The leaderboard's description.
			/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetDescription () const
					{
						return m_Response.GetString("description");
					}
			/// <summary>
			/// The leaderboard's name.
			/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetName () const
					{
						return m_Response.GetString("name");
					}
			/// <summary>
			/// The leaderboard's short code.
			/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetShortCode () const
					{
						return m_Response.GetString("shortCode");
					}
			
		};
			/// <summary>
			/// A list of JSON object containing leaderboard meta data
			/// </summary>
					// method type 1
					gsstl::vector<_Leaderboard> GetLeaderboards() const
					{
						gsstl::vector<_Leaderboard> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("leaderboards");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_Leaderboard(*it));
						}
						return result; 
					}
			};
			class ListMessageResponse : public  GameSparks::Core::GSTypedResponse
			{
			public:
				ListMessageResponse(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				ListMessageResponse(const ListMessageResponse& other)
					: GSTypedResponse(other)
				{
				}

			/// <summary>
			/// A list of JSON objects containing player messages
			/// </summary>
						// method type 3.1 
						gsstl::vector<GameSparks::Core::GSData::t_Optional> GetMessageList() const
						{
							gsstl::vector<GameSparks::Core::GSData::t_Optional> result;
							gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("messageList");
							for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
							{
								result.push_back(GameSparks::Core::GSData::t_Optional(*it, true));
							}
							return result;
						}
			};
			class ListMessageSummaryResponse : public  GameSparks::Core::GSTypedResponse
			{
			public:
				ListMessageSummaryResponse(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				ListMessageSummaryResponse(const ListMessageSummaryResponse& other)
					: GSTypedResponse(other)
				{
				}

			/// <summary>
			/// A list of JSON objects containing player message summaries
			/// </summary>
						// method type 3.1 
						gsstl::vector<GameSparks::Core::GSData::t_Optional> GetMessageList() const
						{
							gsstl::vector<GameSparks::Core::GSData::t_Optional> result;
							gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("messageList");
							for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
							{
								result.push_back(GameSparks::Core::GSData::t_Optional(*it, true));
							}
							return result;
						}
			};
			class ListTeamChatResponse : public  GameSparks::Core::GSTypedResponse
			{
			public:
				ListTeamChatResponse(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				ListTeamChatResponse(const ListTeamChatResponse& other)
					: GSTypedResponse(other)
				{
				}

			};
			class ListVirtualGoodsResponse : public  GameSparks::Core::GSTypedResponse
			{
			public:
				ListVirtualGoodsResponse(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				ListVirtualGoodsResponse(const ListVirtualGoodsResponse& other)
					: GSTypedResponse(other)
				{
				}

		class _VirtualGood : public GSTypedResponse
		{
		public:
			_VirtualGood(const GameSparks::Core::GSData& data) 
				: GSTypedResponse(data)
			{

			}

			/// <summary>
			/// The Currency1 cost of the Virtual Good
			/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency1Cost () const
					{
						return m_Response.GetLong("currency1Cost");
					}
			/// <summary>
			/// The Currency2 cost of the Virtual Good
			/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency2Cost () const
					{
						return m_Response.GetLong("currency2Cost");
					}
			/// <summary>
			/// The Currency3 cost of the Virtual Good
			/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency3Cost () const
					{
						return m_Response.GetLong("currency3Cost");
					}
			/// <summary>
			/// The Currency4 cost of the Virtual Good
			/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency4Cost () const
					{
						return m_Response.GetLong("currency4Cost");
					}
			/// <summary>
			/// The Currency5 cost of the Virtual Good
			/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency5Cost () const
					{
						return m_Response.GetLong("currency5Cost");
					}
			/// <summary>
			/// The Currency6 cost of the Virtual Good
			/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetCurrency6Cost () const
					{
						return m_Response.GetLong("currency6Cost");
					}
			/// <summary>
			/// The description of the Virtual Good
			/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetDescription () const
					{
						return m_Response.GetString("description");
					}
			/// <summary>
			/// The maximum number of the Virtual Good that can be owned at one time
			/// </summary>
					// method type 4
					GameSparks::Optional::t_LongOptional GetMaxQuantity () const
					{
						return m_Response.GetLong("maxQuantity");
					}
			/// <summary>
			/// The name of the Virtual Good
			/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetName () const
					{
						return m_Response.GetString("name");
					}
			/// <summary>
			/// The short code of the Virtual Good
			/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetShortCode () const
					{
						return m_Response.GetString("shortCode");
					}
			/// <summary>
			/// The tags of the Virtual Good
			/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetTags () const
					{
						return m_Response.GetString("tags");
					}
			
		};
			/// <summary>
			/// A list of JSON objects containing virtual goods data
			/// </summary>
					// method type 1
					gsstl::vector<_VirtualGood> GetVirtualGoods() const
					{
						gsstl::vector<_VirtualGood> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("virtualGoods");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_VirtualGood(*it));
						}
						return result; 
					}
			};
			class LogChallengeEventResponse : public  GameSparks::Core::GSTypedResponse
			{
			public:
				LogChallengeEventResponse(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				LogChallengeEventResponse(const LogChallengeEventResponse& other)
					: GSTypedResponse(other)
				{
				}

			};
			class LogEventResponse : public  GameSparks::Core::GSTypedResponse
			{
			public:
				LogEventResponse(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				LogEventResponse(const LogEventResponse& other)
					: GSTypedResponse(other)
				{
				}

			};
			class PushRegistrationResponse : public  GameSparks::Core::GSTypedResponse
			{
			public:
				PushRegistrationResponse(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				PushRegistrationResponse(const PushRegistrationResponse& other)
					: GSTypedResponse(other)
				{
				}

			/// <summary>
			/// An identifier for the successful registration.  Clients should store this value to be used in the event the player no longer wants to receive push notifications to this device.
			/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetRegistrationId () const
					{
						return m_Response.GetString("registrationId");
					}
			};
			class RegistrationResponse : public  GameSparks::Core::GSTypedResponse
			{
			public:
				RegistrationResponse(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				RegistrationResponse(const RegistrationResponse& other)
					: GSTypedResponse(other)
				{
				}

		class _Player : public GSTypedResponse
		{
		public:
			_Player(const GameSparks::Core::GSData& data) 
				: GSTypedResponse(data)
			{

			}

			/// <summary>
			/// The achievements of the Player
			/// </summary>
						gsstl::vector<gsstl::string> GetAchievements() const
						{
							return m_Response.GetStringList("achievements");
						}
			/// <summary>
			/// The display name of the Player
			/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetDisplayName () const
					{
						return m_Response.GetString("displayName");
					}
			/// <summary>
			/// The external Id's of the Player
			/// </summary>
					// method type 4
					GameSparks::Core::GSData::t_Optional GetExternalIds () const
					{
						return m_Response.GetGSDataObject("externalIds");
					}
			/// <summary>
			/// The id of the Player
			/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetId () const
					{
						return m_Response.GetString("id");
					}
			/// <summary>
			/// The online status of the Player
			/// </summary>
					// method type 4
					GameSparks::Optional::t_BoolOptional GetOnline () const
					{
						return m_Response.GetBoolean("online");
					}
			/// <summary>
			/// The virtual goods of the Player
			/// </summary>
						gsstl::vector<gsstl::string> GetVirtualGoods() const
						{
							return m_Response.GetStringList("virtualGoods");
						}
			
		};
			/// <summary>
			/// 44b297a8-162a-4220-8c14-dad9a1946ad2
			/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetAuthToken () const
					{
						return m_Response.GetString("authToken");
					}
			/// <summary>
			/// The player's display name
			/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetDisplayName () const
					{
						return m_Response.GetString("displayName");
					}
			/// <summary>
			/// Indicates whether the player was created as part of this request
			/// </summary>
					// method type 4
					GameSparks::Optional::t_BoolOptional GetNewPlayer () const
					{
						return m_Response.GetBoolean("newPlayer");
					}
			/// <summary>
			/// A summary of the player that would be switched to.  Only returned as part of an error response for a request where automatic switching is disabled.
			/// </summary>
					// method type 2
					_Player GetSwitchSummary() const
					{
						return _Player(m_Response.GetGSDataObject("switchSummary").GetValue());
					}
			/// <summary>
			/// The player's id
			/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetUserId () const
					{
						return m_Response.GetString("userId");
					}
			};
			class SendFriendMessageResponse : public  GameSparks::Core::GSTypedResponse
			{
			public:
				SendFriendMessageResponse(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				SendFriendMessageResponse(const SendFriendMessageResponse& other)
					: GSTypedResponse(other)
				{
				}

			};
			class SendTeamChatMessageResponse : public  GameSparks::Core::GSTypedResponse
			{
			public:
				SendTeamChatMessageResponse(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				SendTeamChatMessageResponse(const SendTeamChatMessageResponse& other)
					: GSTypedResponse(other)
				{
				}

			};
			class SocialDisconnectResponse : public  GameSparks::Core::GSTypedResponse
			{
			public:
				SocialDisconnectResponse(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				SocialDisconnectResponse(const SocialDisconnectResponse& other)
					: GSTypedResponse(other)
				{
				}

			};
			class SocialStatusResponse : public  GameSparks::Core::GSTypedResponse
			{
			public:
				SocialStatusResponse(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				SocialStatusResponse(const SocialStatusResponse& other)
					: GSTypedResponse(other)
				{
				}

		class _SocialStatus : public GSTypedResponse
		{
		public:
			_SocialStatus(const GameSparks::Core::GSData& data) 
				: GSTypedResponse(data)
			{

			}

			/// <summary>
			/// When the token is still active.
			/// </summary>
					// method type 4
					GameSparks::Optional::t_BoolOptional GetActive () const
					{
						return m_Response.GetBoolean("active");
					}
			/// <summary>
			/// When the token expires (if available).
			/// </summary>
					// method type 4
					GameSparks::Core::GSDateTime::t_Optional GetExpires () const
					{
						return m_Response.GetDate("expires");
					}
			/// <summary>
			/// The identifier of the external platform.
			/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetSystemId () const
					{
						return m_Response.GetString("systemId");
					}
			
		};
			/// <summary>
			/// A list of social statuses.
			/// </summary>
					// method type 1
					gsstl::vector<_SocialStatus> GetStatuses() const
					{
						gsstl::vector<_SocialStatus> result;
						gsstl::vector<GameSparks::Core::GSData> dataList = m_Response.GetGSDataObjectList("statuses");
						for (gsstl::vector<GameSparks::Core::GSData>::iterator it = dataList.begin(); it != dataList.end(); ++it)
						{
							result.push_back(_SocialStatus(*it));
						}
						return result; 
					}
			};
			class WithdrawChallengeResponse : public  GameSparks::Core::GSTypedResponse
			{
			public:
				WithdrawChallengeResponse(const GameSparks::Core::GSData& data)
					: GSTypedResponse(data)
				{

				}

				WithdrawChallengeResponse(const WithdrawChallengeResponse& other)
					: GSTypedResponse(other)
				{
				}

			/// <summary>
			/// A challenge instance id
			/// </summary>
					// method type 4
					GameSparks::Optional::t_StringOptional GetChallengeInstanceId () const
					{
						return m_Response.GetString("challengeInstanceId");
					}
			};
		}
	}
}

