class Solution {
    public int[] frequencySort(int[] nums) {
        Map<Integer, Integer> hsh = new HashMap<>();
        for (int num : nums) {
            hsh.put(num, hsh.getOrDefault(num, 0) + 1);
        }
        List<Map.Entry<Integer, Integer>> list = new ArrayList<>(hsh.entrySet());
        list.sort((a, b) -> a.getValue().equals(b.getValue()) ? b.getKey() - a.getKey() : a.getValue() - b.getValue());
        int[] result = new int[nums.length];
        int index = 0;
        for (Map.Entry<Integer, Integer> entry : list) {
            Arrays.fill(result, index, index + entry.getValue(), entry.getKey());
            index += entry.getValue();
        }
        return result;
    }
}