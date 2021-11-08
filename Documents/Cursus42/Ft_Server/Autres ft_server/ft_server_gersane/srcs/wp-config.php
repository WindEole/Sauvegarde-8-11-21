<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** MySQL database username */
define( 'DB_USER', 'gersane' );

/** MySQL database password */
define( 'DB_PASSWORD', 'password' );

/** MySQL hostname */
define( 'DB_HOST', 'localhost' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8mb4' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         '1;J`(MoO<LqRd(:!vi+r|+{+)%=i^P+8#4A:w7){f`:+29qukx&Xg]|g1Sd;+eC ');
define('SECURE_AUTH_KEY',  '([?=`oi{=I+/1N6^_~!X],@U_zr(-HLy?j(x*)f.@=g_VR)Q1cP>Bv5&zC@r+Rag');
define('LOGGED_IN_KEY',    '0k,R-:-A>?,3[:Y= I.^{oYFO6X#b:R?-19V+RgJHJKCSx*++sL<t+|YOO*&UrK%');
define('NONCE_KEY',        'vNgWo{sOnp}g{;MmCdt]J)iQpoxK*p0C}M`.zp]>}6|?0R?QM =n*lv.S{vL3%,@');
define('AUTH_SALT',        'fLk_izd=I]I6t3YBFBz}G3q^.[dTP*qMc>;p)S6+ZPp+|daZtywJssikB~MD|3}r');
define('SECURE_AUTH_SALT', 'ax]y@mRaI*CUxO&7$-$b6Y^utMtFoP9IfB]iL^%ne#UwzcCF.[cUm-vn4kN>Y.oA');
define('LOGGED_IN_SALT',   'aM/:>(k}|Hed,PEW*uAg-zuW)Yi#My+Am=PulgNG^@#N-.bxokKr;Wfuxb`K|_kj');
define('NONCE_SALT',       '|(y;N}9[!KSR*%d/);WM+1~-=d grVRl#%uf=7U%_C-zO}J);u W>;eR$mK{?{F(');

/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
