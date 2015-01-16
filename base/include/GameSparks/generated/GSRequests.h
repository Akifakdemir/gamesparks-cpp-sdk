#pragma once

//THIS FILE IS AUTO GENERATED, DO NOT MODIFY!!
//THIS FILE IS AUTO GENERATED, DO NOT MODIFY!!
//THIS FILE IS AUTO GENERATED, DO NOT MODIFY!!

#include "../GSObject.h"
#include "../GSTypedResponse.h"
#include "../GSTypedRequest.h"
#include "GSResponses.h"

namespace GameSparks
{
	namespace Api
	{
		namespace Requests
		{
			class AcceptChallengeRequest : public GameSparks::Core::GSTypedRequest < AcceptChallengeRequest, GameSparks::Api::Responses::AcceptChallengeResponse >
			{
			public:
				AcceptChallengeRequest()
					: GSTypedRequest(".AcceptChallengeRequest")
				{

				}
			


			/// <summary>
			/// The ID of the challenge
			/// </summary>
			AcceptChallengeRequest& SetChallengeInstanceId( const gsstl::string& challengeInstanceId )
			{
				m_Request.AddString("challengeInstanceId", challengeInstanceId);
				return *this;
			}
			/// <summary>
			/// An optional message to send with the challenge
			/// </summary>
			AcceptChallengeRequest& SetMessage( const gsstl::string& message )
			{
				m_Request.AddString("message", message);
				return *this;
			}
			};
			
			class AccountDetailsRequest : public GameSparks::Core::GSTypedRequest < AccountDetailsRequest, GameSparks::Api::Responses::AccountDetailsResponse >
			{
			public:
				AccountDetailsRequest()
					: GSTypedRequest(".AccountDetailsRequest")
				{

				}
			


			};
			
			class AnalyticsRequest : public GameSparks::Core::GSTypedRequest < AnalyticsRequest, GameSparks::Api::Responses::AnalyticsResponse >
			{
			public:
				AnalyticsRequest()
					: GSTypedRequest(".AnalyticsRequest")
				{

				}
			


			/// <summary>
			/// Custom data payload
			/// </summary>
			AnalyticsRequest& SetData( const GameSparks::Core::GSRequestData& data )
			{
				m_Request.AddObject("data", data);
				return *this;
			}
			/// <summary>
			/// Use the value true to indicate it's an end timer
			/// </summary>
			AnalyticsRequest& SetEnd( bool end )
			{
				m_Request.AddBoolean("end", end);
				return *this;
			}
			/// <summary>
			/// The key you want to track this analysis with.
			/// </summary>
			AnalyticsRequest& SetKey( const gsstl::string& key )
			{
				m_Request.AddString("key", key);
				return *this;
			}
			/// <summary>
			/// Use the value true to indicate it's a start timer
			/// </summary>
			AnalyticsRequest& SetStart( bool start )
			{
				m_Request.AddBoolean("start", start);
				return *this;
			}
			};
			
			class AroundMeLeaderboardRequest : public GameSparks::Core::GSTypedRequest < AroundMeLeaderboardRequest, GameSparks::Api::Responses::AroundMeLeaderboardResponse >
			{
			public:
				AroundMeLeaderboardRequest()
					: GSTypedRequest(".AroundMeLeaderboardRequest")
				{

				}
			


			/// <summary>
			/// The number of items to return in a page (default=50)
			/// </summary>
			AroundMeLeaderboardRequest& SetEntryCount( long entryCount )
			{
				m_Request.AddNumber("entryCount", entryCount);
				return *this;
			}
			/// <summary>
			/// A friend id or an array of friend ids to use instead of the player's social friends
			/// </summary>
			AroundMeLeaderboardRequest& SetFriendIds( gsstl::vector<gsstl::string> friendIds )
			{
				m_Request.AddStringList("friendIds", friendIds);
				return *this;
			}
			/// <summary>
			/// Number of entries to include from head of the list
			/// </summary>
			AroundMeLeaderboardRequest& SetIncludeFirst( long includeFirst )
			{
				m_Request.AddNumber("includeFirst", includeFirst);
				return *this;
			}
			/// <summary>
			/// Number of entries to include from tail of the list
			/// </summary>
			AroundMeLeaderboardRequest& SetIncludeLast( long includeLast )
			{
				m_Request.AddNumber("includeLast", includeLast);
				return *this;
			}
			/// <summary>
			/// The short code of the leaderboard
			/// </summary>
			AroundMeLeaderboardRequest& SetLeaderboardShortCode( const gsstl::string& leaderboardShortCode )
			{
				m_Request.AddString("leaderboardShortCode", leaderboardShortCode);
				return *this;
			}
			/// <summary>
			/// If True returns a leaderboard of the player's social friends
			/// </summary>
			AroundMeLeaderboardRequest& SetSocial( bool social )
			{
				m_Request.AddBoolean("social", social);
				return *this;
			}
			/// <summary>
			/// The IDs of the teams you are interested in
			/// </summary>
			AroundMeLeaderboardRequest& SetTeamIds( gsstl::vector<gsstl::string> teamIds )
			{
				m_Request.AddStringList("teamIds", teamIds);
				return *this;
			}
			/// <summary>
			/// The type of team you are interested in
			/// </summary>
			AroundMeLeaderboardRequest& SetTeamTypes( gsstl::vector<gsstl::string> teamTypes )
			{
				m_Request.AddStringList("teamTypes", teamTypes);
				return *this;
			}
			};
			
			class AuthenticationRequest : public GameSparks::Core::GSTypedRequest < AuthenticationRequest, GameSparks::Api::Responses::AuthenticationResponse >
			{
			public:
				AuthenticationRequest()
					: GSTypedRequest(".AuthenticationRequest")
				{

				}
			


			/// <summary>
			/// The previously registered password
			/// </summary>
			AuthenticationRequest& SetPassword( const gsstl::string& password )
			{
				m_Request.AddString("password", password);
				return *this;
			}
			/// <summary>
			/// The previously registered player name
			/// </summary>
			AuthenticationRequest& SetUserName( const gsstl::string& userName )
			{
				m_Request.AddString("userName", userName);
				return *this;
			}
			};
			
			class BuyVirtualGoodsRequest : public GameSparks::Core::GSTypedRequest < BuyVirtualGoodsRequest, GameSparks::Api::Responses::BuyVirtualGoodResponse >
			{
			public:
				BuyVirtualGoodsRequest()
					: GSTypedRequest(".BuyVirtualGoodsRequest")
				{

				}
			


			/// <summary>
			/// Which virtual currency to use. (1 to 6)
			/// </summary>
			BuyVirtualGoodsRequest& SetCurrencyType( long currencyType )
			{
				m_Request.AddNumber("currencyType", currencyType);
				return *this;
			}
			/// <summary>
			/// The number of items to purchase
			/// </summary>
			BuyVirtualGoodsRequest& SetQuantity( long quantity )
			{
				m_Request.AddNumber("quantity", quantity);
				return *this;
			}
			/// <summary>
			/// The short code of the virtual good to be purchased
			/// </summary>
			BuyVirtualGoodsRequest& SetShortCode( const gsstl::string& shortCode )
			{
				m_Request.AddString("shortCode", shortCode);
				return *this;
			}
			};
			
			class ChangeUserDetailsRequest : public GameSparks::Core::GSTypedRequest < ChangeUserDetailsRequest, GameSparks::Api::Responses::ChangeUserDetailsResponse >
			{
			public:
				ChangeUserDetailsRequest()
					: GSTypedRequest(".ChangeUserDetailsRequest")
				{

				}
			


			/// <summary>
			/// The new display name to set in the player data.
			/// </summary>
			ChangeUserDetailsRequest& SetDisplayName( const gsstl::string& displayName )
			{
				m_Request.AddString("displayName", displayName);
				return *this;
			}
			/// <summary>
			/// The new language code to set in the player data.
			/// </summary>
			ChangeUserDetailsRequest& SetLanguage( const gsstl::string& language )
			{
				m_Request.AddString("language", language);
				return *this;
			}
			/// <summary>
			/// The new password to set in the player data.
			/// </summary>
			ChangeUserDetailsRequest& SetNewPassword( const gsstl::string& newPassword )
			{
				m_Request.AddString("newPassword", newPassword);
				return *this;
			}
			/// <summary>
			/// The player's existing password. If supplied it will be checked against the password stored in the player data. This allows you re-authenticate the player making the change.
			/// </summary>
			ChangeUserDetailsRequest& SetOldPassword( const gsstl::string& oldPassword )
			{
				m_Request.AddString("oldPassword", oldPassword);
				return *this;
			}
			/// <summary>
			/// The new userName with which this player will sign in.  If the player currently authenticates using device authentication this will upgrade their account and require them to use username and password authentication from now on.
			/// </summary>
			ChangeUserDetailsRequest& SetUserName( const gsstl::string& userName )
			{
				m_Request.AddString("userName", userName);
				return *this;
			}
			};
			
			class ChatOnChallengeRequest : public GameSparks::Core::GSTypedRequest < ChatOnChallengeRequest, GameSparks::Api::Responses::ChatOnChallengeResponse >
			{
			public:
				ChatOnChallengeRequest()
					: GSTypedRequest(".ChatOnChallengeRequest")
				{

				}
			


			/// <summary>
			/// The ID of the challenge
			/// </summary>
			ChatOnChallengeRequest& SetChallengeInstanceId( const gsstl::string& challengeInstanceId )
			{
				m_Request.AddString("challengeInstanceId", challengeInstanceId);
				return *this;
			}
			/// <summary>
			/// An optional message to send with the challenge
			/// </summary>
			ChatOnChallengeRequest& SetMessage( const gsstl::string& message )
			{
				m_Request.AddString("message", message);
				return *this;
			}
			};
			
			class ConsumeVirtualGoodRequest : public GameSparks::Core::GSTypedRequest < ConsumeVirtualGoodRequest, GameSparks::Api::Responses::ConsumeVirtualGoodResponse >
			{
			public:
				ConsumeVirtualGoodRequest()
					: GSTypedRequest(".ConsumeVirtualGoodRequest")
				{

				}
			


			/// <summary>
			/// The amount of virtual goods to be consumed
			/// </summary>
			ConsumeVirtualGoodRequest& SetQuantity( long quantity )
			{
				m_Request.AddNumber("quantity", quantity);
				return *this;
			}
			/// <summary>
			/// The short code of the virtual good to be consumed
			/// </summary>
			ConsumeVirtualGoodRequest& SetShortCode( const gsstl::string& shortCode )
			{
				m_Request.AddString("shortCode", shortCode);
				return *this;
			}
			};
			
			class CreateChallengeRequest : public GameSparks::Core::GSTypedRequest < CreateChallengeRequest, GameSparks::Api::Responses::CreateChallengeResponse >
			{
			public:
				CreateChallengeRequest()
					: GSTypedRequest(".CreateChallengeRequest")
				{

				}
			


			/// <summary>
			/// Who can join this challenge. Either PUBLIC, PRIVATE or FRIENDS
			/// </summary>
			CreateChallengeRequest& SetAccessType( const gsstl::string& accessType )
			{
				m_Request.AddString("accessType", accessType);
				return *this;
			}
			/// <summary>
			/// An optional message to include with the challenge
			/// </summary>
			CreateChallengeRequest& SetChallengeMessage( const gsstl::string& challengeMessage )
			{
				m_Request.AddString("challengeMessage", challengeMessage);
				return *this;
			}
			/// <summary>
			/// The short code of the challenge
			/// </summary>
			CreateChallengeRequest& SetChallengeShortCode( const gsstl::string& challengeShortCode )
			{
				m_Request.AddString("challengeShortCode", challengeShortCode);
				return *this;
			}
			/// <summary>
			/// The ammount of currency type 1 that the player is wagering on this challenge
			/// </summary>
			CreateChallengeRequest& SetCurrency1Wager( long currency1Wager )
			{
				m_Request.AddNumber("currency1Wager", currency1Wager);
				return *this;
			}
			/// <summary>
			/// The ammount of currency type 2 that the player is wagering on this challenge
			/// </summary>
			CreateChallengeRequest& SetCurrency2Wager( long currency2Wager )
			{
				m_Request.AddNumber("currency2Wager", currency2Wager);
				return *this;
			}
			/// <summary>
			/// The ammount of currency type 3 that the player is wagering on this challenge
			/// </summary>
			CreateChallengeRequest& SetCurrency3Wager( long currency3Wager )
			{
				m_Request.AddNumber("currency3Wager", currency3Wager);
				return *this;
			}
			/// <summary>
			/// The ammount of currency type 4 that the player is wagering on this challenge
			/// </summary>
			CreateChallengeRequest& SetCurrency4Wager( long currency4Wager )
			{
				m_Request.AddNumber("currency4Wager", currency4Wager);
				return *this;
			}
			/// <summary>
			/// The ammount of currency type 5 that the player is wagering on this challenge
			/// </summary>
			CreateChallengeRequest& SetCurrency5Wager( long currency5Wager )
			{
				m_Request.AddNumber("currency5Wager", currency5Wager);
				return *this;
			}
			/// <summary>
			/// The ammount of currency type 6 that the player is wagering on this challenge
			/// </summary>
			CreateChallengeRequest& SetCurrency6Wager( long currency6Wager )
			{
				m_Request.AddNumber("currency6Wager", currency6Wager);
				return *this;
			}
			/// <summary>
			/// The time at which this challenge will end
			/// </summary>
			CreateChallengeRequest& SetEndTime( const GameSparks::Core::GSDateTime& endTime )
			{
				m_Request.AddDate("endTime", endTime);
				return *this;
			}
			/// <summary>
			/// The latest time that players can join this challenge
			/// </summary>
			CreateChallengeRequest& SetExpiryTime( const GameSparks::Core::GSDateTime& expiryTime )
			{
				m_Request.AddDate("expiryTime", expiryTime);
				return *this;
			}
			/// <summary>
			/// The maximum number of attempts 
			/// </summary>
			CreateChallengeRequest& SetMaxAttempts( long maxAttempts )
			{
				m_Request.AddNumber("maxAttempts", maxAttempts);
				return *this;
			}
			/// <summary>
			/// The maximum number of players that are allowed to join this challenge
			/// </summary>
			CreateChallengeRequest& SetMaxPlayers( long maxPlayers )
			{
				m_Request.AddNumber("maxPlayers", maxPlayers);
				return *this;
			}
			/// <summary>
			/// The minimum number of players that are allowed to join this challenge
			/// </summary>
			CreateChallengeRequest& SetMinPlayers( long minPlayers )
			{
				m_Request.AddNumber("minPlayers", minPlayers);
				return *this;
			}
			/// <summary>
			/// If True  no messaging is triggered
			/// </summary>
			CreateChallengeRequest& SetSilent( bool silent )
			{
				m_Request.AddBoolean("silent", silent);
				return *this;
			}
			/// <summary>
			/// The time at which this challenge will begin
			/// </summary>
			CreateChallengeRequest& SetStartTime( const GameSparks::Core::GSDateTime& startTime )
			{
				m_Request.AddDate("startTime", startTime);
				return *this;
			}
			/// <summary>
			/// A player id or an array of player ids who will recieve this challenge
			/// </summary>
			CreateChallengeRequest& SetUsersToChallenge( gsstl::vector<gsstl::string> usersToChallenge )
			{
				m_Request.AddStringList("usersToChallenge", usersToChallenge);
				return *this;
			}
			};
			
			class CreateTeamRequest : public GameSparks::Core::GSTypedRequest < CreateTeamRequest, GameSparks::Api::Responses::CreateTeamResponse >
			{
			public:
				CreateTeamRequest()
					: GSTypedRequest(".CreateTeamRequest")
				{

				}
			


			/// <summary>
			/// An optional teamId to use
			/// </summary>
			CreateTeamRequest& SetTeamId( const gsstl::string& teamId )
			{
				m_Request.AddString("teamId", teamId);
				return *this;
			}
			/// <summary>
			/// A display name to use
			/// </summary>
			CreateTeamRequest& SetTeamName( const gsstl::string& teamName )
			{
				m_Request.AddString("teamName", teamName);
				return *this;
			}
			/// <summary>
			/// The type of team to be created
			/// </summary>
			CreateTeamRequest& SetTeamType( const gsstl::string& teamType )
			{
				m_Request.AddString("teamType", teamType);
				return *this;
			}
			};
			
			class DeclineChallengeRequest : public GameSparks::Core::GSTypedRequest < DeclineChallengeRequest, GameSparks::Api::Responses::DeclineChallengeResponse >
			{
			public:
				DeclineChallengeRequest()
					: GSTypedRequest(".DeclineChallengeRequest")
				{

				}
			


			/// <summary>
			/// The ID of the challenge
			/// </summary>
			DeclineChallengeRequest& SetChallengeInstanceId( const gsstl::string& challengeInstanceId )
			{
				m_Request.AddString("challengeInstanceId", challengeInstanceId);
				return *this;
			}
			/// <summary>
			/// An optional message to send with the challenge
			/// </summary>
			DeclineChallengeRequest& SetMessage( const gsstl::string& message )
			{
				m_Request.AddString("message", message);
				return *this;
			}
			};
			
			class DeviceAuthenticationRequest : public GameSparks::Core::GSTypedRequest < DeviceAuthenticationRequest, GameSparks::Api::Responses::AuthenticationResponse >
			{
			public:
				DeviceAuthenticationRequest()
					: GSTypedRequest(".DeviceAuthenticationRequest")
				{

				}
			


			/// <summary>
			/// An optional displayname for the player
			/// </summary>
			DeviceAuthenticationRequest& SetDisplayName( const gsstl::string& displayName )
			{
				m_Request.AddString("displayName", displayName);
				return *this;
			}
			/// <summary>
			/// An optional segment configuration for this request.
			/// If this request reates a new player on the gamesparks platform, the segments of the new player will match the values provided
			/// </summary>
			DeviceAuthenticationRequest& SetSegments( const GameSparks::Core::GSRequestData& segments )
			{
				m_Request.AddObject("segments", segments);
				return *this;
			}
			};
			
			class DismissMessageRequest : public GameSparks::Core::GSTypedRequest < DismissMessageRequest, GameSparks::Api::Responses::DismissMessageResponse >
			{
			public:
				DismissMessageRequest()
					: GSTypedRequest(".DismissMessageRequest")
				{

				}
			


			/// <summary>
			/// The messageId of the message to dismiss
			/// </summary>
			DismissMessageRequest& SetMessageId( const gsstl::string& messageId )
			{
				m_Request.AddString("messageId", messageId);
				return *this;
			}
			};
			
			class DropTeamRequest : public GameSparks::Core::GSTypedRequest < DropTeamRequest, GameSparks::Api::Responses::DropTeamResponse >
			{
			public:
				DropTeamRequest()
					: GSTypedRequest(".DropTeamRequest")
				{

				}
			


			/// <summary>
			/// The team owner to find, used in combination with teamType. If not supplied the current players id will be used
			/// </summary>
			DropTeamRequest& SetOwnerId( const gsstl::string& ownerId )
			{
				m_Request.AddString("ownerId", ownerId);
				return *this;
			}
			/// <summary>
			/// The teamId to find (may be null if teamType supplied)
			/// </summary>
			DropTeamRequest& SetTeamId( const gsstl::string& teamId )
			{
				m_Request.AddString("teamId", teamId);
				return *this;
			}
			/// <summary>
			/// The teamType to find, used in combination with the current player, or the player defined by ownerId
			/// </summary>
			DropTeamRequest& SetTeamType( const gsstl::string& teamType )
			{
				m_Request.AddString("teamType", teamType);
				return *this;
			}
			};
			
			class EndSessionRequest : public GameSparks::Core::GSTypedRequest < EndSessionRequest, GameSparks::Api::Responses::EndSessionResponse >
			{
			public:
				EndSessionRequest()
					: GSTypedRequest(".EndSessionRequest")
				{

				}
			


			};
			
			class FacebookConnectRequest : public GameSparks::Core::GSTypedRequest < FacebookConnectRequest, GameSparks::Api::Responses::AuthenticationResponse >
			{
			public:
				FacebookConnectRequest()
					: GSTypedRequest(".FacebookConnectRequest")
				{

				}
			


			/// <summary>
			/// The access token is used by the client to make authenticated requests on behalf of the end user.
			/// It has a longer lifetime than the authorization code, typically on the order of minutes or hours.
			/// When the access token expires, attempts to use it will fail, and a new access token must be obtained via a refresh token.
			/// </summary>
			FacebookConnectRequest& SetAccessToken( const gsstl::string& accessToken )
			{
				m_Request.AddString("accessToken", accessToken);
				return *this;
			}
			/// <summary>
			/// An authorization code is a short-lived token representing the user's access grant, created by the authorization server and passed to the client application via the browser.
			/// The client application sends the authorization code to the authorization server to obtain an access token and, optionally, a refresh token.
			/// </summary>
			FacebookConnectRequest& SetCode( const gsstl::string& code )
			{
				m_Request.AddString("code", code);
				return *this;
			}
			/// <summary>
			/// Indicates that the server should not try to link the external profile with the current player.  If false, links the external profile to the currently signed in player.  If true, creates a new player and links the external profile to them.  Defaults to false.
			/// </summary>
			FacebookConnectRequest& SetDoNotLinkToCurrentPlayer( bool doNotLinkToCurrentPlayer )
			{
				m_Request.AddBoolean("doNotLinkToCurrentPlayer", doNotLinkToCurrentPlayer);
				return *this;
			}
			/// <summary>
			/// Indicates whether the server should return an error if an account switch would have occurred, rather than switching automatically.  Defaults to false.
			/// </summary>
			FacebookConnectRequest& SetErrorOnSwitch( bool errorOnSwitch )
			{
				m_Request.AddBoolean("errorOnSwitch", errorOnSwitch);
				return *this;
			}
			/// <summary>
			/// An optional segment configuration for this request.
			/// If this request creates a new player on the gamesparks platform, the segments of the new player will match the values provided
			/// </summary>
			FacebookConnectRequest& SetSegments( const GameSparks::Core::GSRequestData& segments )
			{
				m_Request.AddObject("segments", segments);
				return *this;
			}
			/// <summary>
			/// Indicates that the server should switch to the supplied profile if it isalready associated to a player. Defaults to false.
			/// </summary>
			FacebookConnectRequest& SetSwitchIfPossible( bool switchIfPossible )
			{
				m_Request.AddBoolean("switchIfPossible", switchIfPossible);
				return *this;
			}
			};
			
			class GetChallengeRequest : public GameSparks::Core::GSTypedRequest < GetChallengeRequest, GameSparks::Api::Responses::GetChallengeResponse >
			{
			public:
				GetChallengeRequest()
					: GSTypedRequest(".GetChallengeRequest")
				{

				}
			


			/// <summary>
			/// The ID of the challenge
			/// </summary>
			GetChallengeRequest& SetChallengeInstanceId( const gsstl::string& challengeInstanceId )
			{
				m_Request.AddString("challengeInstanceId", challengeInstanceId);
				return *this;
			}
			/// <summary>
			/// An optional message to send with the challenge
			/// </summary>
			GetChallengeRequest& SetMessage( const gsstl::string& message )
			{
				m_Request.AddString("message", message);
				return *this;
			}
			};
			
			class GetDownloadableRequest : public GameSparks::Core::GSTypedRequest < GetDownloadableRequest, GameSparks::Api::Responses::GetDownloadableResponse >
			{
			public:
				GetDownloadableRequest()
					: GSTypedRequest(".GetDownloadableRequest")
				{

				}
			


			/// <summary>
			/// The short code of the Downloadable item
			/// </summary>
			GetDownloadableRequest& SetShortCode( const gsstl::string& shortCode )
			{
				m_Request.AddString("shortCode", shortCode);
				return *this;
			}
			};
			
			class GetLeaderboardEntriesRequest : public GameSparks::Core::GSTypedRequest < GetLeaderboardEntriesRequest, GameSparks::Api::Responses::GetLeaderboardEntriesResponse >
			{
			public:
				GetLeaderboardEntriesRequest()
					: GSTypedRequest(".GetLeaderboardEntriesRequest")
				{

				}
			


			/// <summary>
			/// The list of leaderboards shortcodes
			/// </summary>
			GetLeaderboardEntriesRequest& SetLeaderboards( gsstl::vector<gsstl::string> leaderboards )
			{
				m_Request.AddStringList("leaderboards", leaderboards);
				return *this;
			}
			/// <summary>
			/// The player id. Leave out to use the current player id
			/// </summary>
			GetLeaderboardEntriesRequest& SetPlayer( const gsstl::string& player )
			{
				m_Request.AddString("player", player);
				return *this;
			}
			/// <summary>
			/// Set to true to include the player's game friends
			/// </summary>
			GetLeaderboardEntriesRequest& SetSocial( bool social )
			{
				m_Request.AddBoolean("social", social);
				return *this;
			}
			/// <summary>
			/// The types of team to apply this request to
			/// </summary>
			GetLeaderboardEntriesRequest& SetTeamTypes( gsstl::vector<gsstl::string> teamTypes )
			{
				m_Request.AddStringList("teamTypes", teamTypes);
				return *this;
			}
			};
			
			class GetMessageRequest : public GameSparks::Core::GSTypedRequest < GetMessageRequest, GameSparks::Api::Responses::GetMessageResponse >
			{
			public:
				GetMessageRequest()
					: GSTypedRequest(".GetMessageRequest")
				{

				}
			


			/// <summary>
			/// The messageId of the message retreive
			/// </summary>
			GetMessageRequest& SetMessageId( const gsstl::string& messageId )
			{
				m_Request.AddString("messageId", messageId);
				return *this;
			}
			};
			
			class GetMyTeamsRequest : public GameSparks::Core::GSTypedRequest < GetMyTeamsRequest, GameSparks::Api::Responses::GetMyTeamsResponse >
			{
			public:
				GetMyTeamsRequest()
					: GSTypedRequest(".GetMyTeamsRequest")
				{

				}
			


			/// <summary>
			/// Set to true to only get teams owned by the player
			/// </summary>
			GetMyTeamsRequest& SetOwnedOnly( bool ownedOnly )
			{
				m_Request.AddBoolean("ownedOnly", ownedOnly);
				return *this;
			}
			/// <summary>
			/// The type of teams to get
			/// </summary>
			GetMyTeamsRequest& SetTeamTypes( gsstl::vector<gsstl::string> teamTypes )
			{
				m_Request.AddStringList("teamTypes", teamTypes);
				return *this;
			}
			};
			
			class GetRunningTotalsRequest : public GameSparks::Core::GSTypedRequest < GetRunningTotalsRequest, GameSparks::Api::Responses::GetRunningTotalsResponse >
			{
			public:
				GetRunningTotalsRequest()
					: GSTypedRequest(".GetRunningTotalsRequest")
				{

				}
			


			/// <summary>
			/// A friend id or an array of friend ids
			/// </summary>
			GetRunningTotalsRequest& SetFriendIds( gsstl::vector<gsstl::string> friendIds )
			{
				m_Request.AddStringList("friendIds", friendIds);
				return *this;
			}
			/// <summary>
			/// The short code of the running total
			/// </summary>
			GetRunningTotalsRequest& SetShortCode( const gsstl::string& shortCode )
			{
				m_Request.AddString("shortCode", shortCode);
				return *this;
			}
			};
			
			class GetTeamRequest : public GameSparks::Core::GSTypedRequest < GetTeamRequest, GameSparks::Api::Responses::GetTeamResponse >
			{
			public:
				GetTeamRequest()
					: GSTypedRequest(".GetTeamRequest")
				{

				}
			


			/// <summary>
			/// The team owner to find, used in combination with teamType. If not supplied the current players id will be used
			/// </summary>
			GetTeamRequest& SetOwnerId( const gsstl::string& ownerId )
			{
				m_Request.AddString("ownerId", ownerId);
				return *this;
			}
			/// <summary>
			/// The teamId to find (may be null if teamType supplied)
			/// </summary>
			GetTeamRequest& SetTeamId( const gsstl::string& teamId )
			{
				m_Request.AddString("teamId", teamId);
				return *this;
			}
			/// <summary>
			/// The teamType to find, used in combination with the current player, or the player defined by ownerId
			/// </summary>
			GetTeamRequest& SetTeamType( const gsstl::string& teamType )
			{
				m_Request.AddString("teamType", teamType);
				return *this;
			}
			};
			
			class GetUploadUrlRequest : public GameSparks::Core::GSTypedRequest < GetUploadUrlRequest, GameSparks::Api::Responses::GetUploadUrlResponse >
			{
			public:
				GetUploadUrlRequest()
					: GSTypedRequest(".GetUploadUrlRequest")
				{

				}
			


			/// <summary>
			/// Optional meta data which is stored against the player's uploaded content
			/// </summary>
			GetUploadUrlRequest& SetUploadData( const GameSparks::Core::GSRequestData& uploadData )
			{
				m_Request.AddObject("uploadData", uploadData);
				return *this;
			}
			};
			
			class GetUploadedRequest : public GameSparks::Core::GSTypedRequest < GetUploadedRequest, GameSparks::Api::Responses::GetUploadedResponse >
			{
			public:
				GetUploadedRequest()
					: GSTypedRequest(".GetUploadedRequest")
				{

				}
			


			/// <summary>
			/// The system generated id of the uploaded item
			/// </summary>
			GetUploadedRequest& SetUploadId( const gsstl::string& uploadId )
			{
				m_Request.AddString("uploadId", uploadId);
				return *this;
			}
			};
			
			class GooglePlayBuyGoodsRequest : public GameSparks::Core::GSTypedRequest < GooglePlayBuyGoodsRequest, GameSparks::Api::Responses::BuyVirtualGoodResponse >
			{
			public:
				GooglePlayBuyGoodsRequest()
					: GSTypedRequest(".GooglePlayBuyGoodsRequest")
				{

				}
			


			/// <summary>
			/// TODO
			/// </summary>
			GooglePlayBuyGoodsRequest& SetCurrencyCode( const gsstl::string& currencyCode )
			{
				m_Request.AddString("currencyCode", currencyCode);
				return *this;
			}
			/// <summary>
			/// The value obtained from data.getStringExtra("INAPP_DATA_SIGNATURE");
			/// </summary>
			GooglePlayBuyGoodsRequest& SetSignature( const gsstl::string& signature )
			{
				m_Request.AddString("signature", signature);
				return *this;
			}
			/// <summary>
			/// The value obtained from data.getStringExtra("INAPP_PURCHASE_DATA")
			/// </summary>
			GooglePlayBuyGoodsRequest& SetSignedData( const gsstl::string& signedData )
			{
				m_Request.AddString("signedData", signedData);
				return *this;
			}
			/// <summary>
			/// TODO
			/// </summary>
			GooglePlayBuyGoodsRequest& SetSubUnitPrice( long subUnitPrice )
			{
				m_Request.AddNumber("subUnitPrice", subUnitPrice);
				return *this;
			}
			/// <summary>
			/// If set to true, the transactionId from this reciept will not be globally valdidated, this will mean replays between players are possible.
			/// It will only validate the transactionId has not been used by this player before.
			/// </summary>
			GooglePlayBuyGoodsRequest& SetUniqueTransactionByPlayer( bool uniqueTransactionByPlayer )
			{
				m_Request.AddBoolean("uniqueTransactionByPlayer", uniqueTransactionByPlayer);
				return *this;
			}
			};
			
			class GooglePlusConnectRequest : public GameSparks::Core::GSTypedRequest < GooglePlusConnectRequest, GameSparks::Api::Responses::AuthenticationResponse >
			{
			public:
				GooglePlusConnectRequest()
					: GSTypedRequest(".GooglePlusConnectRequest")
				{

				}
			


			/// <summary>
			/// The access code is used by the client to make authenticated requests on behalf of the end user.
			/// </summary>
			GooglePlusConnectRequest& SetCode( const gsstl::string& code )
			{
				m_Request.AddString("code", code);
				return *this;
			}
			/// <summary>
			/// Indicates that the server should not try to link the external profile with the current player.  If false, links the external profile to the currently signed in player.  If true, creates a new player and links the external profile to them.  Defaults to false.
			/// </summary>
			GooglePlusConnectRequest& SetDoNotLinkToCurrentPlayer( bool doNotLinkToCurrentPlayer )
			{
				m_Request.AddBoolean("doNotLinkToCurrentPlayer", doNotLinkToCurrentPlayer);
				return *this;
			}
			/// <summary>
			/// Indicates whether the server should return an error if an account switch would have occurred, rather than switching automatically.  Defaults to false.
			/// </summary>
			GooglePlusConnectRequest& SetErrorOnSwitch( bool errorOnSwitch )
			{
				m_Request.AddBoolean("errorOnSwitch", errorOnSwitch);
				return *this;
			}
			/// <summary>
			/// An optional segment configuration for this request.
			/// If this request creates a new player on the gamesparks platform, the segments of the new player will match the values provided
			/// </summary>
			GooglePlusConnectRequest& SetSegments( const GameSparks::Core::GSRequestData& segments )
			{
				m_Request.AddObject("segments", segments);
				return *this;
			}
			/// <summary>
			/// Indicates that the server should switch to the supplied profile if it isalready associated to a player. Defaults to false.
			/// </summary>
			GooglePlusConnectRequest& SetSwitchIfPossible( bool switchIfPossible )
			{
				m_Request.AddBoolean("switchIfPossible", switchIfPossible);
				return *this;
			}
			};
			
			class IOSBuyGoodsRequest : public GameSparks::Core::GSTypedRequest < IOSBuyGoodsRequest, GameSparks::Api::Responses::BuyVirtualGoodResponse >
			{
			public:
				IOSBuyGoodsRequest()
					: GSTypedRequest(".IOSBuyGoodsRequest")
				{

				}
			


			/// <summary>
			/// TODO
			/// </summary>
			IOSBuyGoodsRequest& SetCurrencyCode( const gsstl::string& currencyCode )
			{
				m_Request.AddString("currencyCode", currencyCode);
				return *this;
			}
			/// <summary>
			/// The reciept obtained from SKPaymentTransaction. transactionReceipt
			/// </summary>
			IOSBuyGoodsRequest& SetReceipt( const gsstl::string& receipt )
			{
				m_Request.AddString("receipt", receipt);
				return *this;
			}
			/// <summary>
			/// Should the sandbox account be used
			/// </summary>
			IOSBuyGoodsRequest& SetSandbox( bool sandbox )
			{
				m_Request.AddBoolean("sandbox", sandbox);
				return *this;
			}
			/// <summary>
			/// TODO
			/// </summary>
			IOSBuyGoodsRequest& SetSubUnitPrice( long subUnitPrice )
			{
				m_Request.AddNumber("subUnitPrice", subUnitPrice);
				return *this;
			}
			/// <summary>
			/// If set to true, the transactionId from this reciept will not be globally valdidated, this will mean replays between players are possible.
			/// It will only validate the transactionId has not been used by this player before.
			/// </summary>
			IOSBuyGoodsRequest& SetUniqueTransactionByPlayer( bool uniqueTransactionByPlayer )
			{
				m_Request.AddBoolean("uniqueTransactionByPlayer", uniqueTransactionByPlayer);
				return *this;
			}
			};
			
			class JoinChallengeRequest : public GameSparks::Core::GSTypedRequest < JoinChallengeRequest, GameSparks::Api::Responses::JoinChallengeResponse >
			{
			public:
				JoinChallengeRequest()
					: GSTypedRequest(".JoinChallengeRequest")
				{

				}
			


			/// <summary>
			/// The ID of the challenge
			/// </summary>
			JoinChallengeRequest& SetChallengeInstanceId( const gsstl::string& challengeInstanceId )
			{
				m_Request.AddString("challengeInstanceId", challengeInstanceId);
				return *this;
			}
			/// <summary>
			/// An optional message to send with the challenge
			/// </summary>
			JoinChallengeRequest& SetMessage( const gsstl::string& message )
			{
				m_Request.AddString("message", message);
				return *this;
			}
			};
			
			class JoinTeamRequest : public GameSparks::Core::GSTypedRequest < JoinTeamRequest, GameSparks::Api::Responses::JoinTeamResponse >
			{
			public:
				JoinTeamRequest()
					: GSTypedRequest(".JoinTeamRequest")
				{

				}
			


			/// <summary>
			/// The team owner to find, used in combination with teamType. If not supplied the current players id will be used
			/// </summary>
			JoinTeamRequest& SetOwnerId( const gsstl::string& ownerId )
			{
				m_Request.AddString("ownerId", ownerId);
				return *this;
			}
			/// <summary>
			/// The teamId to find (may be null if teamType supplied)
			/// </summary>
			JoinTeamRequest& SetTeamId( const gsstl::string& teamId )
			{
				m_Request.AddString("teamId", teamId);
				return *this;
			}
			/// <summary>
			/// The teamType to find, used in combination with the current player, or the player defined by ownerId
			/// </summary>
			JoinTeamRequest& SetTeamType( const gsstl::string& teamType )
			{
				m_Request.AddString("teamType", teamType);
				return *this;
			}
			};
			
			class LeaderboardDataRequest : public GameSparks::Core::GSTypedRequest < LeaderboardDataRequest, GameSparks::Api::Responses::LeaderboardDataResponse >
			{
			public:
				LeaderboardDataRequest()
					: GSTypedRequest(".LeaderboardDataRequest")
				{

				}
			


			/// <summary>
			/// The challenge instance to get the leaderboard data for
			/// </summary>
			LeaderboardDataRequest& SetChallengeInstanceId( const gsstl::string& challengeInstanceId )
			{
				m_Request.AddString("challengeInstanceId", challengeInstanceId);
				return *this;
			}
			/// <summary>
			/// The number of items to return in a page (default=50)
			/// </summary>
			LeaderboardDataRequest& SetEntryCount( long entryCount )
			{
				m_Request.AddNumber("entryCount", entryCount);
				return *this;
			}
			/// <summary>
			/// A friend id or an array of friend ids to use instead of the player's social friends
			/// </summary>
			LeaderboardDataRequest& SetFriendIds( gsstl::vector<gsstl::string> friendIds )
			{
				m_Request.AddStringList("friendIds", friendIds);
				return *this;
			}
			/// <summary>
			/// Number of entries to include from head of the list
			/// </summary>
			LeaderboardDataRequest& SetIncludeFirst( long includeFirst )
			{
				m_Request.AddNumber("includeFirst", includeFirst);
				return *this;
			}
			/// <summary>
			/// Number of entries to include from tail of the list
			/// </summary>
			LeaderboardDataRequest& SetIncludeLast( long includeLast )
			{
				m_Request.AddNumber("includeLast", includeLast);
				return *this;
			}
			/// <summary>
			/// The short code of the leaderboard
			/// </summary>
			LeaderboardDataRequest& SetLeaderboardShortCode( const gsstl::string& leaderboardShortCode )
			{
				m_Request.AddString("leaderboardShortCode", leaderboardShortCode);
				return *this;
			}
			/// <summary>
			/// The offset into the set of leaderboards returned
			/// </summary>
			LeaderboardDataRequest& SetOffset( long offset )
			{
				m_Request.AddNumber("offset", offset);
				return *this;
			}
			/// <summary>
			/// If True returns a leaderboard of the player's social friends
			/// </summary>
			LeaderboardDataRequest& SetSocial( bool social )
			{
				m_Request.AddBoolean("social", social);
				return *this;
			}
			/// <summary>
			/// The IDs of the teams you are interested in
			/// </summary>
			LeaderboardDataRequest& SetTeamIds( gsstl::vector<gsstl::string> teamIds )
			{
				m_Request.AddStringList("teamIds", teamIds);
				return *this;
			}
			/// <summary>
			/// The type of team you are interested in
			/// </summary>
			LeaderboardDataRequest& SetTeamTypes( gsstl::vector<gsstl::string> teamTypes )
			{
				m_Request.AddStringList("teamTypes", teamTypes);
				return *this;
			}
			};
			
			class LeaveTeamRequest : public GameSparks::Core::GSTypedRequest < LeaveTeamRequest, GameSparks::Api::Responses::LeaveTeamResponse >
			{
			public:
				LeaveTeamRequest()
					: GSTypedRequest(".LeaveTeamRequest")
				{

				}
			


			/// <summary>
			/// The team owner to find, used in combination with teamType. If not supplied the current players id will be used
			/// </summary>
			LeaveTeamRequest& SetOwnerId( const gsstl::string& ownerId )
			{
				m_Request.AddString("ownerId", ownerId);
				return *this;
			}
			/// <summary>
			/// The teamId to find (may be null if teamType supplied)
			/// </summary>
			LeaveTeamRequest& SetTeamId( const gsstl::string& teamId )
			{
				m_Request.AddString("teamId", teamId);
				return *this;
			}
			/// <summary>
			/// The teamType to find, used in combination with the current player, or the player defined by ownerId
			/// </summary>
			LeaveTeamRequest& SetTeamType( const gsstl::string& teamType )
			{
				m_Request.AddString("teamType", teamType);
				return *this;
			}
			};
			
			class ListAchievementsRequest : public GameSparks::Core::GSTypedRequest < ListAchievementsRequest, GameSparks::Api::Responses::ListAchievementsResponse >
			{
			public:
				ListAchievementsRequest()
					: GSTypedRequest(".ListAchievementsRequest")
				{

				}
			


			};
			
			class ListChallengeRequest : public GameSparks::Core::GSTypedRequest < ListChallengeRequest, GameSparks::Api::Responses::ListChallengeResponse >
			{
			public:
				ListChallengeRequest()
					: GSTypedRequest(".ListChallengeRequest")
				{

				}
			


			/// <summary>
			/// The number of items to return in a page (default=50)
			/// </summary>
			ListChallengeRequest& SetEntryCount( long entryCount )
			{
				m_Request.AddNumber("entryCount", entryCount);
				return *this;
			}
			/// <summary>
			/// The offset (page number) to start from (default=0)
			/// </summary>
			ListChallengeRequest& SetOffset( long offset )
			{
				m_Request.AddNumber("offset", offset);
				return *this;
			}
			/// <summary>
			/// The type of challenge to return
			/// </summary>
			ListChallengeRequest& SetShortCode( const gsstl::string& shortCode )
			{
				m_Request.AddString("shortCode", shortCode);
				return *this;
			}
			/// <summary>
			/// The state of the challenged to be returned
			/// </summary>
			ListChallengeRequest& SetState( const gsstl::string& state )
			{
				m_Request.AddString("state", state);
				return *this;
			}
			};
			
			class ListChallengeTypeRequest : public GameSparks::Core::GSTypedRequest < ListChallengeTypeRequest, GameSparks::Api::Responses::ListChallengeTypeResponse >
			{
			public:
				ListChallengeTypeRequest()
					: GSTypedRequest(".ListChallengeTypeRequest")
				{

				}
			


			};
			
			class ListGameFriendsRequest : public GameSparks::Core::GSTypedRequest < ListGameFriendsRequest, GameSparks::Api::Responses::ListGameFriendsResponse >
			{
			public:
				ListGameFriendsRequest()
					: GSTypedRequest(".ListGameFriendsRequest")
				{

				}
			


			};
			
			class ListInviteFriendsRequest : public GameSparks::Core::GSTypedRequest < ListInviteFriendsRequest, GameSparks::Api::Responses::ListInviteFriendsResponse >
			{
			public:
				ListInviteFriendsRequest()
					: GSTypedRequest(".ListInviteFriendsRequest")
				{

				}
			


			};
			
			class ListLeaderboardsRequest : public GameSparks::Core::GSTypedRequest < ListLeaderboardsRequest, GameSparks::Api::Responses::ListLeaderboardsResponse >
			{
			public:
				ListLeaderboardsRequest()
					: GSTypedRequest(".ListLeaderboardsRequest")
				{

				}
			


			};
			
			class ListMessageRequest : public GameSparks::Core::GSTypedRequest < ListMessageRequest, GameSparks::Api::Responses::ListMessageResponse >
			{
			public:
				ListMessageRequest()
					: GSTypedRequest(".ListMessageRequest")
				{

				}
			


			/// <summary>
			/// The number of items to return in a page (default=50)
			/// </summary>
			ListMessageRequest& SetEntryCount( long entryCount )
			{
				m_Request.AddNumber("entryCount", entryCount);
				return *this;
			}
			/// <summary>
			/// The offset (page number) to start from (default=0)
			/// </summary>
			ListMessageRequest& SetOffset( long offset )
			{
				m_Request.AddNumber("offset", offset);
				return *this;
			}
			};
			
			class ListMessageSummaryRequest : public GameSparks::Core::GSTypedRequest < ListMessageSummaryRequest, GameSparks::Api::Responses::ListMessageSummaryResponse >
			{
			public:
				ListMessageSummaryRequest()
					: GSTypedRequest(".ListMessageSummaryRequest")
				{

				}
			


			/// <summary>
			/// The number of items to return in a page (default=50)
			/// </summary>
			ListMessageSummaryRequest& SetEntryCount( long entryCount )
			{
				m_Request.AddNumber("entryCount", entryCount);
				return *this;
			}
			/// <summary>
			/// The offset (page number) to start from (default=0)
			/// </summary>
			ListMessageSummaryRequest& SetOffset( long offset )
			{
				m_Request.AddNumber("offset", offset);
				return *this;
			}
			};
			
			class ListVirtualGoodsRequest : public GameSparks::Core::GSTypedRequest < ListVirtualGoodsRequest, GameSparks::Api::Responses::ListVirtualGoodsResponse >
			{
			public:
				ListVirtualGoodsRequest()
					: GSTypedRequest(".ListVirtualGoodsRequest")
				{

				}
			


			};
			
			class LogChallengeEventRequest : public GameSparks::Core::GSTypedRequest < LogChallengeEventRequest, GameSparks::Api::Responses::LogChallengeEventResponse >
			{
			public:
				LogChallengeEventRequest()
					: GSTypedRequest(".LogChallengeEventRequest")
				{

				}
			

				LogChallengeEventRequest& SetEventAttribute(const gsstl::string& key, long value)
				{
					m_Request.AddNumber(key, value);
					return *this;
				}

				LogChallengeEventRequest& SetEventAttribute(const gsstl::string& key, int value)
				{
					m_Request.AddNumber(key, value);
					return *this;
				}

				LogChallengeEventRequest& SetEventAttribute(const gsstl::string& key, const gsstl::string& value)
				{
					m_Request.AddString(key, value);
					return *this;
				}

				LogChallengeEventRequest& SetEventAttribute(const gsstl::string& key, const GameSparks::Core::GSRequestData& value)
				{
					m_Request.AddObject(key, value);
					return *this;
				}

				LogChallengeEventRequest& SetEventAttribute(const gsstl::string& key, gsstl::vector<GameSparks::Core::GSData> value)
				{
					m_Request.AddObjectList(key, value);
					return *this;
				}

				LogChallengeEventRequest& SetEventAttribute(const gsstl::string& key, gsstl::vector<gsstl::string> value)
				{
					m_Request.AddStringList(key, value);
					return *this;
				}

				LogChallengeEventRequest& SetEventAttribute(const gsstl::string& key, gsstl::vector<long> value)
				{
					m_Request.AddNumberList(key, value);
					return *this;
				}

				LogChallengeEventRequest& SetEventAttribute(const gsstl::string& key, gsstl::vector<int> value)
				{
					m_Request.AddNumberList(key, value);
					return *this;
				}

			/// <summary>
			/// The ID challenge instance to target
			/// </summary>
			LogChallengeEventRequest& SetChallengeInstanceId( const gsstl::string& challengeInstanceId )
			{
				m_Request.AddString("challengeInstanceId", challengeInstanceId);
				return *this;
			}
			/// <summary>
			/// The short code of the event to trigger
			/// </summary>
			LogChallengeEventRequest& SetEventKey( const gsstl::string& eventKey )
			{
				m_Request.AddString("eventKey", eventKey);
				return *this;
			}
			};
			
			class LogEventRequest : public GameSparks::Core::GSTypedRequest < LogEventRequest, GameSparks::Api::Responses::LogEventResponse >
			{
			public:
				LogEventRequest()
					: GSTypedRequest(".LogEventRequest")
				{

				}
			

				LogEventRequest& SetEventAttribute(const gsstl::string& key, long value)
				{
					m_Request.AddNumber(key, value);
					return *this;
				}

				LogEventRequest& SetEventAttribute(const gsstl::string& key, int value)
				{
					m_Request.AddNumber(key, value);
					return *this;
				}

				LogEventRequest& SetEventAttribute(const gsstl::string& key, const gsstl::string& value)
				{
					m_Request.AddString(key, value);
					return *this;
				}

				LogEventRequest& SetEventAttribute(const gsstl::string& key, const GameSparks::Core::GSRequestData& value)
				{
					m_Request.AddObject(key, value);
					return *this;
				}

				LogEventRequest& SetEventAttribute(const gsstl::string& key, gsstl::vector<GameSparks::Core::GSData> value)
				{
					m_Request.AddObjectList(key, value);
					return *this;
				}

				LogEventRequest& SetEventAttribute(const gsstl::string& key, gsstl::vector<gsstl::string> value)
				{
					m_Request.AddStringList(key, value);
					return *this;
				}

				LogEventRequest& SetEventAttribute(const gsstl::string& key, gsstl::vector<long> value)
				{
					m_Request.AddNumberList(key, value);
					return *this;
				}

				LogEventRequest& SetEventAttribute(const gsstl::string& key, gsstl::vector<int> value)
				{
					m_Request.AddNumberList(key, value);
					return *this;
				}

			/// <summary>
			/// The short code of the event to trigger
			/// </summary>
			LogEventRequest& SetEventKey( const gsstl::string& eventKey )
			{
				m_Request.AddString("eventKey", eventKey);
				return *this;
			}
			};
			
			class PushRegistrationRequest : public GameSparks::Core::GSTypedRequest < PushRegistrationRequest, GameSparks::Api::Responses::PushRegistrationResponse >
			{
			public:
				PushRegistrationRequest()
					: GSTypedRequest(".PushRegistrationRequest")
				{

				}
			


			/// <summary>
			/// The push notification identifier for the device
			/// </summary>
			PushRegistrationRequest& SetPushId( const gsstl::string& pushId )
			{
				m_Request.AddString("pushId", pushId);
				return *this;
			}
			};
			
			class RegistrationRequest : public GameSparks::Core::GSTypedRequest < RegistrationRequest, GameSparks::Api::Responses::RegistrationResponse >
			{
			public:
				RegistrationRequest()
					: GSTypedRequest(".RegistrationRequest")
				{

				}
			


			/// <summary>
			/// A display name to use
			/// </summary>
			RegistrationRequest& SetDisplayName( const gsstl::string& displayName )
			{
				m_Request.AddString("displayName", displayName);
				return *this;
			}
			/// <summary>
			/// The previously registered password
			/// </summary>
			RegistrationRequest& SetPassword( const gsstl::string& password )
			{
				m_Request.AddString("password", password);
				return *this;
			}
			/// <summary>
			/// An optional segment configuration for this request.
			/// If this request creates a new player on the gamesparks platform, the segments of the new player will match the values provided
			/// </summary>
			RegistrationRequest& SetSegments( const GameSparks::Core::GSRequestData& segments )
			{
				m_Request.AddObject("segments", segments);
				return *this;
			}
			/// <summary>
			/// The previously registered player name
			/// </summary>
			RegistrationRequest& SetUserName( const gsstl::string& userName )
			{
				m_Request.AddString("userName", userName);
				return *this;
			}
			};
			
			class SendFriendMessageRequest : public GameSparks::Core::GSTypedRequest < SendFriendMessageRequest, GameSparks::Api::Responses::SendFriendMessageResponse >
			{
			public:
				SendFriendMessageRequest()
					: GSTypedRequest(".SendFriendMessageRequest")
				{

				}
			


			/// <summary>
			/// One or more friend ID's. This can be supplied as a single string, or a JSON array
			/// </summary>
			SendFriendMessageRequest& SetFriendIds( gsstl::vector<gsstl::string> friendIds )
			{
				m_Request.AddStringList("friendIds", friendIds);
				return *this;
			}
			/// <summary>
			/// The message to send
			/// </summary>
			SendFriendMessageRequest& SetMessage( const gsstl::string& message )
			{
				m_Request.AddString("message", message);
				return *this;
			}
			};
			
			class SocialDisconnectRequest : public GameSparks::Core::GSTypedRequest < SocialDisconnectRequest, GameSparks::Api::Responses::SocialDisconnectResponse >
			{
			public:
				SocialDisconnectRequest()
					: GSTypedRequest(".SocialDisconnectRequest")
				{

				}
			


			/// <summary>
			/// The external system from which to disconnect this profile.
			/// </summary>
			SocialDisconnectRequest& SetSystemId( const gsstl::string& systemId )
			{
				m_Request.AddString("systemId", systemId);
				return *this;
			}
			};
			
			class SocialLeaderboardDataRequest : public GameSparks::Core::GSTypedRequest < SocialLeaderboardDataRequest, GameSparks::Api::Responses::LeaderboardDataResponse >
			{
			public:
				SocialLeaderboardDataRequest()
					: GSTypedRequest(".SocialLeaderboardDataRequest")
				{

				}
			


			/// <summary>
			/// The challenge instance to get the leaderboard data for
			/// </summary>
			SocialLeaderboardDataRequest& SetChallengeInstanceId( const gsstl::string& challengeInstanceId )
			{
				m_Request.AddString("challengeInstanceId", challengeInstanceId);
				return *this;
			}
			/// <summary>
			/// The number of items to return in a page (default=50)
			/// </summary>
			SocialLeaderboardDataRequest& SetEntryCount( long entryCount )
			{
				m_Request.AddNumber("entryCount", entryCount);
				return *this;
			}
			/// <summary>
			/// A friend id or an array of friend ids to use instead of the player's social friends
			/// </summary>
			SocialLeaderboardDataRequest& SetFriendIds( gsstl::vector<gsstl::string> friendIds )
			{
				m_Request.AddStringList("friendIds", friendIds);
				return *this;
			}
			/// <summary>
			/// Number of entries to include from head of the list
			/// </summary>
			SocialLeaderboardDataRequest& SetIncludeFirst( long includeFirst )
			{
				m_Request.AddNumber("includeFirst", includeFirst);
				return *this;
			}
			/// <summary>
			/// Number of entries to include from tail of the list
			/// </summary>
			SocialLeaderboardDataRequest& SetIncludeLast( long includeLast )
			{
				m_Request.AddNumber("includeLast", includeLast);
				return *this;
			}
			/// <summary>
			/// The short code of the leaderboard
			/// </summary>
			SocialLeaderboardDataRequest& SetLeaderboardShortCode( const gsstl::string& leaderboardShortCode )
			{
				m_Request.AddString("leaderboardShortCode", leaderboardShortCode);
				return *this;
			}
			/// <summary>
			/// The offset into the set of leaderboards returned
			/// </summary>
			SocialLeaderboardDataRequest& SetOffset( long offset )
			{
				m_Request.AddNumber("offset", offset);
				return *this;
			}
			/// <summary>
			/// If True returns a leaderboard of the player's social friends
			/// </summary>
			SocialLeaderboardDataRequest& SetSocial( bool social )
			{
				m_Request.AddBoolean("social", social);
				return *this;
			}
			/// <summary>
			/// The IDs of the teams you are interested in
			/// </summary>
			SocialLeaderboardDataRequest& SetTeamIds( gsstl::vector<gsstl::string> teamIds )
			{
				m_Request.AddStringList("teamIds", teamIds);
				return *this;
			}
			/// <summary>
			/// The type of team you are interested in
			/// </summary>
			SocialLeaderboardDataRequest& SetTeamTypes( gsstl::vector<gsstl::string> teamTypes )
			{
				m_Request.AddStringList("teamTypes", teamTypes);
				return *this;
			}
			};
			
			class SteamConnectRequest : public GameSparks::Core::GSTypedRequest < SteamConnectRequest, GameSparks::Api::Responses::AuthenticationResponse >
			{
			public:
				SteamConnectRequest()
					: GSTypedRequest(".SteamConnectRequest")
				{

				}
			


			/// <summary>
			/// Indicates that the server should not try to link the external profile with the current player.  If false, links the external profile to the currently signed in player.  If true, creates a new player and links the external profile to them.  Defaults to false.
			/// </summary>
			SteamConnectRequest& SetDoNotLinkToCurrentPlayer( bool doNotLinkToCurrentPlayer )
			{
				m_Request.AddBoolean("doNotLinkToCurrentPlayer", doNotLinkToCurrentPlayer);
				return *this;
			}
			/// <summary>
			/// Indicates whether the server should return an error if an account switch would have occurred, rather than switching automatically.  Defaults to false.
			/// </summary>
			SteamConnectRequest& SetErrorOnSwitch( bool errorOnSwitch )
			{
				m_Request.AddBoolean("errorOnSwitch", errorOnSwitch);
				return *this;
			}
			/// <summary>
			/// An optional segment configuration for this request.
			/// If this request creates a new player on the gamesparks platform, the segments of the new player will match the values provided
			/// </summary>
			SteamConnectRequest& SetSegments( const GameSparks::Core::GSRequestData& segments )
			{
				m_Request.AddObject("segments", segments);
				return *this;
			}
			/// <summary>
			/// The hex encoded UTF-8 string representation of the ticket acquired calling the Steam SDKs GetAuthSessionTicket.
			/// </summary>
			SteamConnectRequest& SetSessionTicket( const gsstl::string& sessionTicket )
			{
				m_Request.AddString("sessionTicket", sessionTicket);
				return *this;
			}
			/// <summary>
			/// Indicates that the server should switch to the supplied profile if it isalready associated to a player. Defaults to false.
			/// </summary>
			SteamConnectRequest& SetSwitchIfPossible( bool switchIfPossible )
			{
				m_Request.AddBoolean("switchIfPossible", switchIfPossible);
				return *this;
			}
			};
			
			class TwitterConnectRequest : public GameSparks::Core::GSTypedRequest < TwitterConnectRequest, GameSparks::Api::Responses::AuthenticationResponse >
			{
			public:
				TwitterConnectRequest()
					: GSTypedRequest(".TwitterConnectRequest")
				{

				}
			


			/// <summary>
			/// The accessSecret is obtained at the same time as the accessToken, and is required to sign requests to Twitter's services that require the accessToken.
			/// </summary>
			TwitterConnectRequest& SetAccessSecret( const gsstl::string& accessSecret )
			{
				m_Request.AddString("accessSecret", accessSecret);
				return *this;
			}
			/// <summary>
			/// The accessToken represents a player's permission to share access to their account with your application.
			/// To obtain an accessToken for the player see https://dev.twitter.com/docs/auth/obtaining-access-tokens.
			/// Currently, Twitter accessTokens do not expire but they can be revoked by the player.
			/// </summary>
			TwitterConnectRequest& SetAccessToken( const gsstl::string& accessToken )
			{
				m_Request.AddString("accessToken", accessToken);
				return *this;
			}
			/// <summary>
			/// Indicates that the server should not try to link the external profile with the current player.  If false, links the external profile to the currently signed in player.  If true, creates a new player and links the external profile to them.  Defaults to false.
			/// </summary>
			TwitterConnectRequest& SetDoNotLinkToCurrentPlayer( bool doNotLinkToCurrentPlayer )
			{
				m_Request.AddBoolean("doNotLinkToCurrentPlayer", doNotLinkToCurrentPlayer);
				return *this;
			}
			/// <summary>
			/// Indicates whether the server should return an error if an account switch would have occurred, rather than switching automatically.  Defaults to false.
			/// </summary>
			TwitterConnectRequest& SetErrorOnSwitch( bool errorOnSwitch )
			{
				m_Request.AddBoolean("errorOnSwitch", errorOnSwitch);
				return *this;
			}
			/// <summary>
			/// An optional segment configuration for this request.
			/// If this request creates a new player on the gamesparks platform, the segments of the new player will match the values provided
			/// </summary>
			TwitterConnectRequest& SetSegments( const GameSparks::Core::GSRequestData& segments )
			{
				m_Request.AddObject("segments", segments);
				return *this;
			}
			/// <summary>
			/// Indicates that the server should switch to the supplied profile if it isalready associated to a player. Defaults to false.
			/// </summary>
			TwitterConnectRequest& SetSwitchIfPossible( bool switchIfPossible )
			{
				m_Request.AddBoolean("switchIfPossible", switchIfPossible);
				return *this;
			}
			};
			
			class WindowsBuyGoodsRequest : public GameSparks::Core::GSTypedRequest < WindowsBuyGoodsRequest, GameSparks::Api::Responses::BuyVirtualGoodResponse >
			{
			public:
				WindowsBuyGoodsRequest()
					: GSTypedRequest(".WindowsBuyGoodsRequest")
				{

				}
			


			/// <summary>
			/// TODO
			/// </summary>
			WindowsBuyGoodsRequest& SetCurrencyCode( const gsstl::string& currencyCode )
			{
				m_Request.AddString("currencyCode", currencyCode);
				return *this;
			}
			/// <summary>
			/// Allows you to specify the platform
			/// </summary>
			WindowsBuyGoodsRequest& SetPlatform( const gsstl::string& platform )
			{
				m_Request.AddString("platform", platform);
				return *this;
			}
			/// <summary>
			/// The xml reciept returned from the windows phone 8 store
			/// </summary>
			WindowsBuyGoodsRequest& SetReceipt( const gsstl::string& receipt )
			{
				m_Request.AddString("receipt", receipt);
				return *this;
			}
			/// <summary>
			/// TODO
			/// </summary>
			WindowsBuyGoodsRequest& SetSubUnitPrice( long subUnitPrice )
			{
				m_Request.AddNumber("subUnitPrice", subUnitPrice);
				return *this;
			}
			/// <summary>
			/// If set to true, the transactionId from this reciept will not be globally valdidated, this will mean replays between players are possible.
			/// It will only validate the transactionId has not been used by this player before.
			/// </summary>
			WindowsBuyGoodsRequest& SetUniqueTransactionByPlayer( bool uniqueTransactionByPlayer )
			{
				m_Request.AddBoolean("uniqueTransactionByPlayer", uniqueTransactionByPlayer);
				return *this;
			}
			};
			
			class WithdrawChallengeRequest : public GameSparks::Core::GSTypedRequest < WithdrawChallengeRequest, GameSparks::Api::Responses::WithdrawChallengeResponse >
			{
			public:
				WithdrawChallengeRequest()
					: GSTypedRequest(".WithdrawChallengeRequest")
				{

				}
			


			/// <summary>
			/// The ID of the challenge
			/// </summary>
			WithdrawChallengeRequest& SetChallengeInstanceId( const gsstl::string& challengeInstanceId )
			{
				m_Request.AddString("challengeInstanceId", challengeInstanceId);
				return *this;
			}
			/// <summary>
			/// An optional message to send with the challenge
			/// </summary>
			WithdrawChallengeRequest& SetMessage( const gsstl::string& message )
			{
				m_Request.AddString("message", message);
				return *this;
			}
			};
			
		}
	}
}




