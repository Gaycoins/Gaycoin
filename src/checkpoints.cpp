// Copyright (c) 2009-2012 The Bitcoin developers
// Copyright (c) 2011-2012 Litecoin Developers
// Copyright (c) 2013 GayCoin Developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/foreach.hpp>

#include "checkpoints.h"

#include "main.h"
#include "uint256.h"

namespace Checkpoints
{
    typedef std::map<int, uint256> MapCheckpoints;

    //
    // What makes a good checkpoint block?
    // + Is surrounded by blocks with reasonable timestamps
    //   (no blocks before with a timestamp after, none after with
    //    timestamp before)
    // + Contains no strange transactions
    //

    static MapCheckpoints mapCheckpoints =
            boost::assign::map_list_of
        ( 0, uint256("0xc2524ed84fcd19900c5ea917502f30b32c16f5b275209dcb34aacdcf8b9140b0"))
        ( 111, uint256("0xd96ae07d1b4f4369e67710194a3d667cff51b7e5397cc4fe384bdb38e5f8efcc"))
        ( 222, uint256("0xff5465b29628bf6738205e813c0d6ee8ab408d8191c168ac1b7b80789dd30581"))
        ( 333, uint256("0x85dbff70627fef1f09942a10f65196b5816254d66a51c81a421c8980ba78a3e5"))
        ( 444, uint256("0xd58f711eef6bfb2906d4d8c3b8db944953fb45ba5d77e9f2be382e133d9f8e97"))
        ( 555, uint256("0xa4f3efeb7c0d299016911bfe019866867f11b216824b6b9552210ac80aeb594b"))
        ( 666, uint256("0x168a07cc86eb6444e24ec9adf0dea32896462142e9b0d85dc5a78496c043472a"))
        ( 777, uint256("0x8c5af7d45b419f4d98e57f61712d9cc19561ce2ca7c30d9d65a161a12e734cf9"))
        ( 888, uint256("0xc811ce2e95d4f27f89b56d44e069ad2ef300ac5f39f52ee5fb6a5a8075531c83"))
        ( 999, uint256("0x679ac4f3c5b0ef4ae430df448b0a0cdde798fc284acbd21d6d273d75477dff71"))
        ( 1111, uint256("0xf7b5afe1cfdc36ea1f3772e58b25edc6785a48b9d4c47a6de23d8262585cbb62"))
        ( 2222, uint256("0x7be5f19a388ae74db6642839435c5f05134b772fc9e0a07af7dcff05a6ce3ecf"))
        ( 3333, uint256("0x99bd528c72ea4046979d0e0aab522382b82e4730e6d0ce5c04ba6cf17220fb35"))
        ( 4444, uint256("0x09849dd472c246b59af64ddb845f3ce7063c2f91e5abfbba41e22fb2f2add190"))
        ( 5555, uint256("0x763e4cede399c6d25566fa4c41990994657e343c0e870c89e67e8d882b03cfa5"))
        ( 6666, uint256("0xe041373ca2fc9c52ae813ea9fff866c5786b5d86faba04d2307f4fe0c161374a"))
        ( 11111, uint256("0x8021da1033ea20570eb851bbd046d2d769808c954f9cef4871048853b329f2b7"))
	( 22222, uint256("0x4c6f8e592c442b40deb1ffc826754f6cfd293aa4c3a9605c2a6d52a23cc800df"))
	( 33333, uint256("0xf0e6f1621f453d4a1381e99eb9ea39857c934d5565d342aaad557b0b5e83b65b"))
	( 44444, uint256("0xaafa3330ab354c6fd4b6f907a0ab9f0d32d488a1e7144427263618e62c7d1594"))
	( 55555, uint256("0xd3224187d1d7da4c1c9884d4c9c28373ca16b2213b6503dc8db72ec18bb72586"))
	( 66666, uint256("0x25356865d43c0f1bb35ecc39d4241f6a55628b062faeddaef0886e2226014a05"))
	( 77777, uint256("0x334085e323bd8ed4f7843d91857504f87984c5c6599900ac51bb25d428604b2d"))
	( 88888, uint256("0x6a058ae9b55602dddd290d0fe76db69bcc9398ea564c0e79c918611497f48ec2"))
	( 99999, uint256("0x21a452325766e0e04e9721b0f01bad755598d33d933a718ddbad6fefb51e37a7"))
		;


    bool CheckBlock(int nHeight, const uint256& hash)
    {
        if (fTestNet) return true; // Testnet has no checkpoints

        MapCheckpoints::const_iterator i = mapCheckpoints.find(nHeight);
        if (i == mapCheckpoints.end()) return true;
        return hash == i->second;
		// return true;
    }

    int GetTotalBlocksEstimate()
    {
        if (fTestNet) return 0;
	
        return mapCheckpoints.rbegin()->first;
		// return 0;
    }

    CBlockIndex* GetLastCheckpoint(const std::map<uint256, CBlockIndex*>& mapBlockIndex)
    {
        if (fTestNet) return NULL;

        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, mapCheckpoints)
        {
            const uint256& hash = i.second;
            std::map<uint256, CBlockIndex*>::const_iterator t = mapBlockIndex.find(hash);
            if (t != mapBlockIndex.end())
                return t->second;
				// return NULL;
        }
        return NULL;
    }
}
