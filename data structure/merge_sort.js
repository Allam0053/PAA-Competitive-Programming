
function merge(arr, l, m, r) {
  var size_l = m - l + 1;
  var size_r = r - m;
  var left = new Array(size_l);
  
  var right = new Array(size_r);

  // create temp
  for (var i = 0; i < size_l; i++) {
    left[i] = arr[l + i];
  }
  for (var i = 0; i < size_r; i++) {
    right[i] = arr[m + i + 1];
  }

  // start merging
  var it_l = 0, it_r = 0, it_tot = l;
  while (it_l < size_l && it_r < size_r) {
    if (left[it_l] <= right[it_r]) {
      arr[it_tot] = left[it_l];
      it_l++;
    } else {
      arr[it_tot] = right[it_r];
      it_r++;
    }
    it_tot++;
  }

  // merge the remaining
  while (it_l < size_l) {
    arr[it_tot] = left[it_l];
    it_tot++;
    it_l++;
  }

  while (it_r < size_r) {
    arr[it_tot] = right[it_r];
    it_tot++;
    it_r++;
  }

  return;
}

function mergeSort(arr, l, r) {
  if (l >= r) return;
  var m = l + parseInt((r - l) / 2);
  mergeSort(arr, l, m);
  mergeSort(arr, m+1, r);

  merge(arr, l, m, r);

}

var arr = [ 12, 11, 13, 5, 6, 7 ];
var arr_size = arr.length;
document.getElementById("awal").innerHTML = arr;
console.log(arr);

mergeSort(arr, 0, arr_size - 1);
console.log(arr);

document.getElementById("akhir").innerHTML = arr;
