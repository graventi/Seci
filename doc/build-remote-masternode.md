## REMOTE SECINODE BUILD NOTES

#### System requirements

##### Remote:
An Ubuntu 16.04 64bit server is recommended with at least 768MB of memory and 10GB space available when running a SeciNode. Note that you may need to enable a swap file/virtual memory to complete the SECI build on the remote machine. Example: A server w/ 1GB of memory will likely need an additional 1GB SWAP file to complete the build.

We also recommend hardening your server, which includes using a non-root user for most tasks (requires creating a new user, adding them to sudo group, and running `sudo` before most commands). This is a good guide for Ubuntu from DigitalOcean. Your mileage/usage of this guide may vary depending on the flavor of linux, etc, you choose. We are unable to assist with most issues related to your server's security and offer this only as a recommended starting point: https://www.digitalocean.com/community/questions/best-practices-for-hardening-new-sever-in-2017

##### Local:
Windows 7 64 bit or newer, or Ubuntu 16.04 64bit Desktop.
At least 2048MB of memory and 10GB space available for chain data.

________________________________________________________________________________

#### Local Machine

Note that the following steps can be performed via command line using the *seci-cli*
instead of using the SECI Qt wallet.

1.  Download latest version of SECI Qt client for windows or linux

        https://github.com/Seci-Coin/Seci/releases

2.  Create seci.conf file with the following contents:

```
rpcallowip=127.0.0.1
rpcuser=YourUserName
rpcpassword=YourRPCPassword
server=1
daemon=1
listen=1
```

    Place the configuration file in its correct location:

    For Linux: ${HOME}/.seci/seci.conf
    For Windows: %appdata%\seci.conf

3.  Start SECI Qt gui client and allow the chain to sync

4.  Go to Help --> Debug Window --> Console and enter: `getaccountaddress 0` (where `0` is a label for the address)
    Copy the generated address to a text file.

5.  In the console enter: `masternode genkey`
    Copy the generated private key to a text file.

5.  Send exactly 30,000 SECI in a single transaction to the address generated from Step 4

6.  After you have received the SECI from Step 5, go to Help --> Debug Window --> Console and enter: `masternode outputs`
    
    You should see output similar to below indicating that the node has recognised coins as eligible to be used
    as collateral for a Masternode.

```
{
  "d565175089b0f4dce2294dc003799ae0c9cb703cadd996a0a4224458f176eb6e": "0"
}
```

7.  Shutdown the SECI Qt wallet

8.  Modify the seci.conf and add the lines noted here:

```
rpcallowip=127.0.0.1
rpcuser=YourUserName
rpcpassword=YourRPCPassword
server=1
daemon=1
listen=1
# **** add the following new lines ****
maxconnections=256
masternode=1
masternodeprivkey=<your_private_key_generated_in_step_5>
externalip=<external_ip_of_your_remote_node>:9819
promode=1
```

#### Remote Machine

1.  Build the latest SECI code

    Instructions here: https://github.com/Seci-Coin/Seci#building-on-ubuntu--debian
        
2.  Create seci.conf file with the following contents in `${HOME}/.seci/`:

```
rpcallowip=127.0.0.1
rpcuser=YourUserName
rpcpassword=YourRPCPassword
server=1
daemon=1
listen=1
maxconnections=256
promode=1
```    

3.  Create a masternode.conf file in the same directory as your wallet.dat (should be `${HOME}/.seci/`).The masternode.conf
    format consists of a space seperated text file. Each line consisting of an alias, ip address
    followed by port, masternode private key, collateral output transaction id and collateral
    output index.

```
alias 127.0.0.1:9819 masternode_private_key collateral_output_txid collateral_output_index

e.g.

mn01 127.0.0.1:9819 92bHZcSpmT6UinHzR8VgaVZVgBVfbDRCh1WogXXXXXXtf9pyZ4Y d565175089b0f4dce2294dc003799ae0c9cb703cadd996a0a4224458f176eb6e 0
```

4.  Start SECI daemon by navigating to `cd seci/src` (not `.seci`) and using command `./secid` (or `sudo ./secid`). This will start your SECI daemon for the first time. It will begin syncing (this can take some time). You can navigate back to `/seci/src` and run `./seci-cli getinfo` to confirm the block height. Once it is sync'd, move on.

#### Local Machine

Note: Your local wallet must remain online and sync'd to receive SeciNode rewards. Suggest keeping it on a stable/secure rig, separate VPS, or local PC with battery backup.

1.  Back on your local machine; start the SECI Qt client

2.  Go to Help --> Debug Window --> Console and enter: `masternode start`

    Note: If you have a password on your wallet, you'll need to first run `walletpassphrase YOURPASSWORD 100`, then `masternode start`

    You should get the following message:

```
successfully started masternode
```

3.  If you then enter: `masternodelist`
    You should be able to locate the externalip of your remote node from the output list of masternodes.

    **Congratulations your masternode is up and running!**

    Alternatively, on the SECI Qt client Masternodes tab --> All Masternodes you should see your
    remote node ip address listed with its public key and other data
