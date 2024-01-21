const CLIENT_ID="{{ env['CLIENT_ID'] }}";
const CLIENT_SECRET="{{ env['CLIENT_SECRET'] }}";
const GCS_URL = "{{ env['GCS_URL'] }}";
const REDIRECT_URI = `https://script.google.com/macros/d/${ScriptApp.getScriptId()}/usercallback`;

function getOAuthService() {
    return OAuth2.createService('gcs')
        .setAuthorizationBaseUrl('https://accounts.google.com/o/oauth2/auth')
        .setTokenUrl('https://accounts.google.com/o/oauth2/token')
        .setClientId(CLIENT_ID)
        .setClientSecret(CLIENT_SECRET)
        .setCallbackFunction('authCallback')
        .setPropertyStore(PropertiesService.getUserProperties())
        .setScope('https://www.googleapis.com/auth/devstorage.read_only')
        .setParam('access_type', 'offline');
}

function authCallback(request) {
    const service = getOAuthService();
    const authorized = service.handleCallback(request);
    return HtmlService.createHtmlOutput('' + authorized);
}

function auth() {
    const service = getOAuthService();
    if(!service.hasAccess()) {
      console.log(`Redirect URI: ${REDIRECT_URI}`);
      console.log(`OAuth Client Config: https://console.cloud.google.com/apis/credentials/oauthclient/${CLIENT_ID}`);
      console.log(service.getAuthorizationUrl());
    }
}

function myFunction() {
    const service = getOAuthService();
    if (!service.hasAccess()) throw new Exception('service has no access');

    const m = /^gs:\/\/(.*?)\/(.*)$/.exec(GCS_URL);
    const bucketName = m[1];
    const objectName = m[2];
    const url = 'https://storage.googleapis.com/storage/v1/b/' + bucketName + '/o/' + encodeURIComponent(objectName);

    const headers = {
        'Authorization': `Bearer ${service.getAccessToken()}`,
    };
    const muteHttpExceptions = true;

    const res = UrlFetchApp.fetch(url, {headers, muteHttpExceptions});
    console.log(res.getResponseCode());
    console.log(JSON.parse(res.getContentText())['kind']);
}