NSAFlood
--------

This directory contains the 0.1 release of RPGen.

About
-----

RPGen is a random password generator, supporting random character mode and 
dictionary mode. RPGen uses kernel devices as sources of entropy.

Installation
------------

To install RPGen, you must call make as root.

Usage
-----

	rpgen -m dictionary -l 5

See the man page for documentation.

Note: The dictionary that comes in this repository is small, and is intended 
only for demonstration and testing.

Licensing
---------

This program is subject to the terms of the GNU General Public License v3, the 
text of which is contained within the file COPYING.

Verifying
---------

To verify the integrity of the archive contents, you need to check the signature
 of the MD5SUMS file, then compare the individual file sums, like follows:

	gpg --verify MD5SUMS.sig MD5SUMS
	sha256sum file

If you do not have the public key needed to verify the MD5SUMS signature, 
download it as so:

	gpg --keyserver pgp.mit.edu --recv-key 0x107d24614a65e591
