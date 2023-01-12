/**
 *
    We are interested in building an app integrated with the twitter API
    that ingests the public tweet stream and provides some word statistics.
    We’ll start with a prototype design 
        - something that would be suitable for running locally/testing/proof of concept
        - and then discuss different aspects of the app that we might need to revisit/rework to take it from prototype to production.

    Our app has two external methods 
      - the first, `onTweet`, is a callback that we assume we can register with Twitter
          so that whenever a new tweet is sent, this method is called with that tweet’s id.
      - the second, `getWordCount`, is called by our app’s users with a single argument (the word they want to query) 
          and should return the number of times that word has been seen so far (across all tweets we’ve consumed).

    You can use a public facing REST API endpoint that Twitter provides to get tweet details (including text contents of the tweet) given a Tweet ID.
    First, let’s start by writing out the prototype implementation (pseudocode is fine)
      - something that would be suitable for running locally on a moderate volume of tweets.

    Sample corpus:
    Tweet 1 - “setting up my twitter”
    Tweet 2 - “I just set up my Twitter. hello world!”
    Tweet 3 - “Hello! My twitter rocks”    
        getWordCount(“twitter”) -> 3
        getWordCount(“rocks”) -> 1
*/

class TweetWordStatsCounter {

    /**
      *  registers with twitter
      *  listen to tweets from a specific group of users
      *  1. extract references of celebrities
      *  2. 
      *  3. 
      *  1 million english words , 10 characters , 20 bytes per word
      *   => 20,000,000 bytes => 20 MB
      *  50 million key-value
      *  50 million words
      *  50 * 20 MB = 1000 MB 
      *      Redis => 100 MB per shard => 10 redis servers
      *       Memcache or any in-memory in a centralized server
      *  file-based => 
      *      cache => MRU
      *      if names are sorted in the file
      *      for all cache misses it maintains a offset for alpha range

      * THROUGHPUT :
      *    1 million requests per day / per hour   
      */
    void onTweet(long tweetId) { 
        // Callback fired when tweets are created 
        // String tweet = Twitter.get(tweetId);
        String[] words = extract_names_references("");
        for (String s : words) {
            // RedisCache.set(word, count + 1) 
            // 
        } 
    }

        
    // 1. Counter 
    //     GlobalCounter.write(word) => map reduce => counts on a time scale
    // 2. Log approach - Write to elastic search type log
    //        pros : simplest 
    //        Logger.write(words)
    String[] extract_names_references(String tweet) {
        // extract words
       String[] words = new String[100];
       for (String word : tweet.split("")) {
            //if(!common_verb(word)) {
            //   words.add(word)
            //}
       }
       return words;
    }

    /**
     *  internal utility function 
     */
    int getWordCount(String word) {
        int count = 0;
        // Return the number of appearances of that word since we 
        // started
        // 1. From the counter datasource
        // 
        //return Cache.read(word)
        //count = Counter.read(word, start, end)
        return count;
    }
}
