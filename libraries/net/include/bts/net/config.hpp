#pragma once

#define BTS_NET_PROTOCOL_VERSION                        106

/**
 * Define this to enable debugging code in the p2p network interface.
 * This is code that would never be executed in normal operation, but is
 * used for automated testing (creating artificial net splits,
 * tracking where messages came from and when)
 */
#define ENABLE_P2P_DEBUGGING_API                        1

/**
 * 512 kb
 */
#define MAX_MESSAGE_SIZE                                (512 * 1024)
#define BTS_NET_DEFAULT_PEER_CONNECTION_RETRY_TIME      30 // seconds

/**
 * AFter trying all peers, how long to wait before we check to
 * see if there are peers we can try again.
 */
#define BTS_PEER_DATABASE_RETRY_DELAY                   15 // seconds

#define BTS_NET_PEER_HANDSHAKE_INACTIVITY_TIMEOUT       5

#define BTS_NET_PEER_DISCONNECT_TIMEOUT                 20

<<<<<<< HEAD
#define BTS_NET_TEST_SEED_IP                            "54.68.193.243"		//"104.236.44.210" // autogenerated
#define BTS_NET_TEST_P2P_PORT                           BTS_NET_DEFAULT_P2P_PORT - BTS_TEST_NETWORK_VERSION		// 150208 Slender
#define BTS_NET_DEFAULT_P2P_PORT                        2810		// Remitabit
#define BTS_NET_DEFAULT_DESIRED_CONNECTIONS             5		// 150208 Slender
#define BTS_NET_DELEGATE_DESIRED_CONNECTIONS            5		// 150208 Slender
=======
#define BTS_NET_TEST_SEED_IP                            "104.236.44.210" // autogenerated
#define BTS_NET_TEST_P2P_PORT                           1700
#define BTS_NET_DEFAULT_P2P_PORT                        1776
#define BTS_NET_DEFAULT_DESIRED_CONNECTIONS             20
#define BTS_NET_DELEGATE_DESIRED_CONNECTIONS            50
>>>>>>> upstream/master
#define BTS_NET_DEFAULT_MAX_CONNECTIONS                 200

#define BTS_NET_MAXIMUM_QUEUED_MESSAGES_IN_BYTES        (1024 * 1024)

/**
 * We prevent a peer from offering us a list of blocks which, if we fetched them
 * all, would result in a blockchain that extended into the future.
 * This parameter gives us some wiggle room, allowing a peer to give us blocks
 * that would put our blockchain up to an hour in the future, just in case
 * our clock is a bit off.
 */
#define BTS_NET_FUTURE_SYNC_BLOCKS_GRACE_PERIOD_SEC     (60 * 60)

#define BTS_NET_INSUFFICIENT_RELAY_FEE_PENALTY_SEC      15

#define BTS_NET_MAX_INVENTORY_SIZE_IN_MINUTES           2

#define BTS_NET_MAX_BLOCKS_PER_PEER_DURING_SYNCING      100

/**
 * Instead of fetching all item IDs from a peer, then fetching all blocks
 * from a peer, we will interleave them.  Fetch at least this many block IDs,
 * then switch into block-fetching mode until the number of blocks we know about
 * but haven't yet fetched drops below this
 */
#define BTS_NET_MIN_BLOCK_IDS_TO_PREFETCH               10000
