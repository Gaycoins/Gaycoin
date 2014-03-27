# Gaycoin [GAY, Ǥ]
http://www.gaycoin.eu/

## What is GayCoin?
Gaycoin is like Bitcoin, but based on Litecoin, and also much more wow.
http://www.gaycoin.eu

## License
GayCoin is released under the terms of the MIT license. See [COPYING](COPYING)
for more information or see http://opensource.org/licenses/MIT.

## Development and contributions
Developers work in their own trees, then submit pull requests when they think
their feature or bug fix is ready.

## Total GAY coins

The total number of GAY coins will be 777,777,777 GAY coins which is about 11% (LGBT percentage of population) of the world population.

## Block Time

60 Seconds

## Difficulty Retarget Time

4 hours

## Mining

You don’t need expensive mining equipment that uses lots of electricity. Just download your wallet and start mining using your computers CPU processing power.

## Rewards

Block 1-200,000 : 0-99 GAY Reward
Block 200,001 -300,000 : 0-88 GAY Reward
Block 300,001 -400,000 : 0-77 GAY Reward
Block 400,001 -500,000 : 0-66 GAY Reward
Block 500,001 -500,000 : 0-55 GAY Reward
Block 600,001 -700,000 : 0-44 GAY Reward
Block 700,001 -800,000 : 0-33 GAY Reward
Block 800,001+ : 22 GAY Reward

## Make gaycoind

    sudo apt-get install build-essential \
                         libssl-dev \
                         libdb5.1++-dev \
                         libboost-all-dev \
                         libqrencode-dev \
                         libminiupnpc-dev

    cd src/
    make -f makefile.unix USE_UPNP=1 USE_IPV6=1 USE_QRCODE=1

## Ports
RPC 22666
P2P 22667
