#import <rootless.h>

static const int APPS_SEARCH_INITIAL_LIMIT = 12;

#ifdef THEOS_PACKAGE_SCHEME_rootless
    /** ROOTLESS CONSTANTS **/
    static NSString *const kLaunchPathBash = @"/var/jb/usr/bin/zsh";
    static NSString *const kLaunchPathUnzip = @"/var/jb/usr/bin/unzip";
    static NSString *const kLaunchPathPlutil = @"/var/jb/usr/bin/plutil";
    static NSString *const kLaunchPathLs = @"/var/jb/usr/bin/ls";
    static NSString *const kLaunchPathMv = @"/var/jb/usr/bin/mv";
    #define kIPARangerLatestDownloadLogPath "/var/jb/Library/IPARanger/downloadProgress.txt"
    static NSString *const kDownloadProgressFileOutput = @"/var/jb/Library/IPARanger/downloadProgress.txt";
    static NSString *const kIPARangerSettingsDict = @"/var/jb/User/Library/Preferences/com.0xkuj.iparangersettings.plist";
    static NSString *const kIPARangerDocumentsPath = @"/var/jb/Library/IPARanger/";
    static NSString *const kIPARangerCacheDirPath = @"/var/jb/Library/IPARanger/cacheDir/";
    static NSString *const kIPARangerCacheDirTempPath = @"/var/jb/Library/IPARanger/cacheDir/TEMP";
    static NSString *const kIPARangerAppsCacheDirPath = @"/var/jb/Library/IPARanger/cacheDir/AppCache.plist";
    static NSString *const kIpatoolScriptPath = @"/var/jb/Applications/IPARanger.app/ipatool/ipatool";
    static NSString *const kAppinstScriptPath = @"/var/jb/Applications/IPARanger.app/ipatool/appinst";
    static NSString *const kIPARangerVersion = @"IPA Ranger version: 2.2 (rootless)";
#else
    /** ROOTFUL CONSTANTS **/
    // default
    static NSString *const kLaunchPathBash = @"/usr/bin/zsh";
    // fallback
    static NSString *const kLaunchPathBashFallback = @"/bin/sh";
    static NSString *const kLaunchPathUnzip = @"/usr/bin/unzip";
    static NSString *const kLaunchPathPlutil = @"/usr/bin/plutil";
    static NSString *const kLaunchPathLs = @"/bin/ls";
    static NSString *const kLaunchPathMv = @"/bin/mv";
    static NSString *const kDownloadProgressFileOutput = @"/var/mobile/Documents/IPARanger/downloadProgress.txt";
    #define kIPARangerLatestDownloadLogPath "/var/mobile/Documents/IPARanger/downloadProgress.txt"
    static NSString *const kIPARangerSettingsDict = @"/var/mobile/Library/Preferences/com.0xkuj.iparangersettings.plist";
    static NSString *const kIPARangerDocumentsPath = @"/var/mobile/Documents/IPARanger/";
    static NSString *const kIPARangerCacheDirPath = @"/var/mobile/Documents/IPARanger/cacheDir/";
    static NSString *const kIPARangerCacheDirTempPath = @"/var/mobile/Documents/IPARanger/cacheDir/TEMP";
    static NSString *const kIPARangerAppsCacheDirPath = @"/var/mobile/Documents/IPARanger/cacheDir/AppCache.plist";
    static NSString *const kIpatoolScriptPath = @"/Applications/IPARanger.app/ipatool/ipatool";
    static NSString *const kAppinstScriptPath = @"/Applications/IPARanger.app/ipatool/appinst";
    static NSString *const kIPARangerVersion = @"IPA Ranger version: 2.2 (rootful)";
#endif

static NSString *const kIPARCountryChangedNotification = @"com.0xkuj.iparanger.countryChanged";
static NSString *const kstdOutput = @"standardOutput";
static NSString *const kerrorOutput = @"errorOutput";
static NSString *const kSha256verification = @"22b9b697f865d25a702561e47a4748ade2675de6e26ad3a9ca2a607e66b0144b";
static NSString *const kIPARangerCopyHeadline = @"IPARanger\nCopy Bundle";
static NSString *const kIPARangerErrorHeadline = @"IPARanger\nError";
static NSString *const kIPARangerWarningHeadline = @"IPARanger\nWarning";
static NSString *const kIPARangerDeleteFileHeadline = @"IPARanger\nDelete File";
static NSString *const kIPARangerDeleteFilesHeadline = @"IPARanger\nDelete Files";
static NSString *const kIPARangerRenameFileHeadline = @"IPARanger\nRename File";
static NSString *const kIPARangerLogouHeadline = @"IPARanger\nLogout";
static NSString *const kIPARangerDownloadPromptHeadline = @"IPARanger - Download";
static NSString *const kIPARangerSearchPromptHeadline = @"IPARanger - Search";
static NSString *const kIPARangerDownloadingMessage = @"IPARanger\nDownloading..";
static NSString *const kIPARangerSuccessMessage = @"IPARanger\nSuccess!";
static NSString *const kIPARangerInstallationHeadline = @"IPARanger\nInstallation\n";
static NSString *const kSearchCommandPathTermLimitCountry = @"%@ search '%@' --limit %ld --keychain-passphrase IPARanger --format json";
static NSString *const kLoginCommandPathAccountPassword = @"%@ auth login -e '%@' -p '%@' --keychain-passphrase IPARanger --non-interactive --format json";
static NSString *const kLoginCommandPathAccountPassword2FA = @"%@ auth login -e '%@' -p '%@' --auth-code '%@' --keychain-passphrase IPARanger --non-interactive --format json";
static NSString *const kDownloadCommandBundleOutputpathCountry = @"%@ download --bundle-identifier %@ -o %@ --purchase --keychain-passphrase IPARanger --format json >> %@";
static NSString *const kLogoutCommand = @"%@ auth revoke --keychain-passphrase IPARanger --format json";
static NSString *const kPredicateIPAApps = @"pathExtension == 'ipa'";
static NSString *const kFilenameIndex = @"filename";
static NSString *const kLoginTitle = @"Login";
static NSString *const kLogoutTitle = @"Logout";
static NSString *const kDateFormatter = @"MMM dd | HH:mm:ss";
static NSString *const kSizeIndex = @"size";
static NSString *const kAppBundleIndex = @"bundleID";
static NSString *const kAppnameIndex = @"name";
static NSString *const kAppVersionIndex = @"version";
static NSString *const kAppimageIndex = @"appimage";
static NSString *const kIPARCell = @"IPARAppCell";
static NSString *const kUnknownValue = @"N/A";
static NSString *const kFirstLaunchKey = @"FirstLaunch";
static NSString *const kFirstLaunchDoneKey = @"Done";
static NSString *const kUnknownSystemImage = @"questionmark.diamond.fill";
static NSString *const kShareSystemImage = @"square.and.arrow.up";
static NSString *const kDownloadSystemImage = @"square.and.arrow.down.on.square.fill"; 
static NSString *const kTabbarDownloadingSectionSystemImage = @"square.stack.3d.up";
static NSString *const kTabbarSearchingSectionSystemImage = @"magnifyingglass";
static NSString *const kPasswordEyeButtonOpen = @"eye.fill";
static NSString *const kPasswordEyeButtonClosed = @"eye.slash.fill";
static NSString *const kShowMoreButtonText = @"Show More Results";
static NSString *const kDefaultInitialCountry = @"US";
static NSString *const kCFBundleKeyPlist = @"CFBundleName";
static NSString *const kCFBundleIconsKeyPlist = @"CFBundleIcons";
static NSString *const kCFBundleIconFilesKeyPlist = @"CFBundleIconFiles";
static NSString *const kIconFile = @"icon.png";
static NSString *const kInfoFile = @"Info.plist";
static NSString *const kCFBundlePrimaryIconKeyPlist = @"CFBundlePrimaryIcon";
static NSString *const kCountryDownloadKeyFromFile = @"AccountCountryDownload";
static NSString *const kCountrySearchKeyFromFile = @"AccountCountrySearch";
static NSString *const kAccountEmailKeyFromFile = @"AccountEmail";
static NSString *const kAccountNameKeyFromFile = @"AccountName";
static NSString *const kAuthenticatedKeyFromFile = @"Authenticated";
static NSString *const kLastLoginDateKeyFromFile = @"lastLoginDate";
static NSString *const kLastLogoutDateKeyFromFile = @"lastLogoutDate";
static NSString *const kItunesImagesForBundleURL = @"https://itunes.apple.com/lookup?bundleId=%@";
static NSString *const kItunesImagesForBundleAnswerField = @"artworkUrl100";
static NSString *const kFilzaScheme = @"filza://";
static NSString *const kKeyForPlutil = @"-key";
static NSString *const kBashCommandKey = @"-c";
static NSString *const kKeyToExtractPlutilBundleId = @"CFBundleIdentifier";
static NSString *const kKeyToExtractPlutilBundleName = @"CFBundleDisplayName";
static NSString *const kCompositionFilter = @"overlayBlendMode";
static NSString *const kTwitterIcon = @"Twitter@2x.png";
static NSString *const kGithubIcon = @"GitHub@2x.png";
static NSString *const kPaypalIcon = @"donate@2x.png";
static NSString *const kPaypalLink = @"https://www.paypal.me/0xkuj";
static NSString *const kGithubRepoLink = @"https://github.com/0xkuj/IPARanger";
static NSString *const kTwitterLink = @"https://www.twitter.com/0xkuj";
static NSString *const kJsonLevel = @"level";
static NSString *const kJsonLevelError = @"error";
static NSString *const kJsonLevelInfo = @"info";
static NSString *const kJsonKeySuccess = @"success";
static NSString *const kJsonResponseContent = @"message";
static NSString *const kLogoutIcon = @"rectangle.portrait.and.arrow.right";
static NSString *const kPersonIcon = @"person.crop.circle";
static NSString *const kTrashIcon = @"trash";
static NSString *const kFolderIcon = @"folder";
static NSString *const kMenuIcon = @"ellipsis";
static NSString *const kAccountTitle = @"Account";
static NSString *const kSearchTitle = @"Search";
static NSString *const kDownloadTitle = @"Download";
static NSString *const kLastLoginDateKey = @"lastLoginDate";
static NSString *const kipaToolVersion = @"ipatool version: 2.1.6 (iOS)";