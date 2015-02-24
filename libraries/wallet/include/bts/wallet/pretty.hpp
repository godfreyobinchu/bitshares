/*
 * This file contains structs to populate for JSON representation of transactions/operations
 * for wallets and block explorers and such
 */

#pragma once

namespace bts { namespace wallet {

using namespace bts::blockchain;

struct public_key_summary
{
    string    hex;
    string    native_pubkey;
    string    native_address;
    string    pts_normal_address;
    string    pts_compressed_address;
    string    btc_normal_address;
    string    btc_compressed_address;

};

struct vote_summary
{
    bool      up_to_date_with_recommendation;  // Are my votes all voting for the result of "vote_recommended" ?
    float     utilization;
    float     negative_utilization;
};

struct pretty_ledger_entry
{
   string                                   from_account;
   string                                   to_account;
   asset                                    amount;
   string                                   memo;
   map<string, map<asset_id_type, asset>>   running_balances;
};

struct pretty_transaction
{
    bool                        is_virtual = false;
    bool                        is_confirmed = false;
    bool                        is_market = false;
    bool                        is_market_cancel = false;
    transaction_id_type         trx_id;
    uint32_t                    block_num = 0;
    vector<pretty_ledger_entry> ledger_entries;
    asset                       fee;
    fc::time_point_sec          timestamp;
    fc::time_point_sec          expiration_timestamp;
    optional<fc::exception>     error;
};

struct pretty_vesting_balance
{
    balance_id_type     balance_id;
    optional<string>    sharedrop_address;

    time_point_sec      start_time;
    uint32_t            duration = 0;

    asset_id_type       asset_id;
    share_type          original_balance;
    share_type          vested_balance;
    share_type          claimed_balance;
    share_type          available_balance;
};

}} // bts::wallet

FC_REFLECT( bts::wallet::public_key_summary, (hex)(native_pubkey)(native_address)(pts_normal_address)(pts_compressed_address)(btc_normal_address)(btc_compressed_address) );

FC_REFLECT( bts::wallet::vote_summary, (utilization)(negative_utilization)(up_to_date_with_recommendation) );

FC_REFLECT( bts::wallet::pretty_ledger_entry,
            (from_account)
            (to_account)
            (amount)
            (memo)
            (running_balances)
            );
FC_REFLECT( bts::wallet::pretty_transaction,
            (is_virtual)
            (is_confirmed)
            (is_market)
            (is_market_cancel)
            (trx_id)
            (block_num)
            (ledger_entries)
            (fee)
            (timestamp)
            (expiration_timestamp)
            (error)
            );
FC_REFLECT( bts::wallet::pretty_vesting_balance,
        (balance_id)
        (sharedrop_address)
        (start_time)
        (duration)
        (asset_id)
        (original_balance)
        (vested_balance)
        (claimed_balance)
        (available_balance)
        );
